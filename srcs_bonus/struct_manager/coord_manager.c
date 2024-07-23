/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 11:35:37 by bedarenn          #+#    #+#             */
/*   Updated: 2024/07/23 15:20:04 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_coord	set_coord(int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

t_coord_f	set_coord_f(t_float x, t_float y)
{
	t_coord_f	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

t_coord_f	cast_to_coord_f(t_coord pos)
{
	t_coord_f	coord;

	coord.x = pos.x;
	coord.y = pos.y;
	return (coord);
}

t_coord	cast_to_coord(t_coord_f pos)
{
	t_coord	coord;

	coord.x = pos.x;
	coord.y = pos.y;
	return (coord);
}

t_coord_f	sum_coord_f(t_coord_f a, t_coord_f b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}