/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:32:24 by matde-ol          #+#    #+#             */
/*   Updated: 2024/06/10 13:07:21 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdrs/cub3d.h"

t_fimg	create_wimg(void)
{
	t_fimg	wimg;

	wimg.coord.x = 0;
	wimg.coord.y = 0;
	wimg.img = NULL;
	return (wimg);
}

void	init_wimg(t_info *info)
{
	info->img_no = create_wimg();
	info->img_so = create_wimg();
	info->img_we = create_wimg();
	info->img_ea = create_wimg();
}

void	init_player(t_info *info, int x, int y, long double radiant)
{
	info->base.pos.x = x;
	info->base.pos.y = y;
	info->base.angle = radiant;
	if (info->map != NULL)
		info->map[y][x] = '0';
}

void	init_info(t_info *info)
{
	info->map = NULL;
	init_wimg(info);
	init_player(info, -1, -1, -1);
	info->color_f = -1;
	info->color_c = -1;
}
