/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33CK256MP508
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/mcc.h"
#ifndef FCY
#define FCY (_XTAL_FREQ / 2)
#endif
#include <libpic30.h>
#include <stdint.h>
#include "mcc_generated_files/interrupt_manager.h"

/*
                         Main application
 */
uint8_t t = 0;

void eightled_off()
{
    LED_1_SetLow();
    LED_2_SetLow();
    LED_3_SetLow();
    LED_4_SetLow();
    LED_5_SetLow();
    LED_6_SetLow();
    LED_7_SetLow();
    LED_8_SetLow();
}

void eightled_on()
{
    LED_1_SetHigh();
    LED_2_SetHigh();
    LED_3_SetHigh();
    LED_4_SetHigh();
    LED_5_SetHigh();
    LED_6_SetHigh();
    LED_7_SetHigh();
    LED_8_SetHigh();
}



void led_on_sequence(int num)
{
    switch (num)
    {
    case 1:
        LED_1_SetHigh();
        break;
    case 2:
        LED_2_SetHigh();
        break;
    case 3:
        LED_3_SetHigh();
        break;
    case 4:
        LED_4_SetHigh();
        break;
    case 5:
        LED_5_SetHigh();
        break;
    case 6:
        LED_6_SetHigh();
        break;
    case 7:
        LED_7_SetHigh();
        break;
    case 8:
        LED_8_SetHigh();
        break;
    }
}

void led_off_sequence(int num)
{
    switch (num)
    {
    case 1:
        LED_1_SetLow();
        break;
    case 2:
        LED_2_SetLow();
        break;
    case 3:
        LED_3_SetLow();
        break;
    case 4:
        LED_4_SetLow();
        break;
    case 5:
        LED_5_SetLow();
        break;
    case 6:
        LED_6_SetLow();
        break;
    case 7:
        LED_7_SetLow();
        break;
    case 8:
        LED_8_SetLow();
        break;
    }
}

void printf_8led(uint8_t value)
{
    for (int i = 1; i <= 8; i++)
    {
        if (value & (1 << (8 - i)))
        {
            led_on_sequence(i);
        }
        else
        {
            led_off_sequence(i);
        }
    }
}
void type1()
{
    eightled_off();
    __delay_ms(200);
    eightled_on();
    __delay_ms(200);
    //    if (t!=1) return ;
}
// fading gradually, gradually fading -> left
void type2()
{
    // gradually brightens from right to left
    for (int i = 8; i >= 1; i--)
    {
        led_on_sequence(i);
        __delay_ms(200);
    }
    //      if (t!=2) return ;
    // fading right to left
    for (int i = 8; i >= 1; i--)
    {
        led_off_sequence(i);
        __delay_ms(200);
    }
    //      if (t!=2) return ;
}
// gradually brightens, gradually turns off -> right

void type3()
{
    // gradually brightens from left to right
    for (int i = 1; i <= 8; i++)
    {
        led_on_sequence(i);
        __delay_ms(200);
    }
    //      if (t!=3) return ;
    // fading left to right
    for (int i = 1; i <= 8; i++)
    {
        led_off_sequence(i);
        __delay_ms(200);
    }
    //      if (t!=3) return ;
}
// gradually brightens and fades from outside to inside

void type4()
{
    // gradually brightens from the outside to the inside
    for (int i = 1; i <= 4; i++)
    {
        led_on_sequence(i);
        led_on_sequence(9 - i);
        __delay_ms(100);
    }
    //      if (t!=4) return ;
    // gradually fades from outside to inside
    for (int i = 1; i <= 4; i++)
    {
        led_off_sequence(i);
        led_off_sequence(9 - i);
        __delay_ms(100);
    }
    //      if (t!=4) return ;
}
// gradually brightens, gradually fades from inside to outside

