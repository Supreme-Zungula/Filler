/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 11:27:06 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/19 11:12:37 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

int				find_points(t_filler *filler)
{
	int			y;
	int			x;
	int			found;

	y = -1;
	found = 0;
	while (++y < filler->map.height)
	{
		x = -1;
		while (++x < filler->map.width)
		{
			if (token_fits(filler, y, x))
			{
				if (y == 0)
					filler->top = 1;
				if (x == filler->map.width - 1)
					filler->right = 1;
				if (x == 0)
					filler->left = 1;
				push_point(filler, y, x);
				found++;
			}
		}
	}
	return (found);
}

t_point_list	*find_best_move(t_filler *filler)
{
	t_point_list	*best;
	t_point_list	*move;
	int				best_dist;
	int				dist;

	dist = 0;
	best = filler->moves_list;
	move = filler->moves_list;
	best_dist = distance_squared(filler->enemy_x, filler->enemy_y,
			move->x, move->y);
	while (move)
	{
		dist = distance_squared(filler->enemy_x, filler->enemy_y,
				move->x, move->y);
		if (best_dist > dist)
		{
			best = move;
			best_dist = dist;
		}
		move = move->next;
	}
	return (best);
}
