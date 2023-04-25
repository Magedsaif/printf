#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>
#include <limits.h>

/**
 * helper_XS - a function that helps
 * @bcount: count
 * @num: num
 * Return:nothing
*/
char *helper_XS(int bcount, unsigned int num)
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

	s[bcount] = '\0';

	return (s);
}

/**
 * write_S - a function that writes signed hexadecimal integer
 * @args:variadic arguments
 * Return:the number of characters printed
*/
int write_S(va_list args)
{
	char *s, *str;
	int len, i;

	str = va_arg(args, char*);
	len = 0;
	if (str == NULL)
	{
		str = "(null)";
		len = strlen(str);
		write(STDOUT_FILENO, str, len);
		return (len);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 0 && str[i] < 32) || (str[i] >= 127))
		{
			s = helper_XS((2), str[i]);
			len +=  write(STDOUT_FILENO, "\\x", 2);
			len +=  write(STDOUT_FILENO, s, 2);
			free(s);
		}
		else
		{
			write(STDOUT_FILENO, &str[i], 1);
			len = len + 1;
		}
		i++;
	}

	return (len);
}
