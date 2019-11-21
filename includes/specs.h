/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specs.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 04:45:20 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 18:18:23 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef	SPECS_H
# define SPECS_H

# include <stdarg.h>

# define MINUS	(1 << 0)
# define PLUS	(1 << 1)
# define SPACE	(1 << 2)
# define ZERO	(1 << 3)
# define HASH	(1 << 4)

typedef unsigned char t_flags;
typedef struct	s_spec
{
	t_flags	flags;
	int		width;
	int		precision;
	char	type;
}				t_spec;

t_spec	parse_spec(const char **fmt, va_list ap);

#endif

