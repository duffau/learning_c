#include <stdio.h>

extern int a, b;
extern int c;
extern float f; 

int main() {

	/** Defining and printing a char variable**/
	char ch;
	ch = 'a';
	printf("char in string: %c  hex: %x  octal: %o \n", ch, ch, ch);

	int a, b, c;
	float f;

	a = 10;
	b = 20;
	c = a + b;
	printf("value of c: %d\n", c);

	f = 70.0/3.0;
	printf("value of f: %f\n", f);

	return 0;
}