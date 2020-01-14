
#define ALRMSOL     0x80  // se pone a 1 si y solo si hay sol
#define ALRMRAMERR  0x40  // detector bitflip
#define ALRMDIV0    0x04
#define ALRMROMERR  0x02
#define ALRME2PERR  0x01

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define u8  unsigned char
#define u16 unsigned short
#define s16   signed short
#define u32 unsigned long
#define s32   signed long

#ifdef LINUX
#define __int16 s16
#define __int32 s32
#endif

#define SYNC   0x33
#define DATA   0x01

struct _tlm
	{
	void *p;
	u8 bitpkt;
	u8 bitvar;
	u8 attr;
	};

struct _tlm2 //descripcion consola
	{
	void *p;
	char s1[20];
	char s2[6];
	char s3[80];
	};

s32 lclock;

#define BITFLIP 100
u8 bitflip[BITFLIP];

#define ADCN 32
u16 adc  [ADCN];
u32 adcpp[ADCN];
u32 adcpn[ADCN];


u16 pktm[5]={0,0,0,0,0};

#define STATSN 26
struct _stats
    {
    u32 pp;
    u32 pn;
    u32 ac;
    } stats[STATSN];


// implementar en proxima mision
#define SENSORN 4
struct _sensor 
	{
	u16 sid;
	u16 v[16];
	} sen[SENSORN];


#include "tlm2.h"

//!!completar
//limitacion, solo variables 16b
const u16* statsv[STATSN]={

&ttx,
&trx,
&tba,
&txp,
&txn,
&typ,
&tyn,
&tzp,
&tzn,

&ixp,
&ixn,
&iyp,
&iyn,
&izp,
&izn,  //corrientes 9-14 (para acumular, uso resultado lut)

&vbat,
&vbus,
&vcpu,
&adc[3],  //tensiones 15-18

&ix,
&iy,
&iz,
&isolar,
&ibus,
&ibatp,
&ibatn //revisar
};

//               0     1     2     3     4
const u8 pktb[]={PKT0B,PKT1B,PKT2B,PKT3B,PKT4B};
const u8 pkte[]={PKT0E,PKT1E,PKT2E,PKT3E,PKT4E};

