/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#include "aka_printf.h"

int		n_len(unsigned long long int n, int base)
{
	int			i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		i++;
		n = n / base;
	}
	return (i);
}

int		max_among(int a, int b)
{
	int			max;

	max = (a > b) ? a : b;
	return (max);
}

int		print_digits(unsigned long long n, unsigned int base, char x)
{
	int			printed;
	char		x_digits[17];

	printed = 0;
	if (x == 'X')
		aka_strcpy(x_digits, "0123456789ABCDEF");
	else
		aka_strcpy(x_digits, "0123456789abcdef");
	if (n >= base)
	{
		printed = printed + print_digits(n / base, base, x);
		printed = printed + write(1, &x_digits[n % base], 1);
	}
	else
		printed = printed + write(1, &x_digits[n], 1);
	return (printed);
}
