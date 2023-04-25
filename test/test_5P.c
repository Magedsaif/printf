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
	int len, len2;
	char *c = "enmad";
	
	len2 = printf("len %p\n",  c);
	len = _printf("len %p\n", c);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);


	len2 = printf("len %p\n",  1);
	len = _printf("len %p\n", 1);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);


	len2 = printf("len %p\n",  NULL);
	len = _printf("len %p\n", NULL);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	
	
	
    
    return (0);
}
