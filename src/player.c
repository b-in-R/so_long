
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

void	check_collect_exit(t_game *game, t_player *p)
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
			close_game(game);
		}
		else
		{
			// animation qu'il faut ramasser les coin?
		}
	}
}