/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binurtas <binurtas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:56:39 by binurtas          #+#    #+#             */
/*   Updated: 2023/04/08 21:29:36 by binurtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_put_limits(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./img/tree.xpm",
			&game->pxl,
			&game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->file,
		game->pxl * game->x, game->pxl * game->y);
}

void	ft_put_floor(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./img/floor.xpm",
			&game->pxl,
			&game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->file,
		game->pxl * game->x, game->pxl * game->y);
}

void	ft_put_collect(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./img/pokeball.xpm",
			&game->pxl,
			&game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->file,
		game->pxl * game->x, game->pxl * game->y);
}

void	ft_put_player(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			game->pl_dir,
			&game->pxl,
			&game->pxl);
	game->pl_y = game->y;
	game->pl_x = game->x;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->file,
		game->pxl * game->x, game->pxl * game->y);
}

void	ft_put_exit(t_game *game)
{
	if (game->collect == 0)
		game->file = mlx_xpm_file_to_image(game->mlx,
				"./img/exit_open.xpm",
				&game->pxl,
				&game->pxl);
	else
		game->file = mlx_xpm_file_to_image(game->mlx,
				"./img/exit_closed.xpm",
				&game->pxl,
				&game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->file,
		game->pxl * game->x, game->pxl * game->y);
}
