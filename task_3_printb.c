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

	num = va_arg(args, int);
	

	temp = num;
	bcount = 0;
	while (temp != 0)
	{
		temp = temp / 2;
		bcount++;
	}
	helper((bcount - 1), num);
	return (bcount);
}
