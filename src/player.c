#include "so_long.h"

void	init_player(t_game *game, t_player *p, t_check *c)// <- game_init(game.c)
{
	p->x = c->check_j_p;
	p->y = c->check_i_p;
	p->px = p->x * TILE_SIZE;
	p->py = p->y * TILE_SIZE;
	p->targ_px = p->px;
	p->targ_py = p->py;
	p->anim_frame = 0;
	p->moving = 0;
	p->direction = 'S';
	game->map[p->y][p->x] = '0';
}

// ADAPTER (t_draw etc)
void	draw_tile(t_game *game, int y, int x)// <- (2)update_player_pos(), render_frame(render.c)
{
	t_draw	d;
	int		px;
	int		py;
	char	tile;

	px = x * TILE_SIZE + game->offset_x;
	py = y * TILE_SIZE + game->offset_y;
	tile = game->map[y][x];


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
	else if (tile == '0')
	{
		if (y < game->height && game->map[y + 1][x] == '1')
			mlx_put_image_to_window(game->mlx, game->win, game->img_wall_n_tree, px, py);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor, px, py);
	}

	// Enfin, dessine le joueur si présent à cet endroit
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
		// ajouter animation, compteur de coin etc
	}
	else if (*tile == 'E')
	{
		if (game->coin_collected == game->coin_total)
		{
			// ajouter animation, texte victoire etc
			close_game(game);// -> utils.c
		}
		else
		{
			// animation qu'il faut ramasser les coin?
		}
	}
}


void	update_player_pos(t_game *game, t_player *p)// <- render_frame(render.c)
{
	int	old_x;
	int	old_y;

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
		old_x = p->x;
		old_y = p->y;

		p->x = p->px / TILE_SIZE;
		p->y = p->py / TILE_SIZE;

		draw_tile(game, old_y, old_x);// -> ()
		draw_tile(game, p->y, p->x);// -> ()
		/*
		if (game->map[old_y][old_x] == 'P')
			game->map[old_y][old_x] = '0';
		*/
		p->moving = 0;
		p->anim_frame = 0;
		p->direction = 's';

		check_collect_exit(game, p);// -> ()
	}
}
