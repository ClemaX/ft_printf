/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 21:47:21 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 22:32:44 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <stdarg.h>
#include <specs.h>
#include <line.h>

t_line	*fmt_char();
t_line	*fmt_str();
t_line	*fmt_num();

/*
**	cspdiuxX% | nfge
*/

t_line	*(*format[9]) = {
	fmt_char,
	fmt_str,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_num,
	fmt_char
};
