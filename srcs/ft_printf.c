/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 18:22:46 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 22:58:00 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <specs.h>
#include <line.h>
#include <format.h>

t_line	*parse_fmt(const char *fmt, va_list ap)
{
	int		len;
	t_spec	spec;
	t_line	*line;
	char	*next;

	line = NULL;
	len = 0;
	while (*fmt)
	{
		if (next = ft_strchr(fmt, '%') && next != fmt)
		{
			len += next - fmt;
			if (!line_add(&line, ft_substr(fmt, 0, next - fmt), next - fmt))
				return (-1);
			fmt = next;
		}
		else
		{
			spec = parse_spec(&fmt, ap);
			next = ft_strchr("cspdiuxX%", spec.type);
			if (!next || !format[next - (fmt - 1)](&line, spec, ap))
				line_clr(&line);
		}
	}
	return (line);
}
