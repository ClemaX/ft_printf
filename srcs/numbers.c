/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   numbers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 17:08:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 04:59:01 by chamada     ###    #+. /#+    ###.fr     */
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
	if ((s.flags & HASH) && n->radix == 16 && (s.type == PTR || n->value))
	{
		n->prefix = (s.type == LHEX || s.type == PTR) ? 'x' : 'X';
		n->prefix_len = 2 + (n->sign != '\0');
	}
	else
	{
		n->prefix = '\0';
		n->prefix_len = (n->sign != '\0');
	}
	size = s.width - n->prefix_len;
	if ((s.flags & ZERO) && s.precision == -1 && size > n->len)
		n->len = size;
	size = n->len + n->prefix_len;
	n->padding = (s.width > size) ? s.width - size : 0;
}

t_number	get_dec(va_list ap, t_spec spec)
{
	t_number	number;

	if (spec.type == UINT)
		number = convert_unsigned(ap, spec);
	else
		number = convert_signed(ap, spec);
	number.digits = D_DEC;
	number.radix = R_DEC;
	return (number);
}

t_number	get_hex(va_list ap, t_spec spec)
{
	t_number	number;

	number = convert_unsigned(ap, spec);
	number.radix = R_HEX;
	if (spec.type == LHEX || spec.type == PTR)
		number.digits = D_LHEX;
	else if (spec.type == UHEX)
		number.digits = D_UHEX;
	return (number);
}

t_number	parse_number(va_list ap, t_spec spec)
{
	t_number	number;

	if (spec.type == DEC || spec.type == INT || spec.type == UINT)
		number = get_dec(ap, spec);
	else
		number = get_hex(ap, spec);
	parse_dimensions(&number, spec);
	return (number);
}
