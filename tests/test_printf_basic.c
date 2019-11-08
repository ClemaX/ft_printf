/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_printf_basic.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/07 22:03:07 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 22:12:51 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void	basic(void)
{
	int count;
	int count_orig;

	count = ft_printf("Hello %s, %d %x %X %c", "World", 42, 42, 42, 'c');
	printf("[%d]\n", count);
	count_orig = printf("Hello %s, %d %x %X %c", "World", 42, 42, 42, 'c');
	printf("[%d]\n", count_orig);
}

static void	null(void)
{
	int count;
	int count_orig;

	count = ft_printf("Hello %s, %d %x %X %c", "", 0, 0, 0, 0);
	printf("[%d]\n", count);
	count_orig = printf("Hello %s, %d %x %X %c", "", 0, 0, 0, 0);
	printf("[%d]\n", count_orig);
}

void		test_printf_basic(void)
{
	basic();
	null();
}
