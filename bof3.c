/*
 * bof3.c
 * This is a simple program that can be used to demonstrate the classic form
 * of a buffer overflow exploit.
 *
 * suggested compiler options:
 * $ <c compiler> -m32 -o bof3 -Wall -z execstack -fno-stack-protector bof3.c
 * When you run it, make sure that you've turned off address space layout
 * randomization, so that the program section will be loaded in predictable
 * places.
 * On linux, run it with:
 * $ setarch $(arch) --addr-no-randomize
 * On Windows, you should pass /DYNAMICBASE[:NO] to the linker, or in Visual
 * Studio, go to: Configuration Properties -> Linker -> Advanced
 * -> "Randomized Base Address", and turn it off.
 * On Macs, run this command before running the executable:
 * $ export DYLD_NO_PYE=1
 */

#include <stdio.h>

int main(void) {
	char word[20];

	printf("Gimmie a word! : ");
	fflush(stdout);

	// bof, as usual
	gets(word);

	printf("you said: %s\n", word);

	return 0;
}
