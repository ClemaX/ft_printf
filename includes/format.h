/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 22:02:48 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 19:43:33 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FORMAT_H
# define FORMAT_H

t_line	*(*format[9])(t_line **line, t_spec spec, va_list ap);

#endif