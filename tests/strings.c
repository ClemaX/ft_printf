/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   strings.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 08:54:47 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/30 09:05:39 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

void	test_int(t_settings sets)
{
	int			i;
	int			count;
	int			count_orig;
	char		*str;
	char		*orig;

	i = 10;
	count = get_int(&str, i, sets);
	count_orig = asprintf(&orig, "% *d", sets.field_width, i);
	printf("%s[%d]\n%s[%d]\n", orig, count_orig, str, count);
	free(str);
	free(orig);
}

void	test_char(t_settings sets)
{
	char		c;
	int			count;
	int			count_orig;
	char		*str;
	char		*orig;

	c = 'c';
	count = get_char(&str, c, sets.field_width);
	count_orig = asprintf(&orig, "%*c", sets.field_width, c);
	printf("%s[%d]\n%s[%d]\n", orig, count_orig, str, count);
	free(str);
	free(orig);
}

void	test_uint(t_settings sets)
{
	int			i;
	int			count;
	int			count_orig;
	char		*str;
	char		*orig;

	i = 42;
	count = get_uint(&str, i, sets);
	count_orig = asprintf(&orig, "%*u", sets.field_width, i);
	printf("%s[%d]\n%s[%d]\n", orig, count_orig, str, count);
	free(str);
	free(orig);
}

void	test_str(t_settings sets)
{
	char		*s;
	int			count;
	int			count_orig;
	char		*str;
	char		*orig;

	s = ft_strdup("Test");
	count = get_str(&str, NULL, sets);
	count_orig = asprintf(&orig, "%*.*s", sets.field_width, sets.precision, NULL);
	printf("%s[%d]\n%s[%d]\n", orig, count_orig, str, count);
	free(str);
}
