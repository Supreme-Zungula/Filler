/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 02:58:31 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/19 17:18:19 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "filler.h"

int			block_enemy(t_filler *filler)
{
	t_point_list	*best;
	int				offset_x;
	int				offset_y;

	best = NULL;
	offset_x = filler->token.crop_x_start;
	offset_y = filler->token.crop_y_start;
	if (find_points(filler))
	{
		best = find_best_move(filler);
		if (best)
		{
			place_token(best->y - offset_y, best->x - offset_x);
			check_boundaries(filler, best->y, best->x);
			delete_points(filler);
			return (1);
		}
	}
	return (0);
}

int			get_move(t_filler *filler)
{
	t_point_list	*best;
	int				offset_x;
	int				offset_y;

	best = NULL;
	offset_x = filler->token.crop_x_start;
	offset_y = filler->token.crop_y_start;
	if (find_points(filler))
	{
		best = find_best_move(filler);
		if (best)
		{
			place_token(best->y - offset_y, best->x - offset_x);
			delete_points(filler);
			return (1);
		}
	}
	return (0);
}

int			play_function(t_filler *filler)
{
	if (!filler->top && !filler->right)
	{
		return (block_enemy(filler));
	}
	if ((filler->top || filler->right) && !filler->left)
	{
		get_enemy_most_left(filler);
		return (get_move(filler));
	}
	if (filler->bottom && (!filler->right || !filler->left))
	{
		get_enemy_most_left(filler);
		return (get_move(filler));
	}
	else
	{
		get_enemy_most_right(filler);
		return (get_move(filler));
	}
	return (0);
}
