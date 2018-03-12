/*
 * bof1.c
 * This program was written for the purpose of demonstrating simple buffer
 * overflows using an on-stack buffer and the gets() function.
 *
 * Suggested compiler settings; if <c compiler> is your C compiler program,
 * compile this program into an executable with:
 * $ <c compiler> -Wall -o bof1 bof1.c
 *
 * Author: Grond <grond66@foothillstemclubs.org>
 */

#include <stdio.h>

int main(void) {
	int x = 5;
	char buffer[100];

	// print the prompt. fflush() is called to ensure that the prompt is
	// actually sent to the screen, since the prompt doesn't contain a
	// newline.
	printf("What do you say? ");
	fflush(stdout);

	// let the user type one line and submit it by pressing <ENTER>
	gets(buffer);
	// this turns out to be very dangerous

	// tell the user what they just typed
	printf("You said %s\n", buffer);
	
	// print the value of x. does it _have_ to be 5?
	printf("x = %d\n", x);

	return 0;
}
