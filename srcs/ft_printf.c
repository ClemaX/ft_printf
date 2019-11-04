/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 16:37:09 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 15:24:11 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/*
**TODO: Implement '-'
*/

static void	get_field_width(const char **fmt, va_list ap, t_settings *s)
{
	s->padding = ' ';
	s->field_width = -1;
	while (**fmt == '0' || **fmt == ' ')
		s->padding = **(fmt++);
	if (**fmt == '*')
	{
		s->field_width = va_arg(ap, int);
		(*fmt)++;
	}
	else
	{
		s->field_width = 0;
		while (ft_isdigit(**fmt))
			s->field_width += 10 * s->field_width + *(*fmt++) - '0';
	}
}

static void	get_precision(const char **fmt, va_list ap, t_settings *s)
{
	if (**(fmt++) == '.')
	{
		if (**(fmt++) == '*')
			s->precision = va_arg(ap, int);
		else
		{
			s->precision = 0;
			while (ft_isdigit(**fmt))
				s->precision += 10 * s->precision + **(fmt++) - '0';
		}
	}
	else
		s->precision = -1;
}

static int	print(const char **fmt, t_settings s, va_list ap)
{
	int		count;
	char	*str;

	if (**fmt == 'c')
		count = get_char(&str, va_arg(ap, int), s.field_width);
	else if (**fmt == 'd' || **fmt == 'i')
		count = get_int(&str, va_arg(ap, int), s, "0123456789");
	else if (**fmt == 'u')
		count = get_uint(&str, va_arg(ap, unsigned int), s);
	else if (**fmt == 's')
		count = get_str(&str, va_arg(ap, char*), s);
	else if (**fmt == 'x')
		count = get_int(&str, va_arg(ap, int), s, "0123456789abcdef");
	else if (**fmt == 'X')
		count = get_int(&str, va_arg(ap, int), s, "0123456789ABCDEF");
	else
		count = -1;
	(*fmt)++;
	if (count > 0)
	{
		write(1, str, count);
		free(str);
	}
	return (count);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_settings	s;
	int			len;

	len = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			get_field_width(&fmt, ap, &s);
			get_precision(&fmt, ap, &s);
			len += print(&fmt, s, ap);
		}
		else
		{
			ft_putchar_fd(*fmt++, 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
