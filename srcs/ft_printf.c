/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 16:37:09 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 01:26:58 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

static void	get_flags(const char **fmt, va_list ap, t_settings *s)
{
	s->padding = ' ';
	s->neg_fw = 0;
	s->prefix = 0;
	while ((ft_strchr("#0 -+\'", **fmt)))
	{
		if (**fmt == '#')
		{
			(*fmt)++;
			s->prefix = 1;
		}
		if (**fmt == '0' || **fmt == ' ')
			s->padding = *((*fmt)++);
		if (**fmt == '-')
		{
			s->neg_fw = 1;
			(*fmt)++;
		}
	}
}

static void	get_field_width(const char **fmt, va_list ap, t_settings *s)
{
	if (**fmt == '*')
	{
		if ((s->field_width = va_arg(ap, int)) < 0)
		{
			s->field_width = -s->field_width;
			s->neg_fw = 1;
			s->padding = ' ';
		}
		(*fmt)++;
	}
	else
		s->field_width = parse_number(fmt);
}

static void	get_precision(const char **fmt, va_list ap, t_settings *s)
{
	if (**fmt == '.')
	{
		(*fmt)++;
		if (**fmt == '*')
		{
			s->precision = va_arg(ap, int);
			(*fmt)++;
		}
		else
			s->precision = parse_number(fmt);
	}
	else
		s->precision = -1;
}

static int	print(const char **fmt, va_list ap, t_settings s)
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
	{
		s.prefix *= 2;
		count = get_int(&str, va_arg(ap, int), s, "0123456789ABCDEF");
	}
	else
		return (-1);
	(*fmt)++;
	write(1, str, count);
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
		if (*fmt == '%')
		{
			fmt++;
			get_flags(&fmt, ap, &s);
			get_field_width(&fmt, ap, &s);
			get_precision(&fmt, ap, &s);
			len += print(&fmt, ap, s);
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
