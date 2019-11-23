/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specs.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 04:45:20 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 19:29:17 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef	SPECS_H
# define SPECS_H

# include <stdarg.h>

# define FLAGS		"-+ 0#"

# define MINUS		(1 << 0)
# define PLUS		(1 << 1)
# define SPACE		(1 << 2)
# define ZERO		(1 << 3)
# define HASH		(1 << 4)

# define TYPES		"cs%pdiuxX"

typedef unsigned char t_flags;

typedef enum	e_type
{
	CHAR, STR, PCNT, PTR, DEC, INT, UINT, LHEX, UHEX
}				t_type;

typedef enum	e_numsize
{
	S_DEF, S_L, S_LL, S_H, S_HH
}				t_numsize;

typedef struct	s_spec
{
	t_flags	flags;
	int			width;
	int			precision;
	t_type		type;
	t_numsize	size;
	va_list		ap;
}				t_spec;

t_spec	parse_spec(const char **fmt, va_list ap);

#endif

