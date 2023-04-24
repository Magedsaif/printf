#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>
#include <limits.h>

/**
 * helpers - a function that helps
 * @ocount: count
 * @num: num
 * Return:nothing
*/
void helpers(int ocount, unsigned int num)
{
	int reminder;
	char octal;

	if (ocount == 0)
		return;

	reminder = num % 8;
	octal = reminder + '0';
	num = num / 8;
	helpers((ocount - 1), num);
	write(STDOUT_FILENO, &octal, 1);
}

/**
 * write_octal_number - a function that writes signed decimal integer
 * @args:variadic arguments
 * Return:the number of characters printed
*/
int write_octal_number(va_list args)
{
	unsigned int num;
	unsigned int temp, ocount;
	char octal;

	num = va_arg(args, int);
	if (num == 1 || num == 0)
	{
		octal = '0' + num;
		write(STDOUT_FILENO, &octal, 1);
		return (1);
	}

	temp = num;
	ocount = 0;
	while (temp != 0)
	{
		temp = temp / 8;
		ocount++;
	}
	helpers((ocount), num);
	return (ocount - 1);
}
