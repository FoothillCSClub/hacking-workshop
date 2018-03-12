/*
 * bof2.c
 * This program was written to demonstrate the power of overwriting a saved
 * instruction pointer on a stack frame
 *
 * Suggested compiler settings:
 * $ <c compiler> -Wall -static -g -o bof2 bof2.c
 *
 * Author: Grond <grond66@foothillstemclubs.org>
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// given pointers to two chars, swap them
void swap_chars(char *a, char *b) {
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// this does more or less what it's name advertises. nothing terribly deep going
// on here
void reverse_string(char *str) {
	size_t len = strlen(str);
	size_t i;

	for (i = 0; i < len/2; i++)
		swap_chars(str + i, str + len - 1 - i);
}

// function that drops a shell appropriate for the OS that we're running on.
// note that this function is not called from anywhere else in the code
void shell(void) {
#if defined(__unix__)
	system("sh");
#elif defined(_WIN32) || defined (WIN32)
	system("cmd");
#endif
}

int main(void) {
	char buffer[100];

	printf("Give me a string, and I'll reverse it!\n : ");

	// read a line of user input. BUFFER OVERFLOW!
	gets(buffer);

	reverse_string(buffer);

	printf("If you were talking backwards, that would be:\n%s\n", buffer);

	// end the program by collapsing the stack frame that main() uses to
	// store it's local variables
	return 0;
}
