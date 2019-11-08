/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_printf_precision.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 22:28:11 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 22:43:25 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void	big(void)
{
	const char	*str = "ABCD";
	int			count;
	int			count_orig;

	count = ft_printf("%.10000000s", str);
	printf("[%d]\n", count);
	count_orig = printf("%.10000000s", str);
	printf("[%d]\n", count_orig);
}

static void	wild_card(void)
{
	const char	*str = "ABCD";
	int			count;
	int			count_orig;

	count = ft_printf("%.*s", 2, str);
	printf("[%d]\n", count);
	count_orig = printf("%.*s", 2, str);
	printf("[%d]\n", count_orig);

	count = ft_printf("%.*s", 0, str);
	printf("[%d]\n", count);
	count_orig = printf("%.*s", 0, str);
	printf("[%d]\n", count_orig);
}

static void	zero(void)
{
	const char	*str = "ABCD";
	int			count;
	int			count_orig;

	count = ft_printf("%.0s", str);
	printf("[%d]\n", count);
	count_orig = printf("%.0s", str);
	printf("[%d]\n", count_orig);
}

static void	basic(void)
{
	const char	*str = "ABCD";
	int			count;
	int			count_orig;

	count = ft_printf("%.2s", str);
	printf("[%d]\n", count);
	count_orig = printf("%.2s", str);
	printf("[%d]\n", count_orig);
}

void	test_printf_precision(void)
{
	basic();
	zero();
	wild_card();
	big();
}
