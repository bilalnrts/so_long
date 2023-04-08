#include "../../inc/so_long_bonus.h"

void	ft_put_enemy(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
		"./img/enemy.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->file, game->x * game->pxl, game->y * game->pxl);
}

void	ft_mov_display(t_game *game)
{
	mlx_string_put(game->mlx, game->mlx_win,
		game->pxl * game->map_x * (0.84), 10, 0x80000,
		"Movements: ");
	mlx_string_put(game->mlx, game->mlx_win,
		game->pxl * game->map_x * (0.95), 10, 0x80000,
		ft_itoa(game->pl_mov));
}

void	ft_enemy(int keyhook, t_game *game)
{
	if ((keyhook == 2 && game->map[game->pl_y][game->pl_x + 1] == 'K')
		|| (keyhook == 1 && game->map[game->pl_y + 1][game->pl_x] == 'K')
		|| (keyhook == 0 && game->map[game->pl_y][game->pl_x - 1] == 'K')
		|| (keyhook == 13 && game->map[game->pl_y -1][game->pl_x] == 'K'))
	{
		ft_printf("You can't beat enemy!\n");
		ft_close_window(game);
	}
}
