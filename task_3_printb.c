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
char *helper(int bcount, unsigned int num)
{
	int reminder, i;
	char binary, *s;

	s  = malloc(sizeof(char) * bcount + 1);
	if (s == NULL)
		return (s);
	for (i = bcount - 1; i != 0; i--)
	{
		reminder = num % 2;
		binary = reminder + '0';
		s[i] = binary;
		num = num / 2;
	}
	
	s[0] = binary;
	if(s[0] == '0')
		s[0] = '1';
	s[bcount] = '\0';

	return (s);
}
/**
 * write_binary_number- a function that writes signed decimal integer
 * @args:variadic arguments
 * Return:the number of characters printed
*/
int write_binary_number(va_list args)
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
		temp = temp / 2;
		bcount++;
	}
	s = helper((bcount), num);
	if(s == NULL)
		return (0);
	
	
	bcount =  write(STDOUT_FILENO, s, bcount);
	free(s);
	return (bcount);
}
