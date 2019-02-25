#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#define TIMER_BASE 0x20203000UL

/*volatile*/ unsigned int* CS = (unsigned int*)(TIMER_BASE);
/*volatile*/ unsigned int* CLO = (unsigned int*)(TIMER_BASE + 0x04);
/*volatile*/ unsigned int* CHI = (unsigned int*)(TIMER_BASE + 0x08);
/*volatile*/ unsigned int* C0 = (unsigned int*)(TIMER_BASE + 0xC);
/*volatile*/ unsigned int* C1 = (unsigned int*)(TIMER_BASE + 0x10);
/*volatile*/ unsigned int* C2 = (unsigned int*)(TIMER_BASE + 0x14);
/*volatile*/ unsigned int* C3 = (unsigned int*)(TIMER_BASE + 0x18);


unsigned int timer_get_time();
void delay_us(unsigned int n);


#endif