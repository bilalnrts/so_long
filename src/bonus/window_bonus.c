/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binurtas <binurtas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:56:39 by binurtas          #+#    #+#             */
/*   Updated: 2023/04/08 21:17:17 by binurtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
}

void	ft_fill_floor(t_game *game)
{
	game->y = 0;
	while (game->y < game->map_y)
	{
		game->x = 0;
		while (game->x < game->map_x)
		{
			game->file = mlx_xpm_file_to_image(game->mlx,
					"./img/floor.xpm",
					&game->pxl,
					&game->pxl);
			mlx_put_image_to_window(game->mlx, game->mlx_win, game->file,
				game->pxl * game->x, game->pxl * game->y);
			game->x++;
		}
		game->y++;
	}
}

int	ft_total_collect(t_game *game)
{
	int	i;

	i = 0;
	game->y = 0;
	while (game->y < game->map_y)
	{
		game->x = 0;
		while (game->x < game->map_x)
		{
			if (game->map[game->y][game->x] == 'C')
				i++;
			game->x++;
		}
		game->y++;
	}
	return (i);
}

void	ft_fill_window(t_game *game)
{
	game->collect = ft_total_collect(game);
	ft_fill_floor(game);
	game->y = 0;
	while (game->y < game->map_y)
	{
		game->x = 0;
		while (game->x < game->map_x)
		{
			if (game->map[game->y][game->x] == '1')
				ft_put_limits(game);
			else if (game->map[game->y][game->x] == 'C')
				ft_put_collect(game);
			else if (game->map[game->y][game->x] == 'P')
				ft_put_player(game);
			else if (game->map[game->y][game->x] == 'K')
				ft_put_enemy(game);
			else if (game->map[game->y][game->x] == 'E')
				ft_put_exit(game);
			game->x++;
		}
		game->y++;
	}
	ft_mov_display(game);
}
