/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strings.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 18:02:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 18:34:58 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

void	*ft_memset(void *b, int c, unsigned long len);

char	*get_char(char c, t_settings settings)
{
	const int	len = settings.field_width | 1;
	char		*str;

	str = malloc(len + 1);
	ft_memset(str, ' ', len);
	str[len] = 0;
	return (str);
}
