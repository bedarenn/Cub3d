/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wkey_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:32:38 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/07 13:55:24 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "cub3d.h"
#include "mlx.h"

void	wkey_init_hook(t_joe_mama *var)
{
	mlx_hook(var->mlx.win, 17, 1L << 17, mlx_loop_end, var->mlx.ptr);
	mlx_hook(var->mlx.win, 02, 1L << 0, wkey_hook_press, var);
	mlx_hook(var->mlx.win, 03, 1L << 1, wkey_hook_release, var);
	mlx_loop_hook(var->mlx.ptr, wmlx_loop, var);
}

int	wkey_hook_press(int keycode, t_joe_mama *var)
{
	if (keycode == KEY_ESC)
		mlx_loop_end(var->mlx.ptr);
	else if (keycode == KEY_W)
		var->press.key_W = true;
	else if (keycode == KEY_A)
		var->press.key_A = true;
	else if (keycode == KEY_S)
		var->press.key_S = true;
	else if (keycode == KEY_D)
		var->press.key_D = true;
	else if (keycode == KEY_TAB)
	{
		if (var->mode == MODE_MAIN)
			var->mode = MODE_MINIMAP;
		else if (var->mode == MODE_MINIMAP)
			var->mode = MODE_MAIN;
		wmlx_loop_draw(var);
		wmlx_update_win(var->mlx);
	}
	else
		wati_fprintf(2, "key: %i\n", keycode);
	return (0);
}

int	wkey_hook_release(int keycode, t_joe_mama *var)
{
	if (keycode == KEY_W)
		var->press.key_W = false;
	else if (keycode == KEY_A)
		var->press.key_A = false;
	else if (keycode == KEY_S)
		var->press.key_S = false;
	else if (keycode == KEY_D)
		var->press.key_D = false;
	return (0);
}
