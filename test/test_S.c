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
	len = _printf("%S\n", "Best\nSchool");
	printf("len %d\n", len);

	len = _printf("%S\n", "Hello");
	printf("len %d\n", len);

    return (0);
}
