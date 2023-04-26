/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binurtas <binurtas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:56:39 by binurtas          #+#    #+#             */
/*   Updated: 2023/04/26 19:36:49 by binurtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/inc/libft.h"
# include "../lib/libft/inc/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	*file;
	int		map_x;
	int		map_y;
	int		map_area;
	int		x;
	int		y;
	int		pxl;
	int		player;
	int		pl_x;
	int		pl_y;
	int		pl_mov;
	char	*pl_dir;
	int		collect;
	int		exit;
}			t_game;

typedef struct s_cpy
{
	char	**map;
	int		pl_x;
	int		pl_y;
	int		collect_c;
	int		correct_exit;
}			t_cpy;

//so_long
void	ft_check_arg(int ac, char **av);
void	ft_validate_map(char **av, t_game *game, t_cpy *cpy);
void	ft_init_struct(t_game *game);
//map_validation
char	*ft_get_map(int fd);
void	ft_check_pce(char *buffer, t_game *game);
void	ft_check_map(char *buffer, t_game *game);
char	*ft_join(char *line, char c);
//check_limits
void	ft_limits_error(t_game *game);
void	ft_check_x_limits(t_game *game);
void	ft_check_y_limits(t_game *game);
//window
void	ft_fill_window(t_game *game);
void	ft_fill_floor(t_game *game);
int		ft_total_collect(t_game *game);
int		ft_close_window(t_game *game);
//window_fill
void	ft_put_exit(t_game *game);
void	ft_put_player(t_game *game);
void	ft_put_collect(t_game *game);
void	ft_put_floor(t_game *game);
void	ft_put_limits(t_game *game);
//keyhook
int		ft_keyboard(int keyhook, t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_up(t_game *game);
//bonus
void	ft_put_enemy(t_game *game);
void	ft_mov_display(t_game *game);
void	ft_enemy(int keyhook, t_game *game);

void	ft_map_control(t_game *game, t_cpy *cpy);

#endif
