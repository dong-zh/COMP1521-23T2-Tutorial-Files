#include <stdio.h>
#include <stdint.h>

#define NO_INK (0x1)
#define COLOUR (0x2)
#define SELECT_PRINT (0x4)
#define SELECT_SCAN (0x8)
#define START (0x10)

// The printer
uint8_t printerControl = 0b0000111;

void checkInk(void);
void replaceInk(void);
void useColourAndSelectScan(void);
void toggleMode(void);
void start(void);

int main(void)
{
	// Main function for testing
	printf("printerControl = 0x%02x\n", printerControl);
	checkInk();
	replaceInk();

	// useColourAndSelectScan();
	// start();
	// toggleMode();
	printf("printerControl = 0x%02x\n", printerControl);

}

void checkInk(void)
{
	if (printerControl & NO_INK) {
		printf("No ink\n");
	} else {
		printf("Has ink\n");
	}
}

void replaceInk(void)
{
	printerControl &= ~NO_INK;
}

void useColourAndSelectScan(void)
{
	printerControl |= (SELECT_SCAN | COLOUR);
}

void toggleMode(void)
{
	printerControl ^= (SELECT_SCAN | SELECT_PRINT);
}

void start(void)
{
}
