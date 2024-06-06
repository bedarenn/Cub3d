/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_struct_display.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:26:05 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/06 10:10:05 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W_STRUCT_DISPLAY_H
# define W_STRUCT_DISPLAY_H

# include "w_struct.h"
# include "w_typedef.h"
# include "w_const.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_coord_f
{
	long double	x;
	long double	y;
}	t_coord_f;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_coord	max;
}	t_data;

typedef struct s_mlx
{
	t_wptr	ptr;
	t_wwin	win;
	t_data	i_win;
	t_data	i_map;
}	t_mlx;

#endif // W_STRUCT_DISPLAY_H
