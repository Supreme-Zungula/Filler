/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 15:40:51 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/19 17:58:15 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

int			token_fits(t_filler *filler, int y, int x)
{
	int		tx;
	int		ty;
	int		touches;

	touches = 0;
	ty = -1;
	while (filler->cropped.data[++ty] && filler->map.data[y + ty])
	{
		tx = -1;
		while (filler->map.data[y][x + (++tx)] && filler->cropped.data[ty][tx])
		{
			if (filler->cropped.data[ty][tx] == '*')
			{
				if (filler->map.data[y + ty][x + tx] == filler->player.id)
					touches++;
				if (filler->map.data[y + ty][x + tx] == filler->enemy.id)
					return (0);
			}
		}
		if (!filler->map.data[y][x + tx] && filler->cropped.data[ty][tx])
			return (0);
	}
	if (!filler->map.data[y + ty] && filler->cropped.data[ty])
		return (0);
	return (touches == 1 ? 1 : 0);
}

void		place_token(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void		check_boundaries(t_filler *filler, int y, int x)
{
	if (y == 0)
		filler->top = 1;
	if (y == filler->map.height - 1)
		filler->bottom = 1;
	if (x == filler->map.width - 1)
		filler->right = 1;
	if (x == 0)
		filler->left = 1;
}
