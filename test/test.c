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
	int len, len2;

	len = _printf("");
    len2 = printf("");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	
	len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	
	len = _printf("%s\n", "emad");
	len2 = printf("%s\n", "emad");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	len = _printf("%%\n");
	len2 = printf("%%\n");
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	
	len = _printf(NULL);
	len2 = printf(NULL);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);

	len = _printf(NULL, NULL);
	len2 = printf(NULL, NULL);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);


	len = _printf("%s %c %%\n", NULL);
	len2 = printf("%s %c %%\n", NULL);
	printf("len %d\n", len);
	printf("len2 %d\n", len2);
	return 0;
}
