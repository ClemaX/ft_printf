/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_printf_field_width.c                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 22:06:09 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 23:00:38 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void	basic(void)
{
	int	count;
	int	count_orig;

	count = ft_printf("%12i", 420);
	printf("[%d]\n", count);
	count_orig = printf("%12i", 420);
	printf("[%d]\n", count_orig);
}

static void	neg(void)
{
	int	count;
	int	count_orig;

	count = ft_printf("%-12i%-12s", 420, "ABC");
	printf("[%d]\n", count);
	count_orig = printf("%-12i%-12s", 420, "ABC");
	printf("[%d]\n", count_orig);
}

static void	padding_zero(void)
{
	int	count;
	int	count_orig;

	count = ft_printf("%010i", 101);
	printf("[%d]\n", count);
	count_orig = printf("%010i", 101);
	printf("[%d]\n", count_orig);
}

static void	wild_card(void)
{
	int	count;
	int	count_orig;

	count = ft_printf("%0*i", 12, 1337);
	printf("[%d]\n", count);
	count_orig = printf("%0*i", 12, 1337);
	printf("[%d]\n", count_orig);

	count = ft_printf("%0*i", -12, 1337);
	printf("[%d]\n", count);
	count_orig = printf("%0*i", -12, 1337);
	printf("[%d]\n", count_orig);

	count = ft_printf("%-*i", 12, 1337);
	printf("[%d]\n", count);
	count_orig = printf("%-*i", 12, 1337);
	printf("[%d]\n", count_orig);

	count = ft_printf("%-*i", -12, 1337);
	printf("[%d]\n", count);
	count_orig = printf("%-*i", -12, 1337);
	printf("[%d]\n", count_orig);
}

void		test_printf_field_width(void)
{
	basic();
	neg();
	padding_zero();
	wild_card();
}
