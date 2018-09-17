/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seeking_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 03:25:59 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/19 16:03:59 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_enemy_closest(t_filler *filler)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	if (filler->player.y_start < filler->enemy.y_start)
	{
		while (!ft_strchr(filler->map.data[y], filler->enemy.id))
			y++;
		while (filler->map.data[y][x] != filler->enemy.id)
			x++;
		filler->enemy_x = x;
		filler->enemy_y = y;
	}
	if (filler->player.y_start > filler->enemy.y_start)
	{
		y = filler->map.height - 1;
		while (!ft_strchr(filler->map.data[y], filler->enemy.id))
			y--;
		while (filler->map.data[y][x] != filler->enemy.id)
			x++;
		filler->enemy_x = x;
		filler->enemy_y = y;
	}
}

void		get_enemy_most_left(t_filler *filler)
{
	int		y;
	int		x;

	y = 0;
	while (y < filler->map.height)
	{
		x = 0;
		while (x < filler->map.width)
		{
			if (filler->map.data[y][x] == filler->enemy.id &&
					filler->enemy_x >= x)
			{
				filler->enemy_x = x;
				filler->enemy_y = y;
			}
			x++;
		}
		y++;
	}
}

void		get_enemy_most_right(t_filler *filler)
{
	int		x;
	int		y;

	y = 0;
	while (y < filler->map.height)
	{
		x = 0;
		while (x < filler->map.width)
		{
			if (filler->map.data[y][x] == filler->enemy.id &&
					filler->enemy_x <= x)
			{
				filler->enemy_x = x;
				filler->enemy_y = y;
			}
			x++;
		}
		y++;
	}
}
