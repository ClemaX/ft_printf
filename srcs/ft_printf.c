/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 16:37:09 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 18:32:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libftprintf.h>
#include <stdarg.h>

static int	get_field_width(const char **format, va_list ap)
{
	int field_width;

	field_width = 0;
	if (**format++ == '*')
		return (va_arg(ap, int));
	else
		while (is_numeric(**format))
			field_width += 10 * field_width + **format++ - '0';
	return (field_width);
}

static int	get_precision(const char **format, va_list ap)
{
	int precision;

	precision = 0;
	if (**format++ == '.')
	{
		if (**format == '*')
		{
			**format++;
			precision = va_arg(ap, int);
		}
		else
			while (is_numeric(**format))
				precision += 10 * precision + **format++ - '0';
	}
	return (precision);
}

static int	print(const char **format, t_settings settings, va_list ap)
{
	int		count;
	char	*str;

	if (**format == 'c')
		str = get_char(va_arg(ap, char), settings.field_width);
	else if (**format == 'd' || **format == 'i')
		str = get_int(ap, settings);
	else if (**format == 'u')
		str = get_uint(ap, settings);
	else if (**format == 's')
		str = get_str(ap, settings);
	else if (**format == 'x' || **format == 'X')
		str = get_hex(ap, settings);
	while (str[count] && settings.precision--)
		write(1, str[count++], 1);
	free(str);
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_settings	settings;
	int			count;

	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
			ft_putchar(*format++);
		else
		{
			settings.field_width = get_field_width(&format, ap);
			settings.precision = get_precision(&format, ap);
			count += print(&format, settings, ap);
		}
		format++;
	}
	va_end(ap);
	return (count);
}
