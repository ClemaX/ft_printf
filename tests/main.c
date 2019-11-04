/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 16:48:35 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/02 01:52:25 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"
#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

int			main(void)
{
	t_settings sets;

	sets.field_width = 10;
	sets.precision = 2;
	sets.padding = ' ';
	test_int(sets);
	test_char(sets);
	test_uint(sets);
	test_str(sets);

	test_printf();
	return (0);
}
