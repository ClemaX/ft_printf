/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_numbers.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 09:49:01 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 04:33:52 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

static int	uintlen(unsigned int n, int base)
{
	int len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

/*
**TODO: Implement '-'
*/

int			get_int(char **str, int n, t_settings s, const char *base)
{
	const unsigned int	b_len = ft_strlen(base);
	unsigned int		u_n;
	int					len;
	int					i;

	u_n = (n < 0 && b_len != 16) ? -n : n;
	len = uintlen(u_n, b_len) + (n < 0 && b_len != 16);
	len = (s.field_width > len) ? s.field_width : len;
	if (!(*str = malloc(sizeof(*str) * (len + 1))))
		return (-1);
	(*str)[len] = '\0';
	i = len;
	if (n == 0)
		(*str)[--i] = '0';
	while (u_n)
	{
		(*str)[--i] = base[u_n % b_len];
		u_n /= b_len;
	}
	if (n < 0 && b_len != 16)
		(*str)[--i] = '-';
	ft_memset(*str, s.padding, i);
	return (len);
}

int			get_uint(char **str, unsigned int n, t_settings s)
{
	int				len;
	int				i;

	len = uintlen(n, 10);
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
