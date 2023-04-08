/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binurtas <binurtas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:56:39 by binurtas          #+#    #+#             */
/*   Updated: 2023/04/08 21:24:46 by binurtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_init_struct(t_game *game)
{
	game->map_x = 0;
	game->map_y = 0;
	game->map_area = 0;
	game->x = 0;
	game->y = 0;
	game->pxl = 0;
	game->player = 0;
	game->pl_mov = 0;
	game->pl_dir = "./img/down.xpm";
	game->collect = 0;
	game->exit = 0;
}

void	ft_window(t_game *game)
{
	game->pxl = 50;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->pxl * game->map_x,
			game->pxl * game->map_y,
			"PokeMario");
	ft_fill_window(game);
}

void	ft_validate_map(char **av, t_game *game)
{
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error!\nThe map could not be read.\n");
		exit(1);
	}
	buffer = ft_get_map(fd);
	ft_check_pce(buffer, game);
	game->map = ft_split(buffer, '\n');
	while (game->map[0][i])
	{
		game->map_x++;
		i++;
	}
	ft_check_map(buffer, game);
	close(fd);
}

void	ft_check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Error\nInvalid number of arguments. Must be 2.\n");
		exit(0);
	}
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	{
		ft_printf("Error\nInvalid file type. Must be \"<name>.ber\"\n");
		exit(0);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_check_arg(ac, av);
	ft_init_struct(&game);
	ft_validate_map(av, &game);
	ft_window(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, ft_keyboard, &game);
	mlx_hook(game.mlx_win, 17, 1L << 5, ft_close_window, &game);
	mlx_loop(game.mlx);
	exit(0);
	return (0);
}
