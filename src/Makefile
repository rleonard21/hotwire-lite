CC=/usr/bin/avr-gcc
MEGA=328p
CFLAGS=-lm -g -Os -Wall -mcall-prologues -mmcu=atmega$(MEGA)
OBJ2HEX=/usr/bin/avr-objcopy 
PROG=/usr/bin/avrdude
TARGET=binary
FILES=main.c

.DEFAULT_GOAL = build

clean:
	rm *.hex *.out *.o

build: 
	# compile the source files
	$(CC) $(CFLAGS) $(FILES) -o $(TARGET).out -DF_CPU=16000000

	# convert the output into a hex file
	$(OBJ2HEX) -j .text -j .data -O ihex $(TARGET).out $(TARGET).hex

	# upload the hex file to the AVR
	$(PROG) -c usbtiny -p m$(MEGA) -U flash:w:$(TARGET).hex

fuse:
	# sets the fuses for full swing oscillator, no clock divide
	$(PROG) -c usbtiny -p m$(MEGA) -U lfuse:w:0xe7:m -U hfuse:w:0xd9:m -U efuse:w:0xff:m

test_sa:
	gcc tests/skippingAverageTest.c filter/SkippingAverage.c -o test_sa.out
	./test_sa.out > .test1.txt
	python3 tests/skippingAverageCorrect.py > .test2.txt
	diff -q .test1.txt .test2.txt