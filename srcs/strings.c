/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strings.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 18:02:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 22:18:32 by chamada     ###    #+. /#+    ###.fr     */
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
	int	len;
	int	padding;

	if (src == NULL)
		src = "(null)";
	len = ft_strlen(src);
	len = (s.precision != -1 && s.precision < len)? s.precision : len;
	padding = (s.field_width > len) ? s.field_width - len : 0;
	len = (s.field_width > len) ? s.field_width : len;
	if (!(*dst = malloc(sizeof(**dst) * (len + 1))))
		return (-1);
	(*dst)[len] = '\0';
	if (!s.neg_fw)
	{
		ft_memset(*dst, ' ', padding);
		ft_memcpy(*dst + padding, src, len - padding);
	}
	else
	{
		ft_memcpy(*dst, src, len - padding);
		ft_memset(*dst + len - padding, ' ', padding);
	}
	return (len);
}
