/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 21:25:00 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/21 22:39:04 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <line.h>

t_line	*line_add(t_line **line, char *content, int size)
{
	t_line *new;

	if (!content || !size)
		return (NULL);
	new->content = content;
	new->size = size;
	new->next = *line;
	return ((*line = new));
}

t_line	*line_clr(t_line **line)
{
	t_line	*curr;

	while ((curr = *line))
	{
		*line = (*line)->next;
		free(curr->content);
		free(curr);
	}
	return (NULL);
}
