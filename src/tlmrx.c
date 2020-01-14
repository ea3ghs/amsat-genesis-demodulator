// play -n -c1 synth 3000 sine 800
// calcular horas en sensor.c
// 2018xxyy
// 20191024 elimino tx
// 20191121 sensor.c
// 20200110 reproducir el pasado

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> 
#include <time.h>
#include "tlm1.h"
#include "sensor.c"
#include "crc.c"
#define BLKN 8000/100
#include "fir.c"

#define RR "rb"
//#define RR "r"

u8 flag=0;
float lvl; //u16 lvl;
short p[BLKN];

#include "fft.c"

u8 bit;
float peakp0,peakn0,peakp=0,peakn=0xffff,mid,alfa=0.02; //felix 0.005;  //0.02
void dsp()
{
lvl=0;
static FILE *f=0;
if(f==0){f=fopen("audio.wav",RR);if(f==0){printf("\n!! adc error\n");exit(1);}}
int n=fread(p,2,BLKN,f); if(n<1) {printf("\n!! adc empty, exiting...\n");exit(0);}
float ss=0,s;
for(u16 m=0;m!=BLKN;m++)
	{
	s=(float)fir(p[m]);
	s=s*s;
	ss+=s;
	}
ss/=BLKN;
lvl=sqrt(ss); 
// RMSDETECTOR+MEANDETECTOR+BITSLICER
mid+=alfa*(lvl-mid);
bit=(lvl>mid)?1:0;
//NIVELES PICO SEÑAL DEPUES DEL DETECTOR
peakp-=alfa*(peakp-lvl);
peakn+=alfa*(lvl-peakn);
peakp =MAX(peakp,lvl);
peakn =MIN(peakn,lvl);
//NIVELES PICO SEÑAL ANTES DEL DETECTOR, DURANTE UNA VENTANA DE 5s
{
static int n=0;
if(n==0)
	{
	peakp0=0;
	peakn0=0xffff;
	n=500;
	}
n--;
for(u16 m=0;m!=BLKN;m++)
	{
	peakp0=MAX(peakp0,(float)p[m]);
	peakn0=MIN(peakn0,(float)p[m]);
	}
}
}


//23170=(2^15-1)/sqrt(2)
void loglvl(void)
{
static u32 clock0=0;
if(lclock-clock0<5)return;
clock0=lclock;
float f1,f2,f3,f4,f5,r;

f1=-20*log10(32767)+20*log10((float)peakp0); 
f2=-20*log10(32767)+20*log10((float)lvl);    
f3=-20*log10(32767)+20*log10((float)peakn); 
f4=-20*log10(32767)+20*log10((float)mid);   
f5=-20*log10(32767)+20*log10((float)peakp); 

printf("p-+ %5.0f:%5.0f %4.1f dBFS",peakn0,peakp0,f1);
printf(" | RMS lvl %5.0f %4.1f dBFS ",lvl  ,f2);
printf(" | p-:mid:p+ %5.0f:%5.0f:%5.0f  %4.1f %4.1f %4.1f dBFS ",peakn,mid,peakp, f3,f4,f5);
//fft();
//r=ffti*8000.0/128.0;
//printf(" | FFT i:%3d %4d Hz %4.1f dB",ffti,(int)r,ffta);

FILE *fi=0;
static u32 clock1=0;
//cada 13horas inicializo fichero muestras
if(lclock-clock1<60*60*13)fi=fopen("rx.dat","a");else {clock1=lclock; fi=fopen("rx.dat","w");}
fprintf(fi,"%ld\t%4.1f\t%4.1f\t%4.1f\t%4.1f\t%4.1f\t%4.1f\t%d\t%d\n",lclock,f1,f2,f3,f4,f5,ffta,(int)r,ffti);
fclose(fi);

if(ffta>-40)
	{
	fi=fopen("fft.dat","a");
	fprintf(fi,"%ld\t%d\t%d\t%4.1f\n",lclock,(int)r,ffti,ffta);
	fclose(fi);
	printf("*");
	}
printf("\n");
}



u8 *x=0,ph0[PKTLEN],ph1[PKTLEN];
void dser(void)
{
int n;
for(n=0;n!=PKTLEN-1;n++){x[n]>>=1;if(x[n+1]&0x01)x[n]|=0x80;else x[n]&=0x7f;}
x[PKTLEN-1]>>=1;
if(bit)x[PKTLEN-1]|=0x80;else x[PKTLEN-1]&=0x7f;
}

