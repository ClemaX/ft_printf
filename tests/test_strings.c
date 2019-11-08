/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_strings.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/30 08:54:47 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 22:14:02 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

static void	test_char(t_settings s)
{
	char	c;
	int		count;
	int		count_orig;
	char	*str;
	char	*orig;

	c = 'c';
	count = get_char(&str, c, s.field_width);
	count_orig = asprintf(&orig, "%*c", s.field_width, c);
	printf("%s[%d]\n%s[%d]\n", orig, count_orig, str, count);
	free(str);
	free(orig);
}

static void	test_str(t_settings s)
{
	char	*src;
	int		count;
	int		count_orig;
	char	*str;
	char	*orig;

	src = ft_strdup("Test");
	count = get_str(&str, src, s);
	count_orig = asprintf(&orig, "%*.*s", s.field_width, s.precision, src);
	printf("%s[%d]\n%s[%d]\n", orig, count_orig, str, count);
	free(str);
	count = get_str(&str, NULL, s);
	count_orig = asprintf(&orig, "%*.*s", s.field_width, s.precision, NULL);
	printf("%s[%d]\n%s[%d]\n", orig, count_orig, str, count);
	free(str);
}

void		test_strings(void)
{
	t_settings s;

	s.field_width = 10;
	s.precision = 20;
	s.padding = ' ';
	test_char(s);
	test_str(s);
}
