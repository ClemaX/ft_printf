/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/02 01:49:33 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 04:04:37 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	test_printf(void)
{
	int	count;
	int	count_orig;

	count = ft_printf("Hello %s, %d %x %X %c", "World", 42, 42, 42, 'c');
	printf("[%d]\n", count);
	count_orig = printf("Hello %s, %d %x %X %c", "World", 42, 42, 42, 'c');
	printf("[%d]\n", count_orig);

	count = ft_printf("Hello %s, %d %x %X %c", "", 0, 0, 0, 0);
	printf("[%d]\n", count);
	count_orig = printf("Hello %s, %d %x %X %c", "", 0, 0, 0, 0);
	printf("[%d]\n", count_orig);

	count = ft_printf("%010i", 101);
	printf("[%d]\n", count);
	count_orig = printf("%010i", 101);
	printf("[%d]\n", count_orig);

	count = ft_printf("% 12i", 420);
	printf("[%d]\n", count);
	count_orig = printf("% 12i", 420);
	printf("[%d]\n", count_orig);

	count = ft_printf("%-12i", 420);
	printf("[%d]\n", count);
	count_orig = printf("%-12i", 420);
	printf("[%d]\n", count_orig);
}
