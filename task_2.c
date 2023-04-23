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
	unsigned int num;
	int temp,bcount,i,reminder;
	char *binary;

	num = va_arg(args, int);

	temp = num;
	bcount = 1;
	while (temp != 0)
	{
		temp = temp / 2;
		bcount++;
	}

	binary = malloc(sizeof(char) * (bcount));
	if (binary == NULL)
	{
		return(0);
	}

	for (i = bcount - 1; i >= 0; i--) 
	{ 
		reminder = num % 2;
		binary[i] = reminder + '0';
		num = num / 2;
	}

	binary[bcount] = '\0';

	write(STDOUT_FILENO, binary, bcount);
	return (bcount);
}
