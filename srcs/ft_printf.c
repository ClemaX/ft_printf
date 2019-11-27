/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 18:22:46 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 01:05:55 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <specs.h>
#include <line.h>
#include <format.h>
#include <unistd.h>
#include <stdlib.h>

static int		parse_txt(const char **fmt, t_line **line)
{
	char	*next;

	if ((next = ft_strchr(*fmt, '%')))
	{
		if (next != *fmt)
			if (!line_add(line, ft_substr(*fmt, 0, next - *fmt), next - *fmt))
			{
				line_clr(line);
				return (0);
			}
		*fmt = next + 1;
		return (1);
	}
	if (!line_add(line, ft_strdup(*fmt), ft_strlen(*fmt)))
		line_clr(line);
	return (0);
}

static t_line	*parse_fmt(const char *fmt, va_list ap)
{
	t_spec	spec;
	t_line	*line;

	line = NULL;
	while (parse_txt(&fmt, &line) && *fmt)
	{
		if ((spec = parse_spec(&fmt, ap)).type == ERR)
			return (line_clr(&line));
		else if (spec.type == CNT)
			*(va_arg(ap, int*)) = line_len(line);
		else if (!g_format[spec.type](&line, spec, ap))
			return (line_clr(&line));
	}
	return (line);
}

int				ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_line	*line;
	char	*str;
	int		len;

	va_start(ap, fmt);
	line = parse_fmt(fmt, ap);
	va_end(ap);
	if ((!line || (len = line_put(&str, &line)) < 0))
		return (-1);
	write(1, str, len);
	free(str);
	return (len);
}
