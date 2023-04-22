#include "main.h"
#include <string.h>
#include <unistd.h>

/**
 *write_signed_number - a function that writes signed decimal integer
 *@args:variadic arguments
 *Return:the number of characters printed
*/
int write_signed_number(va_list args)
{
	int num, len, temp, i;
	char *c; 

	num = va_arg(args, int);
	
	if(num == 0)
	{
		write(STDOUT_FILENO, "0", 1);
		return (1);
	}
	
	len = 0;
	if(num < 0)
	{
		len += 1;
	}
	
	temp = num;
	
	while (temp != 0)
	{
		temp = temp / 10;
		len++;
	}
	
	c = malloc((len + 1) * sizeof(char));
	
	if(c == NULL)
		return 0;
	
	if((num < 0) )
		{
			c[0] = '-';
			i = 1;
			num = num * -1;
		}
		else
			i = 0;
	for (; i < len - 1; i++)
	{
		c[len - i - 1] = '0' + (num % 10);
		num = num / 10;
	}
	c[len] = '\0';
	write(STDOUT_FILENO, c, len);
	free(c);
	return (len);
}
