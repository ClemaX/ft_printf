/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strings.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 18:02:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 15:22:22 by chamada     ###    #+. /#+    ###.fr     */
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
	int	space;
	int	i;

	if (src == NULL)
		src = "(null)";
	len_src = ft_strlen(src);
	len_dst = (s.precision != -1 && s.precision < len_src) ? s.precision : len_src;
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
