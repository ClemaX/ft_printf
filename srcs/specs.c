/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specs.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/10 23:35:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 22:15:25 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <specs.h>
#include <stdarg.h>

/*
**	fmt:	The format string
**
**	Parse a signed integer from the format string
*/

static int	parse_number(char **fmt)
{
	int	number;
	int factor;

	number = 0;
	if (**fmt == '-')
	{
		factor = -1;
		(*fmt)++;
	}
	else
		factor = 1;
	while (ft_isdigit(**fmt))
		number = 10 * number + *((*fmt)++) - '0';
	return (number * factor);
}

/*
**	fmt:	The format string
**
**	Parse flags from the format string
**	Note: If MINUS and ZERO are set, ignore ZERO
*/

static char	parse_flags(const char **fmt)
{
	char	*pos;
	char	flags;

	while (pos = ft_strchr("-+ 0#", *fmt))
		flags |= (1 << (pos - *fmt));
	if (flags & (MINUS | ZERO) == (MINUS | ZERO))
		flags &= ~ZERO;
	return (flags);
}

/*
**	fmt:	The format string
**	ap:		The arguments list
**
**	Parse the field width from the format string
*/

static int	parse_width(const char **fmt, va_list ap)
{
	int	width;

	if (**fmt == '*')
		width = va_arg(ap, int);
	else
		width = parse_number(fmt);
	return (width);
}

/*
**	fmt:	The format string
**	ap:		The arguments list
**
**	Parse the precision from the format string
**	Note: Negative precision is ignored
*/

static int	parse_precision(const char **fmt, va_list ap)
{
	int precision;

	if (**fmt != '.')
		return (-1);
	(*fmt)++;
	if (**fmt == '*')
		precision = va_arg(ap, int);
	else
		precision = parse_number(fmt);
	if (precision < 0)
		return (-1);
	return (precision);
}

/*
**	fmt:		The format string
**	width:		The argument string
**
**	Parse the format string and initialize a new spec
*/

t_spec	parse_spec(const char **fmt, va_list ap)
{
	t_spec	spec;

	spec.flags = parse_flags(fmt);
	spec.width = parse_width(fmt, ap);
	spec.precision = parse_precision(fmt, ap);
	spec.type = **fmt++;
	return (spec);
}
