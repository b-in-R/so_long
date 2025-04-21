
#include "so_long.h"

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
		game->moves++;
		ft_printf("%i\n", game->moves);
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
		game->moves++;
		ft_printf("%i\n", game->moves);
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
		game->moves++;
		ft_printf("%i\n", game->moves);
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
		game->moves++;
		ft_printf("%i\n", game->moves);
	}
}