#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

/* GPIO Addresses */
#define GPIO_BASE 0x20200000UL
/*volatile*/ unsigned int* GP_FSEL0 = (unsigned int*)(GPIO_BASE);
/*volatile*/ unsigned int* GP_FSEL1 = (unsigned int*)(GPIO_BASE + 0x04);
/*volatile*/ unsigned int* GP_FSEL2 = (unsigned int*)(GPIO_BASE + 0x08);
/*volatile*/ unsigned int* GP_FSEL3 = (unsigned int*)(GPIO_BASE + 0x0c);
/*volatile*/ unsigned int* GP_FSEL4 = (unsigned int*)(GPIO_BASE + 0x10);
/*volatile*/ unsigned int* GP_FSEL5 = (unsigned int*)(GPIO_BASE + 0x14);


/*volatile*/ unsigned int* GP_FSET0 = (unsigned int*)(GPIO_BASE + 0x1c);
/*volatile*/ unsigned int* GP_FSET1 = (unsigned int*)(GPIO_BASE + 0x20);

/*volatile*/ unsigned int* GP_CLR0 = (unsigned int*)(GPIO_BASE + 0x28);
/*volatile*/ unsigned int* GP_CLR1 = (unsigned int*)(GPIO_BASE + 0x2c);

/*volatile*/ unsigned int* GP_LEV0 = (unsigned int*)(GPIO_BASE + 0x34);
/*volatile*/ unsigned int* GP_LEV1 = (unsigned int*)(GPIO_BASE + 0x38);

/*volatile*/ unsigned int* GP_EDS0 = (unsigned int*)(GPIO_BASE + 0x40);
/*volatile*/ unsigned int* GP_EDS1 = (unsigned int*)(GPIO_BASE + 0x44);

/*volatile*/ unsigned int* GP_REN0 = (unsigned int*)(GPIO_BASE + 0x4c);
/*volatile*/ unsigned int* GP_REN1 = (unsigned int*)(GPIO_BASE + 0x50);


/*volatile*/ unsigned int* GP_FEN0 = (unsigned int*)(GPIO_BASE + 0x58);
/*volatile*/ unsigned int* GP_FEN1 = (unsigned int*)(GPIO_BASE + 0x5c);


/*volatile*/ unsigned int* GP_HEN0 = (unsigned int*)(GPIO_BASE + 0x64);
/*volatile*/ unsigned int* GP_HEN1 = (unsigned int*)(GPIO_BASE + 0x68);


/*volatile*/ unsigned int* GP_LEN0 = (unsigned int*)(GPIO_BASE + 0x70);
/*volatile*/ unsigned int* GP_LEN1 = (unsigned int*)(GPIO_BASE + 0x74);


/*volatile*/ unsigned int* GP_AREN0 = (unsigned int*)(GPIO_BASE + 0x7c);
/*volatile*/ unsigned int* GP_ARNE1 = (unsigned int*)(GPIO_BASE + 0x80);


/*volatile*/ unsigned int* GP_AFEN0 = (unsigned int*)(GPIO_BASE + 0x88);
/*volatile*/ unsigned int* GP_AFEN1 = (unsigned int*)(GPIO_BASE + 0x8c);


/*volatile*/ unsigned int* GP_PUD = (unsigned int*)(GPIO_BASE + 0x94);
/*volatile*/ unsigned int* GP_PUD_CLK0 = (unsigned int*)(GPIO_BASE + 0x98);
/*volatile*/ unsigned int* GP_PUD_CLK1 = (unsigned int*)(GPIO_BASE + 0x9c);

/* Functions for Raspberry Pi GPIO. */

enum {
  GPIO_PIN_FIRST = 0,
  GPIO_PIN0 = 0,
  GPIO_PIN1 = 1,
  GPIO_PIN2 = 2,
  GPIO_PIN3 = 3,
  GPIO_PIN4 = 4,
  GPIO_PIN5 = 5,
  GPIO_PIN6 = 6,
  GPIO_PIN7 = 7,
  GPIO_PIN8 = 8,
  GPIO_PIN9 = 9,
  GPIO_PIN10 = 10,
  GPIO_PIN11 = 11,
  GPIO_PIN12 = 12,
  GPIO_PIN13 = 13,
  GPIO_PIN14 = 14,
  GPIO_PIN15 = 15,
  GPIO_PIN16 = 16,
  GPIO_PIN17 = 17,
  GPIO_PIN18 = 18,
  GPIO_PIN19 = 19,
  GPIO_PIN20 = 20,
  GPIO_PIN21 = 21,
  GPIO_PIN22 = 22,
  GPIO_PIN23 = 23,
  GPIO_PIN24 = 24,
  GPIO_PIN25 = 25,
  GPIO_PIN26 = 26,
  GPIO_PIN27 = 27,
  GPIO_PIN28 = 28,
  GPIO_PIN29 = 29,
  GPIO_PIN30 = 30,
  GPIO_PIN31 = 31,
  GPIO_PIN32 = 32,
  GPIO_PIN33 = 33,
  GPIO_PIN34 = 34,
  GPIO_PIN35 = 35,
  GPIO_PIN36 = 36,
  GPIO_PIN37 = 37,
  GPIO_PIN38 = 38,
  GPIO_PIN39 = 39,
  GPIO_PIN40 = 40,
  GPIO_PIN41 = 41,
  GPIO_PIN42 = 42,
  GPIO_PIN43 = 43,
  GPIO_PIN44 = 44,
  GPIO_PIN45 = 45,
  GPIO_PIN46 = 46,
  GPIO_PIN47 = 47,
  GPIO_PIN48 = 48,
  GPIO_PIN49 = 49,
  GPIO_PIN50 = 50,
  GPIO_PIN51 = 51,
  GPIO_PIN52 = 52,
  GPIO_PIN53 = 53,
  GPIO_PIN54 = 54,
  GPIO_PIN_LAST =  54
};
// GPIO pin mappings for UART
#define GPIO_TX GPIO_PIN14
#define GPIO_RX GPIO_PIN15

enum {
  GPIO_FUNC_INPUT   = 0,
  GPIO_FUNC_OUTPUT  = 1,
  GPIO_FUNC_ALT0    = 4,
  GPIO_FUNC_ALT1    = 5,
  GPIO_FUNC_ALT2    = 6,
  GPIO_FUNC_ALT3    = 7,
  GPIO_FUNC_ALT4    = 3,
  GPIO_FUNC_ALT5    = 2,
  GPIO_FUNC_INVALID = 8 // Only returned for invalid pins
};



void gpio_set_function(unsigned int pin, unsigned int function);
void gpio_write(unsigned int pin, unsigned int value);

#endif