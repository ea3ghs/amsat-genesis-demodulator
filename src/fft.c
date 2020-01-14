//20200102 integro en tlm19
//20190325 FFT.C

///////////////////////////////////////////////////

#define bool u8
#define false 0
#define true !false

static size_t reverse_bits(size_t x, int n) 
{
size_t result = 0;
for(int i=0;i<n;i++,x>>=1)result=(result<<1)|(x&1U);
return result;
}


double* cos_table;
double* sin_table;
bool Fft_transformRadix2(double real[], double imag[], size_t n) 
{
// Length variables
bool status = false;
int levels = 0;  // Compute levels = floor(log2(n))
for (size_t temp = n; temp > 1U; temp >>= 1)	levels++;
if ((size_t)1U << levels != n)	return false;  // n is not a power of 2

// Trignometric tables
if (__SIZE_MAX__ / sizeof(double) < n / 2)	return false;
//!!evitar el calculo de las tablas en cada llamada
size_t size = (n / 2) * sizeof(double);

cos_table=malloc(size);
sin_table=malloc(size);
if(cos_table==NULL||sin_table==NULL)goto cleanup;
for (size_t i = 0; i < n / 2; i++) {
	cos_table[i] = cos(2 * M_PI * i / n);
	sin_table[i] = sin(2 * M_PI * i / n);
	}

// Bit-reversed addressing permutation
for (size_t i = 0; i < n; i++) {
	size_t j = reverse_bits(i, levels);
	if (j > i) {
		double temp = real[i];
		real[i] = real[j];
		real[j] = temp;
		temp = imag[i];
		imag[i] = imag[j];
		imag[j] = temp;
	}
}

// Cooley-Tukey decimation-in-time radix-2 FFT
for (size_t size = 2; size <= n; size *= 2) {
	size_t halfsize = size / 2;
	size_t tablestep = n / size;
	for (size_t i = 0; i < n; i += size) {
		for (size_t j = i, k = 0; j < i + halfsize; j++, k += tablestep) {
			size_t l = j + halfsize;
			double tpre =  real[l] * cos_table[k] + imag[l] * sin_table[k];
			double tpim = -real[l] * sin_table[k] + imag[l] * cos_table[k];
			real[l] = real[j] - tpre;
			imag[l] = imag[j] - tpim;
			real[j] += tpre;
			imag[j] += tpim;
		}
	}
	if (size == n) break; // Prevent overflow in 'size *= 2'
		
}
status = true;

cleanup:
//!!
free(cos_table);cos_table=0;
free(sin_table);sin_table=0;
return status;
}



#define SAM 128
double re[SAM],im[SAM];
int ffti;
float ffta;
void fft()
{
int n=128;
for(int k=0;k!=n;k++){   
	re[k]=0; //zero padding
	im[k]=0;
	}
n=BLKN;
for(int k=0;k!=n;k++){   
	re[k]=(double)(p[k])/32768;
	im[k]=(double)(p[k])/32768;
	}
Fft_transformRadix2(re,im,128);

ffti=-1;
ffta=-1;

for(int n=0;n!=128/2;n++){
	double u;
	u=re[n]*re[n]+im[n]*im[n]; //operacion ^2, retorna potencia, luego 10log
	if(ffta<u){
		ffta=u;
		ffti=n;
		}
	}

ffta=10*log10(ffta)-20*log10(128);	
}

/*
///////////////////////////////////////////////////
#define SAM 4096*128
double re[SAM],im[SAM],fftb;
int ffta=0,ffti=0,fftn=0,fftj=0; //Amplitud Indice Nbloques4096 

void fft(int n,S16* p)
{
if(fftn==0)return;
if(fftn>128)fftn=128;
for(int k=0;k!=2*n;k+=2){   
	re[fftj]=(double)(p[k  ])/32768;
	im[fftj]=(double)(p[k+1])/32768;
	fftj++;
	}
fftn--;
if(fftn)return; 
printf("++ fft_adq_completa fftj:%d\n",fftj);
//continuo si tengo todos los bloques

FILE *ff;
ff=fopen("adc2.bin","w");
fwrite(re,sizeof(double),fftj,ff);
fwrite(im,sizeof(double),fftj,ff);
fclose(ff);	

printf("++ FFT_TRANSFORMRADIX2\n");
Fft_transformRadix2(re,im,fftj);

ff=fopen("fft.bin","w");
fwrite(re,sizeof(double),fftj,ff);
fwrite(im,sizeof(double),fftj,ff);
fclose(ff);	

ffti=-1;
fftb=-1;

for(int n=0;n!=fftj;n++){
	double u;
	u=re[n]*re[n]+im[n]*im[n]; //operacion ^2, retorna potencia, luego 10log
	if(fftb<u){
		fftb=u;
		ffti=n;
		}
	}

ffta=10*log10(fftb)-20*log10(fftj*fftj);	
printf("++ FFT <j:%d i:%d b:%5.2f a:%d>\n",fftj,ffti,fftb,ffta);
fftj=0;
fflush(stdin);
}
*/