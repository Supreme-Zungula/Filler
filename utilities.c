/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 10:54:12 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/19 16:13:57 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "filler.h"

void		push_point(t_filler *filler, int y, int x)
{
	t_point_list	*point;

	point = (t_point_list*)malloc(sizeof(t_point_list));
	if (point)
	{
		point->x = x;
		point->y = y;
		point->next = filler->moves_list;
		filler->moves_list = point;
	}
}

void		delete_points(t_filler *filler)
{
	t_point_list *point;

	point = NULL;
	while (filler->moves_list)
	{
		point = filler->moves_list;
		filler->moves_list = filler->moves_list->next;
		point->next = NULL;
		free(point);
	}
}

int			power(int base, int exp)
{
	int		result;

	result = 1;
	if (exp == 0)
		return (result);
	while (exp >= 1)
	{
		result *= base;
		exp--;
	}
	return (result);
}

int			distance_squared(int x1, int y1, int x2, int y2)
{
	int		x;
	int		y;

	x = power(x2 - x1, 2);
	y = power(y2 - y1, 2);
	return (x + y);
}
