/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/02 01:49:33 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 14:28:57 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	test_printf(void)
{
	int	count;
	int	count_orig;

	count = ft_printf("Hello %s, %d %c", "World", 42, '\n');
	count_orig = printf("Hello %s, %d %c", "World", 42, '\n');
	printf("[%d, %d]\n", count, count_orig);

	count = ft_printf("Hello %s, %d %c", "", 0, '\n');
	count_orig = printf("Hello %s, %d %c", "", 0, '\n');
	printf("[%d, %d]\n", count, count_orig);
}
