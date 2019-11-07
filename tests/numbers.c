/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   numbers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 14:29:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 02:35:25 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	test_int(t_settings s)
{
	int			i;
	int			count;
	int			count_orig;
	char		*str;
	char		*orig;

	i = -42;
	count = get_int(&str, i, s, "0123456789");
	count_orig = asprintf(&orig, "% *d", s.field_width, i);
	printf("%s[%d]\n%s[%d]\n", orig, count_orig, str, count);
	free(str);
	free(orig);
}

void	test_uint(t_settings s)
{
	int			i;
	int			count;
	int			count_orig;
	char		*str;
	char		*orig;

	i = 42;
	count = get_uint(&str, i, s);
	count_orig = asprintf(&orig, "%*u", s.field_width, i);
	printf("%s[%d]\n%s[%d]\n", orig, count_orig, str, count);
	free(str);
	free(orig);
}

void	test_hex(t_settings s)
{
	int			i;
	int			count;
	int			count_orig;
	char		*str;
	char		*orig;

	i = -42;
	count = get_int(&str, i, s, "0123456789abcdef");
	count_orig = asprintf(&orig, "%*x", s.field_width, i);
	printf("%s[%d]\n%s[%d]\n", orig, count_orig, str, count);
	free(str);
	free(orig);
}
