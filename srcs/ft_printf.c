/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 16:37:09 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 18:29:07 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>

int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_putstr(char *s);

static int	get_field_width(const char **format, va_list ap)
{
	int field_width;
	
	field_width = 0;
	if (**format++ == '*')
		field_width = va_arg(ap, int);
	else
		while (is_numeric(**format))
			field_width += 10 * field_width + **format++ - '0';
}

static int	get_precision(const char **format)
{
	int precision;
	
	precision = 0;
	if (**format == '.')
		while (is_numeric(**format))
			precision += 10 * precision + **format++ - '0';
	return (precision);
}

static int	print(const char **format, int fw, int p, va_list ap)
{
	char *str;

	p = p | -1;
	if (**format == 'c')
		str = get_char(ap, fw);
	else if (**format == 'd' || **format == 'i')
		str = get_int(ap, fw);
	else if (**format == 'u')
		str = get_uint(ap, fw);
	else if (**format == 's')
		str = get_str(ap, fw);
	else if (**format == 'x' || **format == 'X')
		str = get_hex(ap, fw);
	while (*str && p-- != 0)
		write(1, str, 1);
	free(str);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	int		field_width;
	int		precision;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if(*format != '%')
			ft_putchar(*format++);
		else
		{
			field_width = get_field_width(&format, ap);
			precision = get_precision(&format);
			count += print(&format, field_width, precision, ap);
		}
		format++;
	}
  	va_end(ap);
	return (count);
}
