/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   numbers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 17:08:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 21:46:13 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <numbers.h>
#include <specs.h>

t_numsize	parse_size(const char **fmt)
{
	if (**fmt == 'l')
	{
		if (*++(*fmt) == 'l')
		{
			(*fmt)++;
			return (S_LL);
		}
		else
			return (S_L);
	}
	else if (**fmt == 'h')
	{
		if (*++(*fmt) == 'h')
		{
			(*fmt)++;
			return (S_HH);
		}
		else
			return (S_H);
	}
	else
		return (S_DEF);
}

t_number	convert_signed(va_list ap, t_spec spec)
{
	t_number	number;
	int64_t		value;

	if (spec.size == S_L)
		value = va_arg(ap, long);
	else if (spec.size == S_LL)
		value = va_arg(ap, long long);
	else
		value = va_arg(ap, int);
	if (value < 0)
		number.sign = '-';
	else if (spec.flags & PLUS)
		number.sign = '+';
	else if (spec.flags & SPACE)
		number.sign = ' ';
	else
		number.sign = '\0';
	number.value = (number.sign == '-') ? -value : value;
	return (number);
}

t_number	convert_unsigned(va_list ap, t_spec spec)
{
	t_number	number;

	if (spec.type == PTR)
		number.value = (uintptr_t)va_arg(ap, void*);
	else if (spec.size == S_L)
		number.value = va_arg(ap, unsigned long);
	else if (spec.size == S_LL)
		number.value = va_arg(ap, unsigned long long);
	else
		number.value = va_arg(ap, unsigned int);
	if (spec.flags & PLUS)
		number.sign = '+';
	else if (spec.flags & SPACE)
		number.sign = ' ';
	else
		number.sign = '\0';
	return (number);
}

void		parse_dimensions(t_number *n, t_spec s)
{
	int	size;

	n->len = (!n->value && !s.precision) ? 0 : ft_numlen(n->value, n->radix);
	if (s.precision > n->len)
		n->len = s.precision;
	if ((s.flags & HASH) && n->radix == 16
	&& (s.type == PTR || n->value))
	{
		n->prefix = (s.type == LHEX || s.type == PTR) ? 'x' : 'X';
		n->prefix_len = 2;
	}
	else
	{
		n->prefix = '\0';
		n->prefix_len = 0;
	}
	if ((s.flags & ZERO) && s.precision == -1 && s.width > n->len)
		n->len = s.width - (n->sign != '\0') - n->prefix_len;
	size = n->len + n->prefix_len + (n->sign != '\0');
	if (s.width > size)
		n->padding = s.width - size;
	else
		n->padding = 0;
}

t_number	parse_number(va_list ap, t_spec spec)
{
	t_number	number;

	if (spec.type == DEC || spec.type == INT || spec.type == UINT)
	{
		if (spec.type == UINT)
			number = convert_unsigned(ap, spec);
		else
			number = convert_signed(ap, spec);
		number.digits = D_DEC;
		number.radix = R_DEC;
	}
	else
	{
		number = convert_unsigned(ap, spec);
		number.radix = R_HEX;
		if (spec.type == LHEX || spec.type == PTR)
			number.digits = D_LHEX;
		else if (spec.type == UHEX)
			number.digits = D_UHEX;
	}
	parse_dimensions(&number, spec);
	return (number);
}
