/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binurtas <binurtas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:56:39 by binurtas          #+#    #+#             */
/*   Updated: 2023/04/08 21:05:12 by binurtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long_bonus.h"

void	ft_limit_error(t_game *game)
{
	ft_printf("Error!\nNot enough trees in the screen limits!");
	free(game);
	exit(1);
}

void	ft_check_x_limits(t_game *game)
{
	while (game->x < game->map_x)
	{
		if (game->map[0][game->x] != '1')
			ft_limit_error(game);
		game->x++;
	}
	game->x = 0;
	while (game->x < game->map_x)
	{
		if (game->map[game->map_y - 1][game->x] != '1')
			ft_limit_error(game);
		game->x++;
	}
}

void	ft_check_y_limits(t_game *game)
{
	while (game->y < game->map_y)
	{
		if (game->map[game->y][0] != '1')
			ft_limit_error(game);
		game->y++;
	}
	game->y = 0;
	while (game->y < game->map_y)
	{
		if (game->map[game->y][game->map_x - 1] != '1')
			ft_limit_error(game);
		game->y++;
	}
}
