/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binurtas <binurtas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:56:39 by binurtas          #+#    #+#             */
/*   Updated: 2023/04/08 21:05:43 by binurtas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_check_map(char *buffer, t_game *game)
{
	game->map_area = ft_strlen(buffer) - game->map_y;
	if (game->map_area != game->map_x * game->map_y)
	{
		ft_printf("Error!\nThe map has a wrong layout.\n");
		exit(1);
	}
	ft_check_x_limits(game);
	ft_check_y_limits(game);
}

void	ft_check_pce(char *buffer, t_game *game)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'C')
			game->collect++;
		else if (buffer[i] == 'P')
			game->player++;
		else if (buffer[i] == 'E')
			game->exit++;
		else if (buffer[i] == '\n')
			game->map_y++;
		i++;
	}
	if (game->player != 1 || game->exit != 1 || game->collect < 1)
	{
		ft_printf("Error\nIncorrect number of Player, Collectible or Exit.\n");
		exit(1);
	}
}

char	*ft_join(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}

char	*ft_get_map(int fd)
{
	char	buffer;
	char	*line;
	int		rd_bytes;

	rd_bytes = 1;
	line = malloc(1);
	line[0] = '\0';
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, &buffer, 1);
		if ((rd_bytes == 0 && line[0] == '\0') || rd_bytes < 0)
		{
			free(line);
			return (0);
		}
		if (rd_bytes == 0 && line[0] != '\0')
			return (line);
		line = ft_join(line, buffer);
	}
	return (line);
}
