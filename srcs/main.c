/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:28:44 by bedarenn          #+#    #+#             */
/*   Updated: 2024/06/02 16:55:46 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "mlx.h"
#include <stdlib.h>

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
