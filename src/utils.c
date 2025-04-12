
#include "so_long.h"


void	exit_error(char *str, int map_free, t_game *game)
{
	if (map_free)
		free_map(game->map);
	write(2, "Error - ", 8);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	close_game(game);
}

int	close_game(t_game *game)
{
	mlx_destoy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map);
	exit(0);// a voir exit
	return (0);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}