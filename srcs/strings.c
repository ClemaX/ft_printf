/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strings.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 18:02:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 09:12:55 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdlib.h>

int			get_char(char **str, char c, int fw)
{
	const int	len = (fw > 0) ? fw : 1;

	if (!(*str = malloc(sizeof(*str) * len + 1)))
		return (-1);
	ft_memset(*str, ' ', len - 1);
	(*str)[len - 1] = c;
	(*str)[len] = 0;
	return (len);
}

static int	uintlen(unsigned int n)
{
	int len;

	len = 1;
	while (n /= 10)
		len++;
	return (len);
}

int			get_int(char **str, int n, t_settings s)
{
	unsigned int	u_n;
	char			neg;
	int				len;
	int				i;

	neg = (n < 0);
	u_n = (neg) ? -n : n;
	len = uintlen(u_n) + neg;
	len = (s.field_width > len) ? s.field_width : len;
	if (!(*str = malloc(sizeof(*str) * len)))
		return (-1);
	(*str)[len] = '\0';
	i = len;
	while (u_n)
	{
		(*str)[--i] = u_n % 10 + '0';
		u_n /= 10;
	}
	if (neg)
		(*str)[--i] = '-';
	while (i--)
		(*str)[i] = s.padding;
	return (len);
}

int			get_uint(char **str, unsigned int n, t_settings s)
{
	int				len;
	int				i;

	len = uintlen(n);
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

int			get_str(char **dst, char *src, t_settings s)
{
	const int	len_src = ft_strlen(src);
	int			len_dst;
	int			space;
	int			i;

	len_dst = (s.precision < len_src) ? s.precision : len_src;
	space = (s.field_width > len_dst) ? s.field_width - len_dst : 0;
	len_dst = (s.field_width > len_dst) ? s.field_width : len_dst;
	if (!(*dst = malloc(sizeof(**dst) * len_dst + 1)))
		return (-1);
	(*dst)[len_dst] = '\0';
	i = 0;
	while (i < space)
		(*dst)[i++] = ' ';
	while (*src && i < len_dst)
		(*dst)[i++] = *src++;
	return (len_dst);
}

int			get_hex(char **str, int n, t_settings s)
{
	(void)str;
	(void)n;
	(void)s;
	return (0);
}
