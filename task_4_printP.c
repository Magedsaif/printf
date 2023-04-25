#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>
#include <limits.h>


/**
 * helper_xP - a function that helps
 * @bcount: count
 * @num: num
 * Return:nothing
*/
char *helper_xP(int bcount, unsigned long num)
{
	int reminder, i;
	char binary, *s;

	s  = malloc(sizeof(char) * bcount + 1);
	if (s == NULL)
		return (s);
	for (i = bcount - 1; i != -1; i--)
	{
		reminder = num % 16;

		if (reminder > 9)
			binary = (reminder - 10) + 'a';
		else
			binary = reminder + '0';
		s[i] = binary;
		num = num / 16;
	}
	s[bcount] = '\0';

	return (s);
}

/**
 * write_P- a function that writes signed hexadecimal integer
 * @args:variadic arguments
 * Return:the number of characters printed
*/
int write_P(va_list args)
{
	
	unsigned long  num, temp;
	int bcount;
	char binary, *s;
	
	bcount = 0;
	num = (unsigned long) va_arg(args, void *);
	if (num == 0)
	{
		bcount += write(STDOUT_FILENO, "(nil)", 5);
		return (bcount);
	}
	if (num == 1)
	{
		binary = '0' + num;
		bcount += write(STDOUT_FILENO, &binary, 1);
		return (bcount);
	}
	bcount += write(STDOUT_FILENO, "0x", 2);
	temp = num;
	bcount = 0;
	while (temp != 0)
	{
		temp = temp / 16;
		bcount++;
	}
	s = helper_xP((bcount), num);
	if (s == NULL)
		return (0);


	bcount =  write(STDOUT_FILENO, s, bcount);
	free(s);
	
	return (bcount + 2);
}
