all:		larson.bin

larson.bin:	larson.o
	arm-none-eabi-objcopy larson.o -O binary larson.bin

larson.o:	larson.s
	arm-none-eabi-as larson.s -o larson.o

clean:
	rm larson.bin larson.o

larson:	
	rpi-install.py larson.bin