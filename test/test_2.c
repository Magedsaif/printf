#include <limits.h>
#include <stdio.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	/*
	len = _printf("len %d\n", (unsigned int)INT_MAX + 1024);
	len2 = printf("len %d\n", (unsigned int)INT_MAX + 1024);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);


	len = _printf("len %d\n", 0);
	len2 = printf("len %d\n", 0);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	*/
	int len, len2;
	len = _printf("len %i\n", -INT_MAX-1);
	len2 = printf("len %i\n", -INT_MAX-1);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf("len %i\n", INT_MAX);
	len2 = printf("len %i\n", INT_MAX);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);


	len = _printf("len %i\n", 0);
	len2 = printf("len %i\n", 0);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf("len %i\n", -5*7);
	len2 = printf("len %i\n", -5*7);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf("len %i\n", 5*7);
	len2 = printf("len %i\n", 5*7);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	
	return 0;
}
