/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test_printf.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/02 01:49:33 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 15:50:54 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "tests.h"
#include "libftprintf.h"
#include <stdio.h>

void		test_printf(void)
{
	test_printf_basic();
	test_printf_field_width();
	test_printf_precision();
}
