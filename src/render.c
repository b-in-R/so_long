
#include "so_long.h"

int	render_frame(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	return (0);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (game->map[++y])
	{
		x = 1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall, x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, x * TILE_SIZE, y * TILE_SIZE);
			
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img_player, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_coin, x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit, x * TILE_SIZE, y * TILE_SIZE);

		}
	}
}