void type5()
{
    // gradually brightens from the inside out
    for (int i = 0; i < 4; i++)
    {
        led_on_sequence(4 - i);
        led_on_sequence(5 + i);
        __delay_ms(100);
    }
    //      if (t!=5) return ;
    // fading from the inside out
    for (int i = 0; i < 4; i++)
    {
        led_off_sequence(4 - i);
        led_off_sequence(5 + i);
        __delay_ms(100);
    }
    //      if (t!=5) return ;
}
// LED light on and off alternately

void type6()
{
    // Light up LEDs 1,3,5,7 and LEDs 2,4,6,8
    for (int i = 1; i <= 8; i++)
    {
        if (i % 2 == 1)
        {
            led_on_sequence(i);
        }
        else
        {
            led_off_sequence(i);
        }
    }
    __delay_ms(100);
    //      if (t!=6) return ;
    // light up LEDs 2,4,6,8 and turn off LEDs 1,3,5,7
    for (int i = 1; i <= 8; i++)
    {
        if (i % 2 == 0)
        {
            led_on_sequence(i);
        }
        else
        {
            led_off_sequence(i);
        }
    }
    __delay_ms(200);
    //      if (t!=6) return ;
}
// Type 7 on blizzard right to left

void type7()
{
    uint8_t y = 0;
    uint8_t run = 0x01;
    uint8_t saved = 0;
    for (int k = 0; k < 8; k++)
    {
        for (int i = k; i < 8; i++)
        {
            y = run | saved;
            printf_8led(y);
            __delay_ms(200);
            run <<= 1;
        }
        saved = y;
        run = 0x01;
    }
}
//      if (t!=7) return ;

// Type 8 on blizzard from left to right

void type8()
{
    uint8_t y = 0;
    uint8_t run = 0x80;
    uint8_t saved = 0;
    for (int k = 0; k < 8; k++)
    {
        for (int i = k; i < 8; i++)
        {
            y = run | saved;
            printf_8led(y);
            __delay_ms(200);
            run >>= 1;
        }
        saved = y;
        run = 0x80;
    }
    //      if (t!=8) return ;
}
// Type 9 off blizzard right to left

void type9()
{
    uint8_t y = 0xFF;
    uint8_t run = 0x01;
    uint8_t saved = 0xFF;
    for (int k = 0; k < 8; k++)
    {
        for (int i = k; i < 8; i++)
        {
            y = saved & ~run;
            printf_8led(y);
            __delay_ms(200);
            run <<= 1;
        }
        saved = y;
        run = 0x01;
    }
    //    if (t!=9) return ;
}
// Type 10 off blizzard from left to right

void type10()
{
    uint8_t y = 0xFF;
    uint8_t run = 0x80;
    uint8_t saved = 0xFF;
    for (int k = 0; k < 8; k++)
    {
        for (int i = k; i < 8; i++)
        {
            y = saved & ~run;
            printf_8led(y);
            __delay_ms(200);
            run >>= 1;
        }
        saved = y;
        run = 0x80;
    }
    //      if (t!=10) return ;
}

static void INT0_CallBack(void)
{
    // Button UP
    if (S1_GetValue() == 0)
        ;

    {
        t++;
        if (t == 11)
            t = 0;
    }
}
static void INT1_CallBack(void)
{
    if (S2_GetValue() == 0)
        ;
    {
        t--;
        if (t == 0)
            t = 10;
    }
}

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    INTERRUPT_GlobalEnable();
    EXT_INT_Initialize();
    S1_SetInterruptHandler(INT0_CallBack);
    S2_SetInterruptHandler(INT1_CallBack);
    t = 0;
    while (1)
    {
        // Add your application code
        switch (t)
        {
        case 1:
            type1();
            break;
        case 2:
            type2();
            break;
        case 3:
            type3();
            break;
        case 4:
            type4();
            break;
        case 5:
            type5();
            break;
        case 6:
            type6();
            break;
        case 7:
            type7();
            break;
        case 8:
            type8();
            break;
        case 9:
            type9();
            break;
        case 10:
            type10();
            break;
        default:
            break;
        }
    }
    return 1;
}
/**
 End of File
*/
