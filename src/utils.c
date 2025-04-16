
#include "so_long.h"

// <- (3)check_map(map.c), load_image(game.c), main
//		(2)game_init(game.c), check_path(path.c)
void	exit_error(char *str, int map_free, t_game *game)
{
	if (map_free)
		free_map(game->map);
	ft_printf("Error - ");
	ft_printf(str);
	ft_printf("\n");
	/*
	(void)write(2, "Error - ", 8);
	(void)write(2, str, ft_strlen(str));
	(void)write(2, "\n", 1);
	*/
	close_game(game);
}

int	close_game(t_game *game)// <- exit_error(), check_collect_exit(player.c)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free_map(game->map);
	exit(0);// a voir exit
	return (0);
}

void	free_map(char **map)// <- read_map(map.c)
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