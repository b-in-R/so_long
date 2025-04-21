#include "so_long.h"

int	render_frame(t_game *game)
{
	t_draw	d;

	ft_memset(&d, 0, sizeof(t_draw));
	update_player_pos(game, game->player);
	if (game->coin_collected == game->coin_total)
	{
		d.x = game->exit_x;
		d.y = game->exit_y;
		d.px = d.x * TILE_SIZE;
		d.py = d.y * TILE_SIZE;
		draw_exit(game, &d);
	}
	return (0);
}

void	draw_player(t_game *game)
{
	t_player	*p;

	p = game->player;
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		p->px, p->py);
	if (game->map[game->player->y + 1][game->player->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_tree,
			p->px, p->py);
}

void	draw_objs(t_game *game, t_draw *d)
{
	if (game->map[d->y][d->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_y,
			d->px, d->py);
	if (game->map[d->y][d->x] == '1' && d->y < game->height
			&& game->map[d->y + 1][d->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_y_tree,
			d->px, d->py);
	else if (game->map[d->y][d->x] == 'C' && game->map[d->y + 1][d->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_coin_y_tree,
			d->px, d->py);
	else if (game->map[d->y][d->x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img_coin_y,
			d->px, d->py);
	else if (game->map[d->y][d->x] == 'K' && game->map[d->y + 1][d->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_coin_n_tree,
			d->px, d->py);
	else if (game->map[d->y][d->x] == 'K')
		mlx_put_image_to_window(game->mlx, game->win, game->img_coin_n,
			d->px, d->py);
	if (game->map[d->y][d->x] == 'E')
		draw_exit(game, d);
	else if (game->map[d->y][d->x] == '0' && game->map[d->y + 1][d->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_n_tree,
			d->px, d->py);
}

void	draw_floor(t_game *game, t_draw *d)
{
	while (game->map[d->y])
	{
		d->x = 0;
		while (game->map[d->y][d->x])
		{
			d->px = d->x * TILE_SIZE;
			d->py = d->y * TILE_SIZE;
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				d->px, d->py);
			d->x++;
		}
		d->y++;
	}
}

void	draw_map(t_game *game)
{
	t_draw	d;

	ft_memset(&d, 0, sizeof(t_draw));
	draw_floor(game, &d);
	d.y = 0;
	while (game->map[d.y])
	{
		d.x = 0;
		while (game->map[d.y][d.x])
		{
			d.px = d.x * TILE_SIZE;
			d.py = d.y * TILE_SIZE;
			draw_objs(game, &d);
			d.x++;
		}
		d.y++;
	}
	draw_player(game);
}
