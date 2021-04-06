/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "aka_printf.h"

int		aka_printf(const char *format, ...)
{
	int		printed;
	va_list	ap;
	int		index;

	printed = 0;
	index = 0;
	va_start(ap, format);
	while (format[index] != '\0')
	{
		if (format[index] == '%')
		{
			index++;
			if (format[index] != '\0')
				printed = printed + print_arg(&ap, format, &index, printed);
		}
		else
		{
			printed = printed + write(1, &format[index], 1);
			index++;
		}
	}
	va_end(ap);
	return (printed);
}
