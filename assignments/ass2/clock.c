#include "timer.h"
#include "gpio.h"

/*
 * Returns the current system time in us.
 *
 * @return system time in microseconds
 */
// unsigned int timer_get_time(void) {
    // return 
// }

/*
 * A simple busy loop that delays the program for `n` microseconds.
 *
 * @param n the number of microseconds to busy loop for
 */
// void delay_us(unsigned int n) {
//     unsigned int start = timer_get_time();
//     while (timer_get_time() - start < n) { /* spin */ }
// }

/*
 * Set GPIO pin number `pin` to the GPIO function `function`. Does not affect
 * other pins.
 *
 * @param pin the pin number to initialize
 * @param function the GPIO function to set for the pin
 */
void gpio_set_function(unsigned int pin, unsigned int function) {
  unsigned int mask = 7;
  unsigned int pin_case = pin/10;
    if ( (pin < GPIO_PIN_FIRST || pin > GPIO_PIN_LAST) || (function < GPIO_FUNC_INPUT || function > GPIO_FUNC_ALT3) )
        ;
    else{
        switch (pin_case){
            case 0:
                *GP_FSEL0 &= ~((mask)<<(3*pin));
                *GP_FSEL0 |= function<<(3*pin);
                break;
            case 1:
                pin = pin%10;
                *GP_FSEL1 &= ~((mask)<<(3*pin));
                *GP_FSEL1 |= function<<(3*pin);
                break;
            case 2:
                pin = pin%20;
                *GP_FSEL2 &= ~((mask)<<(3*pin));
                *GP_FSEL2 |= (function<<(3*pin));
                break;
            case 3:
                pin = pin%30;
                *GP_FSEL3 &= ~((mask)<<(3*pin));
                *GP_FSEL3 |= function<<(3*pin);
                break;
            case 4:
                pin = pin%40;
                *GP_FSEL4 &= ~((mask)<<(3*pin));
                *GP_FSEL4 |= function<<(3*pin);
                break;
            default:
                ;
        }
    }
}

/*
 * Sets GPIO pin number `pin` to the value `value`. The GPIO pin should be set
 * the output mode for this call to function correctly.
 *
 * @param pin the pin number to set or clear
 * @param value 1 if the pin should be set, 0 otherwise
 */
void gpio_write(unsigned int pin, unsigned int value) {
    unsigned int pin_case = pin/32;
    if ( (pin < GPIO_PIN_FIRST || pin > GPIO_PIN_LAST) || (value < 0 || value > 1) ) ;
    else {
        switch (pin_case){
            case 0:
                if (value==1){
                    *GP_FSET0 &= ~(1<<pin);
                    *GP_FSET0 |=   1<<pin;
                }
                else
                    *GP_CLR0 |= 1<<pin;
                break;
            case 1:
                if (value==1){
                    *GP_FSET1 &= ~(1<<(pin-32));
                    *GP_FSET1 |=   1<<(pin-32);
                }
                else
                    *GP_CLR1 |= 1<<(pin-32);
                break;
            default:
                ;
        }
    }
}

static unsigned int numdigs(int num){
    unsigned int cnt = 0;
    while(num>0){
        if (num/10)
        {
            cnt++;
            num /= 10;
        }
        else{
            cnt++;
            break;
        }
    }
    return cnt;
}

static unsigned int power(unsigned int base, unsigned int p){
    unsigned int tot = 1;
    while(p){
        tot *= base;
        p--;
    }
    return tot;
}

static void resetSegs(){
    unsigned int i;
    for (i = 20; i < 27; ++i)
    {
        gpio_set_function(i, GPIO_FUNC_INPUT);
        gpio_write(i, 1);
    }
}
static void resetDigs(){
    unsigned int i;
    for (i = 16; i < 20; ++i)
    {
        gpio_set_function(i, GPIO_FUNC_INPUT);
    }
}
static void delay(){
    volatile unsigned int del = 0x0F00;
    for (int i = 0; i < del; ++i) ;
}
void main(void) {
    volatile int i, j;
    unsigned int num, num_temp;
    
    char arr[10], val;
    // each represents bit pattern to light up segments to form numbers 0 thru 9
    arr[0] = 0x3F;
    arr[1] = 0x06;
    arr[2] = 0x5B;
    arr[3] = 0x4F;
    arr[4] = 0x66;
    arr[5] = 0x6D;
    arr[6] = 0x7D;
    arr[7] = 0x07;
    arr[8] = 0x7F;
    arr[9] = 0x6F;

    unsigned int mask = 1, temp, index, dig;
    num = 1054;
    dig = numdigs(num);
    resetSegs();
    while (1){
        resetDigs();
        num_temp = num;
        for (i = dig-1; i >= 0 ; --i)
        {
            gpio_set_function(GPIO_PIN16+dig-i-1, GPIO_FUNC_OUTPUT);
            gpio_write(GPIO_PIN16+dig-i-1, 1);
            index = (num_temp/power(10,i));
            val = arr[index];
            temp = val>>0;
            for (j = 0; j < 8; ++j, temp = val>>j){
                if (mask & temp){
                    gpio_set_function(j+20, GPIO_FUNC_OUTPUT);
                    gpio_write(j+20, 0);
                }
            }
            delay();
            resetSegs();
            gpio_write(GPIO_PIN16+dig-i-1, 0);
            num_temp = num_temp % (power(10,i));
        }
    }
}