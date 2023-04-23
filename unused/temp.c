#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

/**
 *write_signed_number - a function that writes signed decimal integer
 *@args:variadic arguments
 *Return:the number of characters printed
*/
int write_binary_number(va_list args)
{
	char n;
	int size, t;
	unsigned int number;
	number = va_arg(args, int);

	if (number == 0)
	{
		n = '0';
		write(STDOUT_FILENO, &n, 1);
		return (1);
	}
	size = 0;
	t = 1;
	while ((number / t) > 9)
		t *= 10;
}
