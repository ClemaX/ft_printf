/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specs.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/10 23:35:12 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 21:59:39 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <specs.h>
#include <stdarg.h>

/*
**	fmt:	The format string
**
**	Parse an usigned integer from the format string
*/

static int	utoa(const char **fmt)
{
	int	number;

	number = 0;
	if (**fmt == '-')
		(*fmt)++;
	while (ft_isdigit(**fmt))
		number = 10 * number + *((*fmt)++) - '0';
	return (number);
}

/*
**	fmt:	The format string
**
**	Parse flags from the format string
**	Note: If MINUS and ZERO are set, ignore ZERO
*/

static char	parse_flags(const char **fmt)
{
	int		pos;
	char	flags;

	flags = 0;
	while ((pos = ft_strpos("-+ 0#", **fmt)) != -1)
	{
		flags |= (1 << pos);
		(*fmt)++;
	}
	if ((flags & (MINUS | ZERO)) == (MINUS | ZERO))
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
	{
		(*fmt)++;
		width = va_arg(ap, int);
	}
	else
		width = utoa(fmt);
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
	{
		(*fmt)++;
		precision = va_arg(ap, int);
	}
	else
		precision = utoa(fmt);
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
	spec.type = ft_strpos("cspdiuxX%", *(*fmt)++);
	return (spec);
}
