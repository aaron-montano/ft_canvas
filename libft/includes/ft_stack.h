/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:16:20 by amontano          #+#    #+#             */
/*   Updated: 2019/04/09 22:48:21 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H
# include "libft.h"
# include <stdlib.h>

typedef struct		s_stack
{
	struct s_node	*top;
}					t_stack;

t_stack				*stack_init();
void				push(t_stack *stack, void *content);
void				*pop(t_stack *stack);
void				*peek(t_stack *stack);
int					stack_isempty(t_stack *stack);

#endif
