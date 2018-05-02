/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1619
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"
#include "data.h"

/*
                         Main application
 */


uint8_t ADC_CH0_H = 0x00;
uint8_t ADC_CH0_L = 0x00;

uint8_t ADC_CH1_H = 0x00;
uint8_t ADC_CH1_L = 0x00;

uint8_t ADC_CH2_H = 0x00;
uint8_t ADC_CH2_L = 0x00;

uint8_t UART_TX_BUFFER[10];


void ADC_Loop();

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();


    while (1)
    {
        __delay_ms(100);
        IO_LD_SetHigh();
        __delay_ms(50);
        IO_LD_SetLow();
        
        ADC_Loop();
                
    }

}


void ADC_Loop()
{
    uint16_t ADCresult = 0x00;
    
    ADCresult = ADC_GetConversion(channel_AN0);
    Result_Buffer[1] = ADCresult >> 8;    
    Result_Buffer[0] = ADCresult & 0x00FF;
    
    __delay_ms(50);
    
    ADCresult = ADC_GetConversion(channel_AN1);
    Result_Buffer[3] = ADCresult >> 8;    
    Result_Buffer[2] = ADCresult & 0x00FF;
    
    __delay_ms(50);
    
    ADCresult = ADC_GetConversion(channel_AN2);
    Result_Buffer[5] = ADCresult >> 8;    
    Result_Buffer[4] = ADCresult & 0x00FF;
}

/**
 End of File
*/