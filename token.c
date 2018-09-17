/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 03:30:38 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/19 17:20:58 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

void		crop_token_size(t_token *token)
{
	int		row;
	int		col;

	row = 0;
	while (row < token->height && !ft_strchr(token->data[row], '*'))
		row++;
	token->crop_y_start = row;
	while (row < token->height && ft_strchr(token->data[row], '*'))
		row++;
	token->crop_y_end = --row;
	token->crop_x_start = token->width;
	while (row >= token->crop_y_start)
	{
		col = 0;
		while (token->data[row][col])
		{
			if ((token->data[row][col] == '*') && token->crop_x_start >= col)
				token->crop_x_start = col;
			if ((token->data[row][col] == '*') && token->crop_x_end <= col)
				token->crop_x_end = col;
			col++;
		}
		row--;
	}
}

void		save_cropped_token(t_filler *filler)
{
	int		y;
	int		start;
	int		end;
	int		ty;
	int		height;

	y = 0;
	ty = filler->token.crop_y_start;
	start = filler->token.crop_x_start;
	end = filler->token.crop_x_end + 1;
	height = filler->token.crop_y_end - filler->token.crop_y_start + 1;
	filler->cropped.data = (char **)malloc(sizeof(char *) * height + 1);
	if (filler->cropped.data)
	{
		while (ty <= filler->token.crop_y_end)
		{
			filler->cropped.data[y] = ft_strsub(filler->token.data[ty],
					start, end);
			y++;
			ty++;
		}
		filler->cropped.data[y] = NULL;
	}
}
