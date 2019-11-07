/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strings.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 18:02:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 04:03:15 by chamada     ###    #+. /#+    ###.fr     */
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

int			get_str(char **dst, char *src, t_settings s)
{
	int	len_src;
	int	len_dst;
	int	padding;
	int	i;

	if (src == NULL)
		src = "(null)";
	len_src = ft_strlen(src);
	len_dst = (s.precision != -1 && s.precision < len_src) ? s.precision : len_src;
	padding = (s.field_width > len_dst) ? s.field_width - len_dst : 0;
	len_dst = (s.field_width > len_dst) ? s.field_width : len_dst;
	if (!(*dst = malloc(sizeof(**dst) * len_dst + 1)))
		return (-1);
	(*dst)[len_dst] = '\0';
	if (!s.neg_fw)
	{
		ft_memset(*dst, ' ', padding);
		while (*src && padding < len_dst)
			(*dst)[padding++] = *src++;
	}
	else
	{
		i = 0;
		while (*src && i < len_dst - padding)
			(*dst)[i++] = *src++;
		ft_memset(dst[i], ' ', padding);
	}
	return (len_dst);
}
