/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: chamada <chamada@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/21 21:25:00 by chamada      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 17:11:20 by chamada     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <libft.h>
#include <line.h>
#include <stdlib.h>

t_line	*line_add(t_line **line, char *content, int size)
{
	t_line *new;

	if (!content || !size || !(new = malloc(sizeof(t_line))))
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

int		line_len(t_line	*line)
{
	t_line	*curr;
	int		len;

	len = 0;
	curr = line;
	while (curr)
	{
		len += curr->size;
		curr = curr->next;
	}
	return (len);
}

int		line_put(char **dest, t_line **line)
{
	const int	len = line_len(*line);
	t_line		*curr;

	if (!(*dest = malloc(sizeof(char) * (len + 1))))
	{
		line_clr(line);
		return (-1);
	}
	*dest += len;
	**dest = '\0';
	curr = *line;
	while (curr)
	{
		*dest -= curr->size;
		ft_memcpy(*dest, curr->content, curr->size);
		curr = curr->next;
	}
	line_clr(line);
	return (len);
}