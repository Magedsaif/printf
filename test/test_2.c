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








	len = _printf("Length:[%d, %i]\n", len, len);
    len2 = printf("Length:[%d, %i]\n", len2, len2);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

    len = _printf("Negative:[%d]\n", -762534);
    len2 = printf("Negative:[%d]\n", -762534);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len =_printf("Len:[%d]\n", len);
    len2 =printf("Len:[%d]\n", len2);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);




	len = _printf("len %d\n", 0377);
	len2 = printf("len %d\n", 0377);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	
	return 0;
}
