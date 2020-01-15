#include <stdio.h>
#include <stdbool.h>

int main(void) {
	bool b = true;
	printf("%i\n", 1 + b);
	char c = 'a';
	printf("%i\n", 1 + c);
	char s[] = "abc";
	printf("%i\n", 1 + s);
}
