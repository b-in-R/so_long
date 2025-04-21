#include "so_long.h"

void	init_player(t_game *game, t_player *p, t_check *c)
{
	p->x = c->check_j_p;
	p->y = c->check_i_p;
	p->px = p->x * TILE_SIZE;
	p->py = p->y * TILE_SIZE;
	p->moving = 0;
	p->direction = 'S';
	game->map[p->y][p->x] = '0';
}

void	draw_tile(t_game *game, int y, int x)
{
	t_draw	d;

	ft_memset(&d, 0, sizeof(t_draw));
	d.px = x * TILE_SIZE;
	d.py = y * TILE_SIZE;
	d.tile = game->map[y][x];
	if (d.tile == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_y,
			d.px, d.py);
		if (y < game->height && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_wall_y_tree, d.px, d.py);
	}
	tile_image_coin(game, &d, y, x);
	tile_image_exit_floor(game, &d, y, x);
	if (game->player->x == x && game->player->y == y)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_player,
			d.px, d.py);
		if (game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win,
				game->img_player_tree, d.px, d.py);
	}
}

void	check_collect_exit(t_game *game, t_player *p)
{
	char	*tile;

	tile = &game->map[p->y][p->x];
	if (*tile == 'C')
	{
		*tile = 'K';
		game->coin_collected++;
	}
	else if (*tile == 'E' && game->coin_collected == game->coin_total)
		close_game(game);
}

void	movement(t_player *p)
{
	if (p->direction == 'r')
		p->px += MOVE_STEP;
	else if (p->direction == 'l')
		p->px -= MOVE_STEP;
	else if (p->direction == 'd')
		p->py += MOVE_STEP;
	else if (p->direction == 'u')
		p->py -= MOVE_STEP;
	p->anim_frame++;
}

void	update_player_pos(t_game *game, t_player *p)
{
	if (!p->moving)
		return ;
	if (p->anim_frame < MAX_ANIM_FRAME)
		movement(p);
	else
	{
		p->old_x = p->x;
		p->old_y = p->y;
		p->x = p->px / TILE_SIZE;
		p->y = p->py / TILE_SIZE;
		draw_tile(game, p->old_y, p->old_x);
		draw_tile(game, p->y, p->x);
		p->moving = 0;
		p->anim_frame = 0;
		p->direction = 's';
		check_collect_exit(game, p);
	}
}
