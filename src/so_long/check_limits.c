#include "../../inc/so_long.h"

void	ft_limits_error(void)
{
	ft_printf("Error!\nNot enough walls in the screen limits.\n");
	ft_printf("Please, plant 1 where they are supposed to be.");
	exit(1);
}

void	ft_check_x_limits(t_game *game)
{
	while (game->x < game->map_x)
	{
		if (game->map[0][game->x] != 1)
			ft_limits_error();
		game->x++;
	}
	game->x = 0;
	while (game->x < game->map_x)
	{
		if (game->map[game->map_y - 1][game->x] != 1)
			ft_limits_error();
		game->x++;
	}
}

void	ft_check_y_limits(t_game *game)
{
	while (game->y < game->map_y)
	{
		if (game->map[game->y][0] != 1)
			ft_limits_error();
		game->y++;
	}
	game->y = 0;
	while (game->y < game->map_y)
	{
		if (game->map[game->y][game->map_x - 1] != 1)
			ft_limits_error();
		game->y++;
	}
}
