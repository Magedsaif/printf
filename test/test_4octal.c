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
	len = _printf("%o\n",8);
	printf("len %d\n", len);
    

	len = _printf("%o\n",7);
	printf("len %d\n", len);

	len = _printf("%o\n",9);
	printf("len %d\n", len);
    return (0);
}
