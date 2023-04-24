#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>
#include <limits.h>

/**
 * helper - a function that helps
 * @bcount: count
 * @num: num
 * Return:nothing
*/
void helper(int bcount, unsigned int num)
{
	int reminder;
	char binary;

	if (bcount == 0)
		return;

	reminder = num % 2;
	binary = reminder + '0';
	num = num / 2;
	helper((bcount - 1), num);
	write(STDOUT_FILENO, &binary, 1);
}

/**
 * write_binary_number- a function that writes signed decimal integer
 * @args:variadic arguments
 * Return:the number of characters printed
*/
int write_binary_number(va_list args)
{
	unsigned int num;
	unsigned int temp, bcount;
	char binary;

	(void) temp;
	(void) bcount;
	num = va_arg(args, int);
	if (num == 1 || num == 0)
	{
		binary = '0' + num;
		write(STDOUT_FILENO, &binary, 1);
		return (1);
	}

	return (1);
}
