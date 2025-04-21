
#include "so_long.h"


void	destroy_images(t_game *game)
{	
	mlx_destroy_image(game->mlx, game->img_wall_y);
	mlx_destroy_image(game->mlx, game->img_wall_y_tree);
	mlx_destroy_image(game->mlx, game->img_wall_n_tree);
	mlx_destroy_image(game->mlx, game->img_floor);
	mlx_destroy_image(game->mlx, game->img_player);
	mlx_destroy_image(game->mlx, game->img_player_tree);
	mlx_destroy_image(game->mlx, game->img_exit_y);
	mlx_destroy_image(game->mlx, game->img_exit_y_tree);
	mlx_destroy_image(game->mlx, game->img_exit_n);
	mlx_destroy_image(game->mlx, game->img_exit_n_tree);
	mlx_destroy_image(game->mlx, game->img_coin_y);
	mlx_destroy_image(game->mlx, game->img_coin_y_tree);
	mlx_destroy_image(game->mlx, game->img_coin_n);
	mlx_destroy_image(game->mlx, game->img_coin_n_tree);
}

// <- (3)check_map(map.c), load_image(game.c), main
//		(2)game_init(game.c), check_path(path.c)
void	exit_error(char *str, t_game *game)
{
	ft_printf("Error\n");
	ft_printf(str);
	ft_printf("\n");
	close_game(game);
}

int	close_game(t_game *game)// <- exit_error(), check_collect_exit(player.c)
{
	mlx_destroy_window(game->mlx, game->win);
	destroy_images(game);
	#ifdef __linux__
		mlx_destroy_display(game->mlx);
	#endif
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