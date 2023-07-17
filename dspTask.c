/*
 * File:   dspTask.c
 * Author: Berni
 *
 * Created on 31 May, 2023, 7:50 PM
 */


#include <xc.h>
#include "config.h"
// Function Declarations:
// - Defined in other file(s):
unsigned int adc_GetConversion(void);
void seg_DispAll(unsigned int count);
unsigned int adc_GetTConversion(void);
unsigned int adc_GetWConversion(void);

// Function Declarations:
// - Defined in other file(s):
void lcdWriteDspData(char x);
void lcdCtrl_SetPos(unsigned char row, unsigned char col);
unsigned int extint_GetCount(void);
// Extern Global Variable

void dspTaskT_OnLCD(void)
{
    unsigned int temp;
    unsigned int count;
    unsigned char dig0, dig1, dig2, dig3;
    if(adc_GetTConversion()== adc_GetTConversion()) {
        
        temp = adc_GetTConversion(); //analog temperature
        count= temp*500/1023;  //Get the count
        dig0 = count%10;
        dig1 = (count/10)%10;
        dig2 = (count/100)%10;
        dig3 = (count/1000)%10;
        lcdCtrl_SetPos(2, 8);
        lcdWriteDspData(dig3 + 0x30);
        lcdWriteDspData(dig2 + 0x30);
        lcdWriteDspData(dig1 + 0x30); // Add 0x30 to translate digit to ASCII
        lcdWriteDspData(dig0 + 0x30);
        
    
    }
}

void dspTaskW_OnLCD(void)
{
    unsigned int Wlvl;
    int count;
    unsigned char dig0, dig1, dig2, dig3;
    if(adc_GetWConversion()== adc_GetWConversion()) {
        
        Wlvl = adc_GetWConversion();
        count = Wlvl/10;// Get the count
        dig0 = count%10;
        dig1 = (count/10)%10;
        dig2 = (count/100)%10;
        dig3 = (count/1000)%10;
        lcdCtrl_SetPos(2, 8);
        lcdWriteDspData(dig3 + 0x30);
        lcdWriteDspData(dig2 + 0x30);
        lcdWriteDspData(dig1 + 0x30); // Add 0x30 to translate digit to ASCII
        lcdWriteDspData(dig0 + 0x30);
        
    
    }
}