/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "aka_printf.h"

void	cast_unumber(unsigned long long int *number, t_specf *data)
{
	if (data->length == 1 || data->type == 'p')
		*number = (unsigned long int)*number;
	else if (data->length == -2)
		*number = (unsigned char)*number;
	else if (data->length == -1)
		*number = (unsigned short int)*number;
	else if (data->length == 0)
		*number = (unsigned int)*number;
}

int		print_alterform(char c)
{
	int	printed;

	printed = 0;
	if (c == 'x' || c == 'p')
		printed = write(1, "0x", 2);
	if (c == 'X')
		printed = write(1, "0X", 2);
	return (printed);
}

int		put_u(unsigned long long n, t_specf *data, int prec_len, int b)
{
	int	printed;

	printed = 0;
	if (!data->left)
	{
		if (data->alterform != 0 && data->zero == '0')
		{
			printed = printed + print_alterform(data->type);
			data->alterform = 0;
		}
		while (data->width-- > 0)
			printed = printed + write(1, &data->zero, 1);
	}
	if ((data->alterform != 0) || data->type == 'p')
		printed = printed + print_alterform(data->type);
	while (prec_len-- > 0)
		printed = printed + write(1, "0", 1);
	if (!(n == 0 && data->precision == 0))
		printed = printed + print_digits(n, b, data->type);
	while (data->width-- > 0)
		printed = printed + write(1, " ", 1);
	return (printed);
}

int		print_unsigned(unsigned long long int number, t_specf *data)
{
	int	printed;
	int	number_len;
	int	precision_len;
	int	base;

	if (data->type == 'u')
		base = 10;
	else
		base = 16;
	printed = 0;
	cast_unumber(&number, data);
	if (number == 0)
		data->alterform = 0;
	if (number == 0 && data->precision == 0)
		number_len = 0;
	else
		number_len = n_len(number, base);
	data->width = data->width - max_among(number_len, data->precision);
	precision_len = data->precision - number_len;
	if ((data->alterform != 0) || data->type == 'p')
		data->width = data->width - 2;
	printed = put_u(number, data, precision_len, base);
	return (printed);
}
