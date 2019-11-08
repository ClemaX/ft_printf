/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_numbers.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 09:49:01 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/08 01:44:08 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static size_t	intlen(long n, int base)
{
	size_t	len;

	len = (n < 0 && base != 16) + 1;
	while (n /= base)
		len++;
	return (len);
}

void			write_u(char *str, int n, const char *base, int b_len)
{
	const int	neg = (n < 0 && b_len != 16);
	unsigned	u_n;

	u_n = (neg) ? -n : n;
	if (n == 0)
		*str = '0';
	else
		str += intlen(n, b_len) - 1;
	while (u_n)
	{
		*str-- = base[u_n % b_len];
		u_n /= b_len;
	}
	if (neg)
		*str = '-';
}

int				get_int(char **str, int n, t_settings s, const char *base)
{
	const unsigned	b_len = ft_strlen(base);
	int				len;
	int				size;

	len = intlen(n, b_len);
	size = ((s.field_width > len) ? s.field_width : len) + 1;
	if (!(*str = malloc(sizeof(**str) * size)))
		return (-1);
	(*str)[size - 1] = '\0';
	if (!s.neg_fw)
	{
		ft_memset(*str, s.padding, size - len - 1);
		write_u(*str + (size - len - 1), n, base, b_len);
	}
	else
	{
		ft_memset(*str + len, s.padding, size - len - 1);
		write_u(*str, n, base, b_len);
	}
	return (size - 1);
}

int				get_uint(char **str, unsigned int n, t_settings s)
{
	int		len;
	int		i;

	len = intlen(n, 10);
	len = (s.field_width > len) ? s.field_width : len;
	if (!(*str = malloc(sizeof(*str) * len)))
		return (-1);
	(*str)[len] = '\0';
	i = len;
	while (n)
	{
		(*str)[--i] = n % 10 + '0';
		n /= 10;
	}
	ft_memset(*str, s.padding, i);
	return (len);
}
