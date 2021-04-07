/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "aka_printf.h"

int		print_s(char *s, t_specf *data)
{
	int		printed;
	int		s_len;

	printed = 0;
	if (s == NULL)
		s = "(null)";
	s_len = aka_strlen(s);
	if (data->precision >= 0)
		s_len = (s_len <= data->precision) ? s_len : data->precision;
	data->width = data->width - s_len;
	if (!data->left)
		while (data->width-- > 0)
			printed = printed + write(1, &data->zero, 1);
	while (s_len-- > 0)
		printed = printed + write(1, s++, 1);
	while (data->width-- > 0)
		printed = printed + write(1, " ", 1);
	return (printed);
}

int		print_c(int c, t_specf *data)
{
	int				printed;

	printed = 0;
	data->width = data->width - 1;
	if (!data->left)
		while (data->width > 0)
		{
			printed = printed + write(1, &data->zero, 1);
			data->width--;
		}
	printed = printed + write(1, &c, 1);
	while (data->width > 0)
	{
		printed = printed + write(1, " ", 1);
		data->width--;
	}
	return (printed);
}
