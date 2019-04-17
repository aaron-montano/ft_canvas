/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:36:06 by amontano          #+#    #+#             */
/*   Updated: 2019/04/09 22:51:04 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# include "libft.h"
# include <stdlib.h>

typedef struct	s_queue
{
	struct s_node		*first;
	struct s_node		*last;
}				t_queue;

t_queue			*queue_init(void);
void			enqueue(t_queue *queue, void *content);
void			*dequeue(t_queue *queue);
void			*queue_peek(t_queue *queue);
int				queue_isempty(t_queue *queue);

#endif
