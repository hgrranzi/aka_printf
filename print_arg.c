/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "aka_printf.h"

int		get_specifier(const char *s, int *index)
{
	int		finish;

	finish = *index;
	while (s[finish] != '\0')
	{
		if (aka_isdigit(s[finish]) || aka_strchr("-0.*# +lh", s[finish]))
			finish++;
		else if (aka_strchr("dcspdiuxXnfge%%", s[finish]))
		{
			finish++;
			break ;
		}
		else
			break ;
	}
	return (finish);
}

t_specf	check_specif(va_list *p, const char *s, int start, int finish)
{
	t_specf	data;

	data.type = s[finish - 1];
	data.left = 0;
	data.sign = 0;
	data.alterform = 0;
	data.zero = ' ';
	data.width = 0;
	data.precision = -1;
	data.length = 0;
	while (start < finish - 1)
	{
		if (aka_strchr("-+# lh", s[start]))
			start = get_flags(s, start, &data);
		else if (s[start] == '0')
		{
			data.zero = '0';
			start++;
		}
		else if (aka_isdigit(s[start]) || s[start] == '*')
			start = get_width(s, start, &data, p);
		else if (s[start] == '.')
			start = get_precis(s, start, &data, p);
	}
	return (data);
}

int		print_specifier(va_list *p, t_specf *data)
{
	int		printed;

	printed = 0;
	if (data->type == 'd' || data->type == 'i')
		printed = print_signed(va_arg(*p, long long int), data);
	if (data->type == 'u' || data->type == 'x' || data->type == 'X')
		printed = print_unsigned(va_arg(*p, unsigned long long int), data);
	if (data->type == 's')
		printed = print_s(va_arg(*p, char *), data);
	if (data->type == 'c')
		printed = print_c(va_arg(*p, int), data);
	if (data->type == '%')
		printed = print_c('%', data);
	if (data->type == 'p')
		printed = print_unsigned(va_arg(*p, uintptr_t), data);
	return (printed);
}

int		print_arg(va_list *p, const char *s, int *index, int for_n)
{
	int		finish;
	int		printed;
	t_specf	data;
	int		*n;

	printed = 0;
	finish = get_specifier(s, index);
	data = check_specif(p, s, *index, finish);
	if (data.type == 'n')
	{
		n = va_arg(*p, int *);
		*n = for_n;
	}
	else
		printed = print_specifier(p, &data);
	*index = finish;
	return (printed);
}
