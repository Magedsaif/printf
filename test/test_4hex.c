#include "../main.h"
#include <stdio.h>
#include <limits.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
	len = _printf("%x\n",16);
	printf("len %d\n", len);
    

	len = _printf("%x\n",15);
	printf("len %d\n", len);

	len = _printf("%o\n",17);
	printf("len %d\n", len);

	len = _printf("%o\n",1);
	printf("len %d\n", len);
    return (0);
}
