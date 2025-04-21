#include "so_long.h"

void	init_player(t_game *game, t_player *p, t_check *c)// <- game_init(game.c)
{
	p->x = c->check_j_p;
	p->y = c->check_i_p;
	p->px = p->x * TILE_SIZE;
	p->py = p->y * TILE_SIZE;
	p->moving = 0;
	p->direction = 'S';
	game->map[p->y][p->x] = '0';
}



void	draw_tile(t_game *game, int y, int x)// <- (2)update_player_pos(), render_frame(render.c)
{
	t_draw	d;
	int		px;
	int		py;
	char	tile;

	ft_memset(&d, 0, sizeof(t_draw));
	px = x * TILE_SIZE;
	py = y * TILE_SIZE;
	tile = game->map[y][x];

/*****************************************************************************/
	if (tile == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_wall_y, px, py);
		if (y < game->height && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall_y_tree, px, py);
	}
	else if (tile == 'C')
	{
		if (y < game->height && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_coin_y_tree, px, py);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_coin_y, px, py);
	}
	else if (tile == 'K')
	{
		if (y < game->height && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_coin_n_tree, px, py);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_coin_n, px, py);
	}
	else if (tile == 'E')
	{
		d.x = x;
		d.y = y;
		d.px = px;
		d.py = py;
		draw_exit(game, &d); // -> render.c 
	}
/*****************************************************************************/
	else if (tile == '0')
	{
		if (y < game->height && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall_n_tree, px, py);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, px, py);
	}

	if (game->player->x == x && game->player->y == y)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->img_player, px, py);
		if (game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_player_tree, px, py);
	}
}

void	check_collect_exit(t_game *game, t_player *p)// <- ()
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

void	update_player_pos(t_game *game, t_player *p)// <- render_frame(render.c)
{
	if (!p->moving)
		return ;
	if (p->anim_frame < MAX_ANIM_FRAME)
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
/*****************************************************************************/