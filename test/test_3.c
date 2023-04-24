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
	len = _printf("%b", 98);
	printf("len %d\n", len);

	len = _printf("%b", UINT_MAX + UINT_MAX);
	printf("len %d\n", len);
    
    return (0);
}
