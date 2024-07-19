/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wati_isupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:11:19 by bedarenn          #+#    #+#             */
/*   Updated: 2024/01/21 15:39:45 by bedarenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libwati.h>

int	wati_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
