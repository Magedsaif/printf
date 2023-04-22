/*
 * 0x06. C - More pointers, arrays and strings
 */
#include "main.h"
#include <string.h> 
#include <unistd.h>
/**
 * _strcmp - copies a string.
 * @s1: string refrance
 * @s2: string refrance
 * Return: 0 in equity
 */
int _printf(const char *format, ...)
{
	int i;

	for (i = 0;(format != NULL) && (format[i] != '\0'); i++)
	{
		/*print*/
		write (STDOUT_FILENO, "emad\n", 5);
	}
	
	
	return (0);

}
