/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 11:52:30 by amontano          #+#    #+#             */
/*   Updated: 2019/03/07 11:54:11 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_node	*new_node(void *content)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(t_node));
	if (n)
	{
		n->content = content;
		n->next = NULL;
	}
	return (n);
}
