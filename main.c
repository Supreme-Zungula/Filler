/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:43:07 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/20 10:04:47 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "filler.h"

void		initialise_players(t_filler *filler)
{
	filler->player.id = '\0';
	filler->player.x_start = 0;
	filler->player.y_start = 0;
	filler->enemy.id = '\0';
	filler->enemy.x_start = 0;
	filler->enemy.y_start = 0;
}

void		initialise_map_and_token(t_filler *filler)
{
	filler->map.height = 0;
	filler->map.width = 0;
	filler->map.data = NULL;
	filler->token.height = 0;
	filler->token.width = 0;
	filler->token.data = NULL;
	filler->token.crop_y_start = 0;
	filler->token.crop_y_end = 0;
	filler->token.crop_x_start = 0;
	filler->token.crop_y_end = 0;
	filler->cropped.height = 0;
	filler->cropped.width = 0;
	filler->cropped.data = NULL;
	filler->cropped.crop_y_start = 0;
	filler->cropped.crop_y_end = 0;
	filler->cropped.crop_x_start = 0;
	filler->cropped.crop_x_end = 0;
}

void		initialise_filler(t_filler *filler)
{
	initialise_players(filler);
	initialise_map_and_token(filler);
	filler->moves_list = NULL;
	filler->top = 0;
	filler->bottom = 0;
	filler->play = 0;
	filler->left = 0;
	filler->right = 0;
}

void		clean_maps(t_filler *filler)
{
	int		y;

	y = filler->map.height - 1;
	while (y >= 0)
	{
		ft_strdel(&filler->map.data[y]);
		y--;
	}
	free(filler->map.data);
	filler->map.data = NULL;
	y = filler->token.height - 1;
	while (y >= 0)
	{
		ft_strdel(&filler->token.data[y]);
		y--;
	}
	free(filler->token.data);
	filler->token.data = NULL;
}

int			main(void)
{
	t_filler	filler;

	initialise_filler(&filler);
	get_player_number(&filler);
	while (1)
	{
		if (get_data(&filler))
		{
			if (play_function(&filler) == 0)
				break ;
			clean_maps(&filler);
		}
	}
	place_token(0, 0);
	clean_maps(&filler);
	return (0);
}
