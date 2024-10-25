/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 09:44:11 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/26 11:37:10 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

bool	maps_params_accepted(char c)
{
	if (c == '0' || c == '1' || c == ' ' || c == 'N' || c == 'W' || c == 'S'
		|| c == 'E')
		return (true);
	return (false);
}

static bool	is_player(int x, int y, char c, t_info *info)
{
	if (maps_params_accepted(c) == true)
	{
		if (info->base.angle != -1 && wati_isalpha(c) != 0)
		{
			wati_fprintf(2, "Too many characters\nError\n");
			return (false);
		}
		if (c == 'N' && info->base.angle == -1)
			init_player(info, x, y, M_PI_2);
		else if (c == 'W' && info->base.angle == -1)
			init_player(info, x, y, M_PI);
		else if (c == 'S' && info->base.angle == -1)
			init_player(info, x, y, -M_PI_2);
		else if (c == 'E' && info->base.angle == -1)
			init_player(info, x, y, 0);
		return (true);
	}
	wati_fprintf(2, "Bad parameter for this map\nError\n");
	return (false);
}

static bool	check_line_map(t_info *info, int j)
{
	int	i;

	i = 0;
	while (info->map.map[j][i] != '\0')
	{
		if (is_player(i, j, info->map.map[j][i], info) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	map_checker(t_info *info)
{
	int		j;

	j = 0;
	while (info->map.map[j] != NULL)
	{
		if (check_line_map(info, j) == false)
			return (false);
		j++;
	}
	if (info->base.angle == -1)
	{
		wati_fprintf(2, "Please add one character\nError\n");
		return (false);
	}
	if (map_close(info->map.map) == false)
		return (false);
	info->map.size = map_coord(info->map);
	return (true);
}
