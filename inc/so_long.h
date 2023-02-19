#ifndef SO_LONG_H
# define SO_LONG_H

#include <fcntl.h>

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

} t_game;

//so_long
void	ft_check_arg(int ac, char **av);
void	ft_validate_map(char **av, t_game *game);
void	ft_init_struct(t_game *game);
//map_validation
int		ft_check(char *line);
char	*ft_get_map(int fd);
void	ft_check_pce(char *buffer, t_game *game);

# endif
