/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   numbers.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/04 14:29:23 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 15:25:58 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	test_int(t_settings sets)
{
	int			i;
	int			count;
	int			count_orig;
	char		*str;
	char		*orig;

	i = 10;
	count = get_int(&str, i, sets, "0123456789");
	count_orig = asprintf(&orig, "% *d", sets.field_width, i);
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

void	test_hex(void)
{
	char		*str;
	int			ret;
	t_settings	s;

	s.field_width = -1;
	s.padding = ' ';
	s.precision = 0;
	ret = get_int(&str, 101, s, "0123456789abcdef");
	printf("%d: %x - %s\n", 101, 101, str);
}
