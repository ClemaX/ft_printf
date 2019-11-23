/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 21:47:21 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 23:22:46 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <libft.h>
#include <specs.h>
#include <line.h>
#include <numbers.h>

static t_line	*fmt_char(t_line **line, t_spec spec, va_list ap)
{
	const int	len = (spec.width > 1) ? spec.width : 1;
	const char	c = (spec.type == PCNT) ? '%' : va_arg(ap, unsigned);
	char		*content;

	if (!(content = malloc(sizeof(*content) * len)))
		return (NULL);
	ft_memset(content, (spec.flags & ZERO) ? '0' : ' ', len);
	content[spec.flags & MINUS ? 0 : len - 1] = c;
	return (line_add(line, content, len));
}

static t_line	*fmt_str(t_line **line, t_spec spec, va_list ap)
{
	const char	*str = va_arg(ap, char*);
	const char	*src = (str) ? str : "(null)";
	int			srclen;
	int			len;
	char		*content;

	srclen = ft_strlen(src);
	if (spec.precision >= 0 && spec.precision < srclen)
		srclen = spec.precision;
	len = (spec.width > srclen) ? spec.width : srclen;
	if (!(content = malloc(sizeof(*content) * len)))
		return (NULL);
	ft_memset(content, (spec.flags & ZERO) ? '0' : ' ', len);
	ft_memcpy(content + (len - srclen) * !(spec.flags & MINUS), src, srclen);
	return (line_add(line, content, len));
}

static t_line	*fmt_num(t_line **line, t_spec spec, va_list ap)
{
	t_number		n;
	int				len;
	int				pos;
	char			*content;

	n = parse_number(ap, spec);
	len = ((spec.width > n.len + (n.sign)) ? spec.width : n.len) + (2 * ((spec.flags & HASH) != 0));
	if (!(content = malloc(sizeof(*content) * len)))
		return (NULL);
	pos = ((spec.flags & MINUS) ? n.len + (n.sign != 0) - 1 : len - 1);
	ft_memset(&content[(spec.flags & MINUS) ? pos : 0], ((spec.flags & ZERO) && spec.precision == -1) ? '0' : ' ', (spec.flags & MINUS) ? len - pos : pos - n.len + 1);
	while (n.len--)
	{
		content[pos--] = n.digits[n.value % n.radix];
		n.value /= n.radix;
	}
	if (n.radix == 16 && spec.flags & HASH)
	{
		content[pos--] = (spec.type & LHEX) ? 'x' : 'X';
		content[pos--] = '0';
	}
	if (n.sign != 0)
		content[pos--] = '-';
	return (line_add(line, content, len));
}

/*
**	line:	The line to add content on
**	spec:	The format specification
**	ap:		The variable-arguments list
**
**	Format each variable according to specification
**	Note: Types are dispatched in following order: cspdiuxX%
*/

t_line	*(*g_format[9])(t_line**, t_spec, va_list) = {
	fmt_char,
	fmt_str,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_char
};
