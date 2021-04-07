/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "aka_printf.h"

int		get_width(const char *s, int start, t_specf *data, va_list *p)
{
	if (s[start] == '*')
	{
		data->width = va_arg(*p, int);
		if (data->width < 0)
		{
			data->left = 1;
			data->width = (-1) * data->width;
		}
		start++;
	}
	else
		while (aka_isdigit(s[start]))
		{
			data->width = 10 * data->width + (s[start] - '0');
			start++;
		}
	return (start);
}

int		get_length(const char *s, int start, t_specf *data)
{
	if (s[start] == 'l')
	{
		if (s[start + 1] == 'l')
		{
			data->length = 2;
			start++;
		}
		else
			data->length = 1;
	}
	else
	{
		if (s[start + 1] == 'h')
		{
			data->length = -2;
			start++;
		}
		else
			data->length = -1;
	}
	start++;
	return (start);
}

int		get_flags(const char *s, int start, t_specf *data)
{
	if (s[start] == '#')
		data->alterform = 1;
	else if (s[start] == '-')
		data->left = 1;
	else if (s[start] == '+')
		data->sign = '+';
	else if (s[start] == ' ')
	{
		if (data->sign == 0)
			data->sign = ' ';
	}
	else
		start = get_length(s, start, data);
	return (start + 1);
}

int		get_precis(const char *s, int start, t_specf *data, va_list *p)
{
	data->precision = 0;
	while (s[start] == '.')
		start++;
	if (aka_isdigit(s[start]))
	{
		while (aka_isdigit(s[start]))
		{
			data->precision = 10 * data->precision + (s[start] - '0');
			start++;
		}
	}
	else if (s[start] == '*')
	{
		data->precision = va_arg(*p, int);
		if (data->precision < 0)
			data->precision = -1;
		start++;
	}
	if (data->precision >= 0 && data->type != 's')
		data->zero = ' ';
	return (start);
}
