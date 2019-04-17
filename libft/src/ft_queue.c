/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:19:46 by amontano          #+#    #+#             */
/*   Updated: 2019/04/14 20:36:47 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_queue	*queue_init(void)
{
	t_queue	*new;

	if ((new = (t_queue *)malloc(sizeof(t_queue))))
	{
		new->first = NULL;
		new->last = NULL;
	}
	return (new);
}

void	enqueue(t_queue *queue, void *content)
{
	t_node *node;

	if ((node = new_node(content)))
	{
		if (!queue->first)
			queue->first = node;
		else if (queue->last)
		{
			queue->last->next = node;
			queue->last = node;
		}
		else
		{
			queue->first->next = node;
			queue->last = node;
		}
	}
}

void	*dequeue(t_queue *queue)
{
	void	*ret;
	t_node	*tmp;

	if (queue->first)
	{
		ret = queue->first->content;
		tmp = queue->first;
		if (queue->first->next == queue->last)
			queue->last = NULL;
		queue->first = queue->first->next;
		free(tmp);
		return (ret);
	}
	return (NULL);
}

void	*queue_peek(t_queue *queue)
{
	if (queue->first)
		return (queue->first->content);
	return (NULL);
}

int		queue_isempty(t_queue *queue)
{
	return (!queue->first && !queue->last);
}
