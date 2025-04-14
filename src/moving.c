
#include "so_long.h"

void	init_player(t_game *game, t_player *p, t_check *c)
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

void	check_collect_exit(t_game *game, t_player *p)
{
	char	*tile;

	tile = &game->map[p->y][p->x];
	if (*tile == 'C')
	{
		*tile = '0';
		game->coin_collected++;
		// ajouter animation, compteur de coin etc
	}
	else if (*tile == 'E')
	{
		if (game->coin_collected == game->coin_total)
		{
			// ajouter animation, texte victoire etc
			close_game(game);
		}
		else
		{
			// animation qu'il faut ramasser les coin?
		}
	}
}

void	update_player_pos(t_game *game, t_player *p)
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
		if (game->map[old_y][old_x] == 'P')
			game->map[old_y][old_x] = '0';
		p->moving = 0;
		p->anim_frame = 0;
		p->direction = 's';

		check_collect_exit(game, p);
	}
}

void	move_up(t_game *game, t_player *p)
{
	int	target_y;
	int	target_x;

	target_y = p->y - 1;
	target_x = p->x;
	if (p->moving)
		return;
	if (game->map[target_y][target_x] != '1')
	{
		p->direction = 'u';
		p->moving = 1;
		p->anim_frame = 0;
		p->targ_py = p->py - TILE_SIZE;
		game->moves++;
	}
}

void	move_down(t_game *game, t_player *p)
{
	int	target_y;
	int	target_x;

	target_y = p->y + 1;
	target_x = p->x;
	if (p->moving)
		return;
	if (game->map[target_y][target_x] != '1')
	{
		p->direction = 'd';
		p->moving = 1;
		p->anim_frame = 0;
		p->targ_py = p->py + TILE_SIZE;
		game->moves++;
	}
}

void	move_left(t_game *game, t_player *p)
{
	int	target_y;
	int	target_x;

	target_y = p->y;
	target_x = p->x - 1;
	if (p->moving)
		return;
	if (game->map[target_y][target_x] != '1')
	{
		p->direction = 'l';
		p->moving = 1;
		p->anim_frame = 0;
		p->targ_px = p->px - TILE_SIZE;
		game->moves++;
	}
}

void	move_right(t_game *game, t_player *p)
{
	int	target_y;
	int	target_x;

	target_y = p->y;
	target_x = p->x + 1;
	if (p->moving)
		return;
	if (game->map[target_y][target_x] != '1')
	{
		p->direction = 'r';
		p->moving = 1;
		p->anim_frame = 0;
		p->targ_px = p->px + TILE_SIZE;
		game->moves++;
	}
}