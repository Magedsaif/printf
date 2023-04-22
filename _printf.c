/*
 * 0x06. C - More pointers, arrays and strings
 */
#include "main.h"
#include <string.h> 
#include <unistd.h>
int write_string(va_list args)
{
	int len;
	char *str;

	str = va_arg(args, char*);
	len = strlen(str);
	write (STDOUT_FILENO, str, len);

	return (len);

}
int write_char(va_list args)
{
	char c;

	c = (char) va_arg(args, int);
	write (STDOUT_FILENO, &c,1);

	return 1;
}

int write_specifier(va_list args)
{
	(void) args;
	write (STDOUT_FILENO, "%",1);

	return 1;
}


int is_specifier(specifier_t spacifiers[], char *format)
{
	int i;
	char fchar;
	i = 0;
	if(format[i] == '%')
	{
		if(format[i + 1] == '\0')
			return (-1);/*error*/
		else
		{
			fchar = format[i + 1];
			/*select spacifier function*/
			for (i = 0; i < 3; i++)
			{
				
				if(spacifiers[i].s == fchar)
					return (i);
			}
		}
		
	}
		
	/*not found*/
	return (-2);
}
/**
 * _strcmp - copies a string.
 * @s1: string refrance
 * @s2: string refrance
 * Return: 0 in equity
 */
int _printf(const char *format, ...)
{
	int i, s_index, write_count;
	va_list args;
	specifier_t spacifiers[] = {{'s', write_string}, {'c', write_char}, {'%', write_specifier}};
	
	va_start(args, format);
	write_count = 0;
	for (i = 0;(format != NULL) && (format[i] != '\0'); i++)
	{
		s_index = is_specifier(spacifiers, (char *) (format + i));
		
		if(s_index == -2)
			/*print char*/
			{
				write (STDOUT_FILENO, (char *) (format + i), 1);
				
				write_count ++;
			}
		else if(s_index == -1)
			/*print char*/
			return (-1);
		else
		{
			write_count = write_count + spacifiers[s_index].f(args);
			i++;
		}
			
		

	}
	
	return (write_count);

}
