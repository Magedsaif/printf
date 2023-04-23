#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 *write_decimal - a function that writes signed decimal integer
 *@args:variadic arguments
 *Return:the number of characters printed
*/
int write_decimal(va_list args)
{
	char n;
	int size, t;
	unsigned int number;
	t = va_arg(args, int);
	if (t == 0)
	{
		n = '0';
		write(STDOUT_FILENO, &n, 1);
		return (1);
	}
	size = 0;
	if (t < 0)
	{
		n = '-';
		write(STDOUT_FILENO, &n, 1);
		size = 1;
		number = t * -1;
	}
	else
	{
		number = t;
	}
	t = 1;
	while ((number / t) > 9)
		t *= 10;
	
	while (t != 0)
	{
		n = '0' + (number / t);
		write(STDOUT_FILENO, &n, 1);
		number %= t;
		t /= 10;
		size++;
	}
	
	return (size);
}
