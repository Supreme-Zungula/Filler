/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:46:11 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/19 16:23:30 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"

typedef	struct			s_point_list
{
	int					x;
	int					y;
	struct s_point_list	*next;
}						t_point_list;

typedef struct			s_map
{
	int					height;
	int					width;
	char				**data;
}						t_map;

typedef struct			s_token
{
	int					height;
	int					width;
	int					crop_y_start;
	int					crop_x_start;
	int					crop_y_end;
	int					crop_x_end;
	char				**data;
}						t_token;

typedef	struct			s_player
{
	char				id;
	int					x_start;
	int					y_start;
}						t_player;

typedef struct			s_filler
{
	t_map				map;
	t_token				token;
	t_player			player;
	t_player			enemy;
	t_point_list		*moves_list;
	t_token				cropped;
	int					enemy_x;
	int					enemy_y;
	int					top;
	int					bottom;
	int					right;
	int					left;
	int					play;
}						t_filler;

void					initialise_filler(t_filler *filler);

int						get_data(t_filler *filler);
void					get_player_number(t_filler *filler);
int						get_map(t_filler *filler);
int						get_token(t_filler *filler);
void					get_start_pos(t_filler *filler);
void					save_cropped_token(t_filler *filler);
void					get_enemy_closest(t_filler *filler);
void					get_enemy_most_left(t_filler *filler);
void					get_enemy_most_right(t_filler *filler);

void					crop_token_size(t_token *token);
void					check_boundaries(t_filler *filler, int y, int x);
int						valid_move(t_filler *filler, int row, int col);
int						token_fits(t_filler *filler, int y, int x);
void					place_token(int y, int x);
int						distance_squared(int x1, int y1, int x2, int y2);
int						power(int base, int exp);

void					push_point(t_filler *filler, int y, int x);
void					delete_points(t_filler *filler);

int						play_function(t_filler *filler);
int						find_points(t_filler *filler);
t_point_list			*find_best_move(t_filler *filler);
void					clean_maps(t_filler *filler);
#endif
