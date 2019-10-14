/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strings.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 18:02:06 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/13 18:13:12 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>

void	*ft_memset(void *b, int c, unsigned long len);

char	*get_char(va_list ap, int fw)
{
	const int	size = fw | 2;
	char		*str;

	str = malloc(size);
	ft_memset(str, ' ', size - 1);
	str[size - 1] = va_arg(ap, char);
	return (str);
}
