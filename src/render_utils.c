#include "so_long.h"

void	draw_exit(t_game *game, t_draw *d)
{
	if (game->coin_collected == game->coin_total)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_y,
			d->px, d->py);
		if (game->map[d->y + 1][d->x] == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_exit_y_tree, d->px, d->py);
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_exit_n,
			d->px, d->py);
		if (game->map[d->y + 1][d->x] == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_exit_n_tree, d->px, d->py);
	}
}

void	tile_image_coin(t_game *game, t_draw *d, int y, int x)
{
	if (d->tile == 'C')
	{
		if (y < game->height && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_coin_y_tree,
				d->px, d->py);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_coin_y,
				d->px, d->py);
	}
	else if (d->tile == 'K')
	{
		if (y < game->height && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_coin_n_tree, d->px, d->py);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_coin_n,
				d->px, d->py);
	}
}

void	tile_image_exit_floor(t_game *game, t_draw *d, int y, int x)
{
	if (d->tile == 'E')
	{
		d->x = x;
		d->y = y;
		draw_exit(game, d);
	}
	else if (d->tile == '0')
	{
		if (y < game->height && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_wall_n_tree, d->px, d->py);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				d->px, d->py);
	}
}
