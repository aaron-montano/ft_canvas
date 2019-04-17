/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:21:34 by amontano          #+#    #+#             */
/*   Updated: 2019/04/07 00:03:31 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_stack.h"

t_stack				*stack_init(void)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new)
		new->top = NULL;
	return (new);
}

void				push(t_stack *stack, void *content)
{
	t_node	*n;

	if (stack)
	{
		n = new_node(content);
		if (n)
		{
			n->next = stack->top;
			stack->top = n;
		}
	}
}

void				*pop(t_stack *stack)
{
	t_node	*tmp;
	void	*ret;

	if (stack->top)
	{
		ret = stack->top->content;
		stack->top->content = NULL;
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	else
		return (NULL);
	return (ret);
}

void				*peek(t_stack *stack)
{
	if (stack->top)
		return (stack->top->content);
	return (NULL);
}

int					stack_isempty(t_stack *stack)
{
	return (!stack->top);
}
