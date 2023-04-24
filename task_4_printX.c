#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>
#include <limits.h>

/**
 * helper_X - a function that helps
 * @bcount: count
 * @num: num
 * Return:nothing
*/
char *helper_X(int bcount, unsigned int num)
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
			binary = (reminder - 10) + 'A';
		else
			binary = reminder + '0';
		s[i] = binary;
		num = num / 16;
	}

	s[0] = binary;
	if (s[0] == '0')
		s[0] = '1';
	s[bcount] = '\0';

	return (s);
}
/**
 * write_heX_number- a function that writes signed hexadecimal integer
 * @args:variadic arguments
 * Return:the number of characters printed
*/
int write_heX_number(va_list args)
{
	unsigned int temp, bcount, num;
	char binary, *s;

	num = va_arg(args, unsigned int);

	if (num == 1 || num == 0)
	{
		binary = '0' + num;
		write(STDOUT_FILENO, &binary, 1);
		return (1);
	}

	temp = num;
	bcount = 0;
	while (temp != 0)
	{
		temp = temp / 16;
		bcount++;
	}
	s = helper_X((bcount), num);
	if (s == NULL)
		return (0);


	bcount =  write(STDOUT_FILENO, s, bcount);
	free(s);
	return (bcount);
}
