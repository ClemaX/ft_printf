/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 16:37:09 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 09:10:46 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>

static void	get_field_width(const char **fmt, va_list ap, t_settings *s)
{
	s->padding = ' ';
	s->field_width = 0;
	if (**fmt == '0' || **fmt == ' ')
		s->padding = **fmt++;
	if (**fmt++ == '*')
		s->field_width = va_arg(ap, int);
	else
		while (ft_isdigit(**fmt))
			s->field_width += 10 * s->field_width + **fmt++ - '0';
}

static void	get_precision(const char **fmt, va_list ap, t_settings *s)
{
	s->precision = 0;
	if (**fmt++ == '.')
	{
		if (**fmt++ == '*')
			s->precision = va_arg(ap, int);
		else
			while (ft_isdigit(**fmt))
				s->precision += 10 * s->precision + **fmt++ - '0';
	}
}

static int	print(const char **fmt, t_settings s, va_list ap)
{
	int		count;
	char	*str;

	if (**fmt == 'c')
		count = get_char(&str, va_arg(ap, int), s.field_width);
	else if (**fmt == 'd' || **fmt == 'i')
		count = get_int(&str, va_arg(ap, int), s);
	else if (**fmt == 'u')
		count = get_uint(&str, va_arg(ap, unsigned int), s);
	else if (**fmt == 's')
		count = get_str(&str, va_arg(ap, char*), s);
	else if (**fmt == 'x' || **fmt == 'X')
		count = get_hex(&str, va_arg(ap, int), s);
	else
		return (0);
	ft_putstr_fd(str, 1);
	free(str);
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
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt++, 1);
			len++;
		}
		else
		{
			get_field_width(&fmt, ap, &s);
			get_precision(&fmt, ap, &s);
			len += print(&fmt, s, ap);
		}
		fmt++;
	}
	va_end(ap);
	return (len);
}
