#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>
#include <limits.h>

/**
 * helper_o - a function that helps
 * @bcount: count
 * @num: num
 * Return:nothing
*/
char *helper_o(int bcount, unsigned int num)
{
	int reminder, i;
	char binary, *s;

	s  = malloc(sizeof(char) * bcount + 1);
	if (s == NULL)
		return (s);
	for (i = bcount - 1; i != -1; i--)
	{
		reminder = num % 8;
		binary = reminder + '0';
		s[i] = binary;
		num = num / 8;
	}

	s[0] = binary;
	if (s[0] == '0')
		s[0] = '1';
	s[bcount] = '\0';

	return (s);
}
/**
 * write_octal_number - a function that writes signed octal integer
 * @args:variadic arguments
 * Return:the number of characters printed
*/
int write_octal_number(va_list args)
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
		temp = temp / 8;
		bcount++;
	}
	s = helper_o((bcount), num);
	if (s == NULL)
		return (0);


	bcount =  write(STDOUT_FILENO, s, bcount);
	free(s);
	return (bcount);
}
