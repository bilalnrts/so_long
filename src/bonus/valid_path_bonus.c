#include "../../inc/so_long_bonus.h"

void	player_loc(t_game *game, t_cpy *cpy)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				cpy->pl_x = x;
				cpy->pl_y = y;
				break ;
			}
			y++;
		}
		x++;
	}
}

void	ft_valid_path(t_cpy *cpy, int pl_x, int pl_y)
{
	if (cpy->map[pl_x][pl_y] != '1')
	{
		if (cpy->map[pl_x][pl_y] != 'E')
		{
			if (cpy->map[pl_x][pl_y] == 'C')
			{
				cpy->collect_c--;
			}
			cpy->map[pl_x][pl_y] = 'X';
			if (cpy->map[pl_x][pl_y + 1] != '1' && cpy->map[pl_x][pl_y + 1] != 'X')
				ft_valid_path(cpy, pl_x, pl_y + 1);
			if (cpy->map[pl_x][pl_y - 1] != '1' && cpy->map[pl_x][pl_y - 1] != 'X')
				ft_valid_path(cpy, pl_x, pl_y - 1);
			if (cpy->map[pl_x - 1][pl_y] != '1' && cpy->map[pl_x - 1][pl_y] != 'X')
				ft_valid_path(cpy, pl_x - 1, pl_y);
			if (cpy->map[pl_x + 1][pl_y] != '1' && cpy->map[pl_x + 1][pl_y] != 'X')
				ft_valid_path(cpy, pl_x + 1, pl_y);
		}
		else
		{
			cpy->correct_exit = 1;
		}
	}
}

void	ft_map_control(t_game *game, t_cpy *cpy)
{
	cpy->collect_c = game->collect;
	cpy->correct_exit = 0;
	player_loc(game, cpy);
	ft_valid_path(cpy, cpy->pl_x, cpy->pl_y);
	if (cpy->collect_c != 0 || cpy->correct_exit != 1)
	{
		ft_printf("There is no a valid path!\n");
		exit(0);
	}
}
