//aleatorizador multiplicativo
//un error en un bit, estropea 17
//los hay aditivos, pero no parece que sean autosincronizable

#include <stdint.h>

const uint32_t InitialState = 0x2C350000;	// Initial state of the registers.

void SelfSyncScrambler(uint8_t* data, uint16_t length){
    
    uint32_t scrambler_LFSR = InitialState;

    uint8_t inBit, outBit;
    
    while(length--){
        
        for(int b = 7; b > 0; b--){
            
            inBit = (*data >> b) & 1;
            outBit = (inBit^(scrambler_LFSR >> 16)^(scrambler_LFSR >> 11)) & 1; // H(z) = 1 + z^-12 + z^-17.
            
            if(outBit)
                *data |= (0x01 << b);
            else
                *data &= ~(0x01 << b);
            
            scrambler_LFSR = ((scrambler_LFSR << 1)|(outBit & 1)) & 0x1FFFF;
        }
        
        data++;
        
    }
    
}

void SelfSyncDeScrambler(uint8_t* data, uint16_t length){
    
    uint8_t inBit, outBit;
    
    uint32_t descrambler_LFSR = InitialState;
    
    while(length--){
        
        for(int b = 7; b > 0; b--){
            
            inBit = (*data >> b) & 1;
            outBit = (inBit^(descrambler_LFSR >> 16)^(descrambler_LFSR >> 11)) & 1;
            
            if(outBit)
                *data |= (0x01 << b);
            else
                *data &= ~(0x01 << b);
            
            descrambler_LFSR = ((descrambler_LFSR << 1)|(inBit & 1)) & 0x1FFFF;
        }
   
        data++;
        
    }
    
}


uint16_t crc16(uint8_t* data, uint16_t length){    
//printf("\ncrc %d length\n");

    uint8_t x;
    uint16_t crc = 0xFFFF;

    while (length--){
        x = crc >> 8 ^ *data++;
        x ^= x>>4;
        crc = (crc << 8) ^ ((uint16_t)(x << 12)) ^ ((uint16_t)(x <<5)) ^ ((uint16_t)x);
    }
    return crc;
    
}

/*

 1297 PH:0 SYNC LEN/TYPE:00 @:00 SEQ:02 crc:11ee crclocal:f0f0 :: 
DUMP  33 80 03 1a ee 11 000000000000000000000000000000000000000000


*/


#ifdef TESTCRC
char x[]={0x33,0x80,0x03,0x1a,0xee,0x11};
#include <stdio.h>
int main(void)
{
unsigned short crclocal;
crclocal=crc16(&x[1],3);
printf("crclocal:%04x\n",crclocal);
return 0;
}
#endif
