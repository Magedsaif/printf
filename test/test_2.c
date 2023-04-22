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
	len = _printf("len %d\n", 12324654);
	len2 = printf("len %d\n", 12324654);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);


	
	return 0;
}
