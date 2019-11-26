/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   numbers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 17:08:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 06:27:49 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <numbers.h>
#include <specs.h>

void		parse_dimensions(t_number *n, t_spec s)
{
	int	size;

	n->len = (!n->value && !s.precision) ? 0 : ft_numlen(n->value, n->radix);
	if (s.precision > n->len)
		n->len = s.precision;
	n->prefix = '\0';
	if ((s.flags & HASH) && n->radix == R_HEX && (s.type == PTR || n->value))
	{
		n->prefix = (s.type == LHEX || s.type == PTR) ? 'x' : 'X';
		n->prefix_len = 2 + (n->sign != '\0');
	}
	else if ((s.flags & HASH) && n->radix == R_OCT)
		n->prefix_len = 1 + (n->sign != '\0');
	else
		n->prefix_len = (n->sign != '\0');
	size = s.width - n->prefix_len;
	if ((s.flags & ZERO) && s.precision == -1 && size > n->len)
		n->len = size;
	size = n->len + n->prefix_len;
	n->padding = (s.width > size) ? s.width - size : 0;
}

t_number	parse_number(va_list ap, t_spec spec)
{
	const int	radixes[RADIX_N] = RADIXES;
	const char	*digits[RADIX_N] = DIGITS;
	t_number	number;

	if (spec.type == DEC || spec.type == INT)
		number = convert_signed(ap, spec);
	else
		number = convert_unsigned(ap, spec);
	number.radix = radixes[spec.type - PTR];
	number.digits = digits[spec.type - PTR];
	parse_dimensions(&number, spec);
	return (number);
}
