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

	_printf("len %d\n", 55);
	_printf("len2 %i\n", 55);
	printf("len2 %d\n", 55);



	_printf("len %d\n", -565);
	_printf("len2 %i\n", -565);
	printf("len2 %d\n", -565);


	_printf("len %d\n", -0);
	_printf("len2 %i\n", -0);
	printf("len2 %d\n", -0);
	return 0;
}
