/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 21:47:21 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 05:24:02 by chamada     ###    #+. /#+    ###.fr     */
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

static void		write_num(char *dest, t_number number)
{
	dest += number.len + number.prefix_len - 1;
	while (number.len--)
	{
		*dest-- = number.digits[number.value % number.radix];
		number.value /= number.radix;
	}
	if (number.prefix)
		*dest-- = number.prefix;
	if ((number.prefix_len - (number.sign != '\0')) > 0)
		*dest-- = '0';
	if (number.sign)
		*dest = number.sign;
}

static t_line	*fmt_num(t_line **line, t_spec s, va_list ap)
{
	const t_number	n = parse_number(ap, s);
	const int		len = n.padding + n.prefix_len + n.len;
	const char		p = ((s.flags & ZERO) && s.precision == -1) ? '0' : ' ';
	char			*content;

	content = malloc(sizeof(*content) * len);
	ft_memset(&content[(s.flags & MINUS) ? len - n.padding : 0], p, n.padding);
	write_num(&content[(s.flags & MINUS) ? 0 : n.padding], n);
	return (line_add(line, content, len));
}

/*
**	line:	The line to add content on
**	spec:	The format specification
**	ap:		The variable-arguments list
**
**	Format each variable according to specification
**	Note: Types are dispatched in following order: cs%pdiuxXo
*/

t_line	*(*g_format[10])(t_line**, t_spec, va_list) = {
	fmt_char,
	fmt_str,
	fmt_char,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num
};
