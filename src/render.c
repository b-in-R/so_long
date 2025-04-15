
#include "so_long.h"


void	exit_anim(t_game *game)
{
	if (!game->ex_anim_start && game->coin_collected == game->coin_total)
	{
		game->ex_anim_start = 1;
		game->ex_anim_frame = 0;
		game->ex_anim_timer = 0;
	}
	if (game->ex_anim_start && game->ex_anim_frame < 5)
	{
		game->ex_anim_timer++;
		if (game->ex_anim_timer >= 100)
		{
			game->ex_anim_timer = 0;
			game->ex_anim_frame++;
		}
	}
}

int	render_frame(t_game *game)
{
	update_player_pos(game, game->player);
	exit_anim(game);
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	return (0);
}

/*****************************************************************************/

void	draw_player(t_game *game)
{
	t_player	*p;
	
	p = game->player;
	mlx_put_image_to_window(game->mlx, game->win, game->img_player,
		p->px + game->offset_x, p->py + game->offset_y);
	if (game->map[game->player->y + 1][game->player->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img_player_tree,
			p->px + game->offset_x, p->py + game->offset_y);
}

void	draw_exit(t_game *game, t_draw *d)
{
	if (game->ex_anim_start && game->ex_anim_frame < 5)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit_build[game->ex_anim_frame], d->px, d->py);
		if (game->map[d->y + 1][d->x] == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_exit_build_tree[game->ex_anim_frame], d->px, d->py);
	}
	else if (game->coin_collected == game->coin_total)
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

/*****************************************************************************/

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
	d->y = 0;
	while (game->map[d->y])
	{
		d->x = 0;
		while (game->map[d->y][d->x])
		{
			d->px = d->x * TILE_SIZE + game->offset_x;
			d->py = d->y * TILE_SIZE + game->offset_y;
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				d->px, d->py);
			d->x++;
		}
		d->y++;
	}
}

/*****************************************************************************/

void	draw_map(t_game *game)
{
	t_draw	d;

	draw_floor(game, &d);
	d.y = 0;
	while (game->map[d.y])
	{
		d.x = 0;
		while (game->map[d.y][d.x])
		{
			d.px = d.x * TILE_SIZE + game->offset_x;
			d.py = d.y * TILE_SIZE + game->offset_y;
			draw_objs(game, &d);
			d.x++;
		}
		d.y++;
	}
	draw_player(game);
}
