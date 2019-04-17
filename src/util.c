/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amontano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 20:02:56 by amontano          #+#    #+#             */
/*   Updated: 2019/04/14 20:03:11 by amontano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas.h"

t_point	*new_point(int x, int y)
{
	t_point *new;

	if ((new = (t_point *)malloc(sizeof(t_point))))
	{
		new->x = x;
		new->y = y;
	}
	return (new);
}
