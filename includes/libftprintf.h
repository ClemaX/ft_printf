/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libftprintf.h                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 18:54:08 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/07 03:25:21 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct	s_settings
{
	int		precision;
	int		field_width;
	int		neg_fw;
	char	padding;
}				t_settings;

int				ft_printf(const char *format, ...)
	__attribute__ ((format (printf, 1, 2)));
int				get_char(char **str, char c, int fw);
int				get_int(char **str, int n, t_settings s, const char *base);
int				get_uint(char **str, unsigned int n, t_settings s);
int				get_str(char **dst, char *src, t_settings s);
int				base_len(const char *base);

#endif