void debugdem(void)
{
static int loop=0;
loop++;
FILE *fi=0;
fi=fopen("rx.dat" ,"a");
fprintf(fi,"%d\t%f\t%f\t%f\t%d\n",loop,lvl,peakp,peakn,bit*500);
fclose(fi);
FILE *fa=0;
fa=fopen("pkt.dat","a");
int n;
for(n=0;n!=36;n++){fprintf(fa,"%02x",ph0[n]);} fprintf(fa,"\t");
for(n=0;n!=36;n++){fprintf(fa,"%02x",ph1[n]);} fprintf(fa,"\n");
fclose(fa);
}


//a cada recepcion de un paquete valido, guardo el buffer entero y la hora
void savepkt(void)
{
FILE *fa=0;
if(fa==0)fa=fopen("out.pkt","a");
if(fa==0){printf("!! out.pkt error\n");exit(0);}
fwrite((void*)&lclock,1,sizeof(s32),fa);
fwrite((void*)x      ,1,PKTLEN     ,fa);
fclose(fa);
}


void loadpkt(void)
{
static FILE *fa=0;
if(fa==0)fa=fopen("in.pkt","r");
if(fa==0)return;
if(feof(fa))return;
fread((void*)&lclock,1,sizeof(s32),fa);
fread((void*)x      ,1,PKTLEN     ,fa);
}


void upkt(u8 type) 
{
u8 sync,len,address,seq,h;
u16 crc,crclocal;
u16 pos,pktlen;
u8 *q=0;
switch(type)
	{
	case 0: pktlen=PKT0LEN; pos=PKTLEN-PKT0LEN; q=&(x[pos]); break;
	case 1: pktlen=PKT1LEN; pos=PKTLEN-PKT1LEN; q=&(x[pos]); break;
	case 2: pktlen=PKT2LEN; pos=PKTLEN-PKT2LEN; q=&(x[pos]); break;
	case 3: pktlen=PKT3LEN; pos=PKTLEN-PKT3LEN; q=&(x[pos]); break;
	}

crc=q[pktlen-1];crc<<=8;crc&=0xff00;crc|=q[pktlen-2];
sync=q[0];
if(sync!=SYNC)return; //busco sync
crclocal=crc16(&q[1],pktlen-3);

int nn=MIN(3500,pktlen);
if(crc!=crclocal)return;

//if(type==3)
{printf("\nT%d LEN%02d CRC/RL %04x %04x ",type,pktlen,crc,crclocal);if(crc!=crclocal)printf("ERR ");printf(":: ");for(int n=0;n!=nn;n++)printf("%02x",q[n]);printf("\n");}

SelfSyncDeScrambler(&q[1],pktlen-3);
h=q[1];len    =h&0x03;
h>>=2 ;address=h&0x0f;
h>>=4 ;seq    =h&0x03;

printf("PH:%d SYNC TYPE:%02d LEN:%02d @:%02d SEQ:%02d\n",((x==ph0)?0:1),len,pktlen,address,seq);
//if(address!=0x00)return;//estacion 15
//verificar crc, si no cumple, retorno
u32 v,mask;
u8 ini,end,k;
flag=type; 
//cuento paquetes de cada tipo
pktn++;
pktm[type]++;
//introducir la hora
static u32 t=0;
t++;//!!mal tiene que ser el reloj remoto!!
ini=pktb[len];
end=pkte[len]+1;
for(k=ini+2;k!=end;k++)
	{
	int nvar,npkt;
	npkt=tlm[k].bitpkt;
	nvar=tlm[k].bitvar;
	if(tlm[k].attr&DATA)
		{
		mask=0;for(int m=0;m!=npkt;m++){mask<<=1;mask|=1;}	
		v=q[3]<<24|q[2]<<16|q[1]<<8|q[0];
		v&=mask;
		//VARIABLE RAW (si no es igual a la fisica)
		if(tlm2[k].p)
			{
			if(nvar<=8 ){u8  *p;p=tlm2[k].p;*p=(u8) v;} else
			if(nvar<=16){u16 *p;p=tlm2[k].p;*p=(u16)v;} else
			if(nvar<=32){u32 *p;p=tlm2[k].p;*p=(u32)v;}
			}
		//VARIABLE FISICA
		if(nvar<=8 ){u8  *p;p=tlm[k].p;*p=(u8) v;} else
		if(nvar<=16){u16 *p;p=tlm[k].p;*p=(u16)v;} else
		if(nvar<=32){u32 *p;p=tlm[k].p;*p=(u32)v;}
		}
	for(int m=0;m!=npkt;m++)dser();
	}
}

