/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 21:47:21 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 19:03:45 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <libft.h>
#include <specs.h>
#include <line.h>

static t_line	*fmt_char(t_line **line, t_spec spec, va_list ap)
{
	const int	len = (spec.width > 1) ? spec.width : 1;
	char		*content;

	if (!(content = malloc(sizeof(*content) * len)))
		return (NULL);
	ft_memset(content, (spec.flags & ZERO) ? '0' : ' ', len);
	content[spec.flags & MINUS ? 0 : len - 1] = va_arg(ap, int);
	return (line_add(line, content, len));
}

static t_line	*fmt_str(t_line **line, t_spec spec, va_list ap)
{
	const char	*str = va_arg(ap, char*);
	int			strlen;
	int			len;
	char		*content;

	strlen = ft_strlen(str);
	if (spec.precision >= 0 && spec.precision < strlen)
		strlen = spec.precision;
	len = (spec.width > strlen) ? spec.width : strlen;
	if (!(content = malloc(sizeof(*content) * len)))
		return (NULL);
	ft_memset(content, (spec.flags & ZERO) ? '0' : ' ', len);
	ft_memcpy(content + (len - strlen) * (spec.flags & MINUS), str, strlen);
	return (line_add(line, content, len));
}

static t_line	*fmt_int(t_line **line, t_spec spec, va_list ap)
{
	return (NULL);
}

static t_line	*fmt_num(t_line **line, t_spec spec, va_list ap)
{
	return (NULL);
}

/*
**	cspdiuxX% | nfge
*/

t_line			*(*format[9])(t_line **line, t_spec spec, va_list ap) = {
	fmt_char,
	fmt_str,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_char
};
