#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

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
 *write_signed_number - a function that writes signed decimal integer
 *@args:variadic arguments
 *Return:the number of characters printed
*/
int write_binary_number(va_list args)
{
	unsigned int num;
	int temp,bcount;
	char binary;

	num = va_arg(args, int);

	if (num == 1 || num == 0)
	{
		binary = '0' + num;
		write(STDOUT_FILENO, &binary, 1);
		return (1);
	}

	temp = num;
	bcount = 1;
	while (temp != 0)
	{
		temp = temp / 2;
		bcount++;
	}
	/*
	for (i = bcount - 1; i >= 0; i--) 
	{ 
		reminder = num % 2;
		binary = reminder + '0';
		write(STDOUT_FILENO, &binary, 1);
		num = num / 2;
	}
	*/
	helper((bcount -1), num);
	return (bcount);
}

