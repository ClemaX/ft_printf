/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_bases.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 09:54:17 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 10:09:15 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	base_len(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i])
	{
		j = i++ + 1;
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		while (base[j])
			if (base[i] == base[++j])
				return (0);
	}
	return (i < 2 ? 0 : i);
}
