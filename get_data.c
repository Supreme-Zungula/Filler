/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 13:29:49 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/19 11:42:00 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdlib.h>

void		get_player_number(t_filler *filler)
{
	char	*line;

	line = NULL;
	get_next_line(0, &line);
	if ((*(ft_strchr(line, 'p') + 1)) == '1')
	{
		filler->player.id = 'O';
		filler->enemy.id = 'X';
	}
	else if ((*(ft_strchr(line, 'p') + 1)) == '2')
	{
		filler->player.id = 'X';
		filler->enemy.id = 'O';
	}
	ft_strdel(&line);
}

int			get_map(t_filler *filler)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	filler->map.height = ft_atoi(ft_strchr(line, ' '));
	filler->map.width = ft_atoi(ft_strrchr(line, ' '));
	if (filler->play == 0)
		filler->map.data = (char **)malloc(sizeof(char *) *
				filler->map.height + 1);
	if (filler->map.data == NULL)
		return (0);
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < filler->map.height)
	{
		get_next_line(0, &line);
		filler->map.data[i++] = ft_strdup(&line[4]);
		ft_strdel(&line);
	}
	filler->map.data[i] = NULL;
	return (1);
}

int			get_token(t_filler *filler)
{
	int		i;
	int		size;
	char	*line;

	i = 0;
	line = NULL;
	get_next_line(0, &line);
	filler->token.height = ft_atoi(ft_strchr(line, ' '));
	filler->token.width = ft_atoi(ft_strrchr(line, ' '));
	ft_strdel(&line);
	size = filler->token.height + 1;
	filler->token.data = (char **)malloc(sizeof(char *) * size);
	if (filler->token.data == NULL)
		return (0);
	while (i < filler->token.height)
	{
		get_next_line(0, &line);
		filler->token.data[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	filler->token.data[i] = NULL;
	return (1);
}

void		get_start_pos(t_filler *filler)
{
	int		row_pos;
	int		col_pos;

	row_pos = 0;
	while (row_pos < filler->map.height)
	{
		col_pos = 0;
		while (filler->map.data[row_pos][col_pos])
		{
			if (filler->map.data[row_pos][col_pos] == filler->player.id)
			{
				filler->player.x_start = col_pos;
				filler->player.y_start = row_pos;
			}
			if (filler->map.data[row_pos][col_pos] == filler->enemy.id)
			{
				filler->enemy.x_start = col_pos;
				filler->enemy.y_start = row_pos;
			}
			col_pos++;
		}
		row_pos++;
	}
}

int			get_data(t_filler *filler)
{
	int		ret;

	ret = 0;
	if (get_map(filler))
	{
		get_start_pos(filler);
		if (get_token(filler))
		{
			crop_token_size(&filler->token);
			save_cropped_token(filler);
			ret = 1;
		}
	}
	return (ret);
}
