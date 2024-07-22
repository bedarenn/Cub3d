/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matde-ol <matde-ol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:36:55 by matde-ol          #+#    #+#             */
/*   Updated: 2024/07/22 11:39:29 by matde-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./hdrs_bonus/cub3d.h"

char	**copy_tab(char **tab)
{
	char	**cpy_tab;
	int		i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	cpy_tab = malloc(sizeof(char *) * (i + 1));
	if (cpy_tab == NULL)
		return (NULL);
	i = 0;
	while (tab[i] != NULL)
	{
		cpy_tab[i] = wati_strdup(tab[i]);
		if (cpy_tab[i] == NULL)
		{
			wati_free_tab(&cpy_tab);
			return (NULL);
		}
		i++;
	}
	cpy_tab[i] = NULL;
	return (cpy_tab);
}
