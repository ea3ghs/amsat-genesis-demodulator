/**************************************************************
WinFilter version 0.8
http://www.winfilter.20m.com
akundert@hotmail.com

Filter type: Band Pass
Filter model: Chebyshev
Filter order: 4
Sampling Frequency: 8 KHz
Fc1 and Fc2 Frequencies: 0.400000 KHz and 2.400000 KHz
Pass band Ripple: 1.000000 dB
Coefficents Quantization: 16-bit

Z domain Zeros
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = -1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000
z = 1.000000 + j 0.000000

Z domain Poles
z = 0.154076 + j -0.658487
z = 0.154076 + j 0.658487
z = -0.272506 + j -0.856502
z = -0.272506 + j 0.856502
z = 0.724841 + j -0.390691
z = 0.724841 + j 0.390691
z = 0.918370 + j -0.299145
z = 0.918370 + j 0.299145
***************************************************************/
#define Ntap 63

#define DCgain 32768

__int16 fir(__int16 NewSample) {
    __int16 FIRCoef[Ntap] = { 
         -145,
         -188,
         -354,
         -350,
         -234,
         -325,
         -320,
          -16,
           39,
          -60,
          298,
          533,
          220,
          384,
          841,
          377,
          106,
          849,
          533,
         -501,
          253,
          588,
        -1353,
        -1554,
         -575,
        -2837,
        -3212,
           67,
        -3838,
        -7484,
         7361,
        20456,
         7361,
        -7484,
        -3838,
           67,
        -3212,
        -2837,
         -575,
        -1554,
        -1353,
          588,
          253,
         -501,
          533,
          849,
          106,
          377,
          841,
          384,
          220,
          533,
          298,
          -60,
           39,
          -16,
         -320,
         -325,
         -234,
         -350,
         -354,
         -188,
         -145
    };

    static __int16 x[Ntap]; //input samples
    __int32 y=0;            //output sample
    int n;

    //shift the old samples
    for(n=Ntap-1; n>0; n--)
       x[n] = x[n-1];

    //Calculate the new output
    x[0] = NewSample;
    for(n=0; n<Ntap; n++)
        y += FIRCoef[n] * x[n];
    
    return y / DCgain;
}
