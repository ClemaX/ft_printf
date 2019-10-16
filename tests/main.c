/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 16:48:35 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 19:40:15 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int	ft_printf(const char *format, ...);

static void test_onlychars(void)
{
	ft_printf("WOW!\nIT WORKS!\n");
}

#include <stdio.h>

int			main()
{
	printf("%10c", 'a');
	test_onlychars();
	return (0);
}
