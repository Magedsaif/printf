#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdio.h>
#include <limits.h>

/**
 *write_flags - a function that writes a specifier to the standard output
 *@args:variadic arguments
 *Return:the number of characters printed
*/
int write_flags(va_list args)
{
	(void) args;
	write(STDOUT_FILENO, "#", 1);/*prints single specifier to screen*/

	return (1);
}

int write_flags(va_list args)
{
	(void) args;
	write(STDOUT_FILENO, " ", 1);/*prints single specifier to screen*/

	return (1);
}

int write_flags(va_list args)
{
	(void) args;
	write(STDOUT_FILENO, "+", 1);/*prints single specifier to screen*/

	return (1);
}
