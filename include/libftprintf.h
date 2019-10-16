/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 18:54:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 17:47:02 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

typedef struct  s_settings
{
    int precision;
    int field_width;
}               t_settings;

int			ft_putchar(char c);
int			ft_putnbr(int n);
int			ft_putstr(char *s);

#endif