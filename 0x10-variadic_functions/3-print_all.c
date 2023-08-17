#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - function that prints anything
 * @format: list of types of arguments passed
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *s, *sep = "";

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
			printf("%s%c", sep, va_arg(args, int));
		else if (format[i] == 'i')
			printf("%s%d", sep, va_arg(args, int));
		else if (format[i] == 'f')
			printf("%s%f", sep, va_arg(args, double));
		else if (format[i] == 's')
		{
			s = va_arg(args, char *);
			if (s != NULL)
				printf("%s%s", sep, s);
			else
				printf("(nil)");
		}

		if (format[i + 1])
			sep = ", ";

		i++;
	}

	printf("\n");

	va_end(args);
}
