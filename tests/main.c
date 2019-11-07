/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 16:48:35 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/04 15:57:43 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"
#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

int			main(void)
{
	t_settings s;

	s.field_width = 10;
	s.precision = 20;
	s.padding = ' ';
	test_int(s);
	test_uint(s);
	test_hex(s);
	test_char(s);
	test_str(s);

	test_printf();
	return (0);
}