void txt(int type)
{
int ini,end,k,n;
s32 v,w,ww;
FILE *f1=0,*f2=0,*f3=0;
char s[128];
sprintf(s,"genesis%d.txt",type); f1=fopen(s,"w");
sprintf(s,    "raw%d.dat",type); f2=fopen(s,"a");
sprintf(s,    "phy%d.dat",type); f3=fopen(s,"a");
if(f1==0){printf("!! no puedo guardar en disco...");exit(1);}

struct tm *ptm=gmtime(&lclock); //http://zetcode.com/articles/cdatetime
fprintf(f1,"\n%04d/%02d/%02d %02d:%02d:%02d UTC\n\
==================================================================\n\
        VARIABLE |    RAW        VALUE      |  DESCRIPTION\n\
==================================================================\n",
//6          key |             0            | clave 
//7        value |             0            | valor 
//5       _free_ |             2            | sin asignar, tamanyo paquete multiplo 8 
1900+ptm->tm_year,ptm->tm_mon+1,ptm->tm_mday,ptm->tm_hour,ptm->tm_min, ptm->tm_sec);

fprintf(f2,"%10ld ",lclock);		
fprintf(f3,"%10ld ",lclock);		
	
ini=pktb[type];
end=pkte[type]+1;
for(k=ini;k!=end;k++)
	{
	//printf("%d\n",k);
	n =tlm[k].bitvar;
	if(tlm[k].attr&DATA)
		{

		//valor fisico
		if(n<=8 ){u8  *p;p=tlm[k].p;v=(u32)(*p);} else
		if(n<=16){u16 *p;p=tlm[k].p;v=(u32)(*p);} else
		if(n<=32){u32 *p;p=tlm[k].p;v=(u32)(*p);}

		//valor RAW
		char s[32];s[0]=0;
		if(tlm2[k].p) 
			{
			if(n<=8 ){u8  *p;p=tlm2[k].p;w=(u32)(*p);} else
			if(n<=16){u16 *p;p=tlm2[k].p;w=(u32)(*p);} else
			if(n<=32){u32 *p;p=tlm2[k].p;w=(u32)(*p);}
			sprintf(s ,"%6ld" ,w);
			fprintf(f2,"%6ld ",w);
			}

		ww=v;	
		//cambio de divisiones a unidades fisicas
		if(strncmp(tlm2[k].s2,"oC",2)==0){ww/=2;ww+=NTCMINT;} //1div=500mK
		if(strncmp(tlm2[k].s2,"uA",2)==0){ww*=20;} //1div=20uA
		fprintf(f1,"    %12s | %6s %12ld  %-4s| %s \n",
			tlm2[k].s1,
			s,ww,
			tlm2[k].s2,
			tlm2[k].s3);
		fprintf(f3,"%10ld ",ww);		
		}
	}

fprintf(f2,"\n");		
fprintf(f3,"\n");		
fclose(f1);
fclose(f2);
fclose(f3);
//susituir lo siguiente por algo hecho en c para terner portabilidad

//if(type<5){char z[128];sprintf(z,"cat genesis%d.txt",type);system(z);}
if(type<5){char z[128];sprintf(z,"type genesis%d.txt",type);system(z);}

}




int main(void)
{
lclock=time(NULL);
printf("tlmrx running... (%ld)\n",lclock);
sensor0();
loop:  //100veces por segundo
       {static u8 x=0;if(++x==100){x=0;lclock++;/*printf("!!CLOCK++ %ld\n",lclock);*/}}
       dsp();
       loglvl();
       if(x==ph0)x=ph1;else x=ph0; //anyade bit en pha o phb alternativamente
       dser();
       //comprobar si la siguiente linea funciona dejando el resto intacto
       //loadpkt(); //intenta reproducir el pasado ignorando lo recibido
       upkt(0);
       upkt(1);
       upkt(2);
       upkt(3);
       //debugdem(); //capturar ultimo paquete solo 
       if(flag)
       		{
       		savepkt();
       		sensor();
       		txt(flag);
       		txt(4);     //estadisticas locales
			for(int n=0;n!=PKTLEN-1;n++)ph0[n]=0; //borro buffer recepcion, evito duplicados
			for(int n=0;n!=PKTLEN-1;n++)ph1[n]=0; //pero...podria medir SNR en la otra fase
       		}
       sensoracc();
       flag=0;
goto loop;
return 0;
}

