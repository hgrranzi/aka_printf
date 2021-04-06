/* *********************************************** */
/*                                                 */
/*       by: hgrranzi <vkh.mariia@gmail.com>       */
/*                                                 */
/* *********************************************** */

#ifndef AKA_PRINTF_H
# define AKA_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

typedef	struct	s_specf
{
	char		type;
	int			left;
	char		sign;
	int			alterform;
	int			zero;
	int			width;
	int			precision;
	int			length;
}				t_specf;

int				aka_printf(const char *format, ...);
int				print_arg(va_list *p, const char *s, int *index, int for_n);
int				get_specifier(const char *s, int *index);
t_specf			check_specif(va_list *p, const char *s, int start, int finish);
int				get_width(const char *s, int start, t_specf *data, va_list *p);
int				get_flags(const char *s, int start, t_specf *data);
int				get_precis(const char *s, int start, t_specf *data, va_list *p);
int				get_length(const char *s, int start, t_specf *data);
int				print_specifier(va_list *p, t_specf *data);
int				print_signed(long long int number, t_specf *data);
void			cast_number(long long int *number, t_specf *data);
int				put_it(long long int n, t_specf *data, int precision_len);
int				print_unsigned(unsigned long long int number, t_specf *data);
void			cast_unumber(unsigned long long int *number, t_specf *data);
int				put_u(unsigned long long n, t_specf *data, int prec_len, int b);
int				print_alterform(char c);
int				n_len(unsigned long long int n, int base);
int				max_among(int a, int b);
int				print_digits(unsigned long long n, unsigned int base, char x);
int				print_s(char *s, t_specf *data);
int				print_c(int c, t_specf *data);
char			*aka_strchr(const char *s, int c);
int				aka_isdigit(int c);
size_t			aka_strlen(const char *s);
void			aka_strcpy(char *dst, const char *src);

#endif
