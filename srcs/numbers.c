/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   numbers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 17:08:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 23:28:30 by chamada     ###    #+. /#+    ###.fr     */
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
	number.len = ft_numlen(number.value, number.radix);
	if (spec.precision > number.len)
		number.len = spec.precision;
	if ((spec.flags & ZERO) && spec.precision == -1 && spec.width > number.len)
		number.len = spec.width;
	return (number);
}
