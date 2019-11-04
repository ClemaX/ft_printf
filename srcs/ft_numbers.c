/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_numbers.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 09:49:01 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 10:49:31 by chamada     ###    #+. /#+    ###.fr     */
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

int			get_int(char **str, int n, t_settings s, const char *base)
{
	const int		b_len = base_len(base);
	unsigned int	u_n;
	char			neg;
	int				len;
	int				i;

	neg = (n < 0);
	u_n = (neg) ? -n : n;
	len = uintlen(u_n, b_len) + neg;
	len = (s.field_width > len) ? s.field_width : len;
	if (!(*str = malloc(sizeof(*str) * len)))
		return (-1);
	(*str)[len] = '\0';
	i = len;
	while (u_n)
	{
		(*str)[--i] = base[n % b_len];
		u_n /= b_len;
	}
	if (neg)
		(*str)[--i] = '-';
	while (i--)
		(*str)[i] = s.padding;
	return (len);
}

int			get_uint(char **str, unsigned int n, t_settings s)
{
	int	len;
	int	i;

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
	while (i--)
		(*str)[i] = s.padding;
	return (len);
}

int			main(void)
{
	char		*str;
	t_settings	s;

	s.field_width = -1;
	s.padding = ' ';
	s.precision = 0;
	str = get_int(&str, 101, s, "0123456789abcdef");
	printf("%d: %x - %s\n", 101, 101, str);
	return (0);
}
