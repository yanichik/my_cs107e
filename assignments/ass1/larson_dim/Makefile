all:		larson_dim.bin

larson_dim.bin:	larson_dim.o
	arm-none-eabi-objcopy larson_dim.o -O binary larson_dim.bin
	arm-none-eabi-gcc -nostdlib larson_dim.o -o larson_dim.elf
	
larson_dim.o:	larson_dim.s
	arm-none-eabi-as -g larson_dim.s -o larson_dim.o

clean:
	rm larson_dim.bin larson_dim.o larson_dim.elf

larson_dim:
	rpi-install.py larson_dim.bin