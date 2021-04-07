/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "aka_printf.h"

void	cast_number(long long int *number, t_specf *data)
{
	if (data->length == -2)
		*number = (signed char)*number;
	if (data->length == -1)
		*number = (signed short int)*number;
	if (data->length == 0)
		*number = (signed int)*number;
	if (data->length == 1)
		*number = (signed long int)*number;
}

int		put_it(long long int n, t_specf *data, int precision_len)
{
	int	printed;

	printed = 0;
	if (!data->left)
	{
		if (data->sign != 0 && data->zero == '0')
		{
			printed = printed + write(1, &data->sign, 1);
			data->sign = 0;
		}
		while (data->width-- > 0)
			printed = printed + write(1, &data->zero, 1);
	}
	if (data->sign != 0)
		printed = printed + write(1, &data->sign, 1);
	while (precision_len-- > 0)
		printed = printed + write(1, "0", 1);
	if (!(n == 0 && data->precision == 0))
		printed = printed + print_digits(n, 10, data->type);
	while (data->width-- > 0)
		printed = printed + write(1, " ", 1);
	return (printed);
}

int		print_signed(long long int number, t_specf *data)
{
	int	printed;
	int	number_len;
	int	precision_len;

	printed = 0;
	precision_len = 0;
	cast_number(&number, data);
	if (number < 0)
	{
		data->sign = '-';
		number = (-1) * number;
	}
	if (number == 0 && data->precision == 0)
		number_len = 0;
	else
		number_len = n_len(number, 10);
	data->width = data->width - max_among(number_len, data->precision);
	precision_len = data->precision - number_len;
	if (data->sign != 0)
		data->width--;
	printed = put_it(number, data, precision_len);
	return (printed);
}
