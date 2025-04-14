
#include "so_long.h"

int	render_frame(t_game *game)
{
	update_player_pos(game, game->player);
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	return (0);
}


void	draw_player(t_game *game)
{
	t_player	*p;
	void	*sprite;
	
	p = game->player;
	sprite = game->img_player_still;

	if (p->moving)
	{
		if (p->anim_frame == 1)
			sprite = game->img_player_jump_up;
		else if (p->anim_frame == 2)
			sprite = game->img_player_jump_high;
		else if (p->anim_frame == 3)
			sprite = game->img_player_jump_down;
	}
	mlx_put_image_to_window(game->mlx, game->win, sprite, p->px + game->offset_x, p->py + game->offset_y);
}


void	draw_map(t_game *game)
{
	int		x;
	int		y;
	int		px;
	int		py;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			px = x * TILE_SIZE + game->offset_x;
			py = y * TILE_SIZE + game->offset_y;
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall_on, px, py);
			else
				mlx_put_image_to_window(game->mlx, game->win, game->img_floor, px, py);
			
			
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img_coin, px, py);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img_exit_off, px, py);
			
			if (game->map[y][x] == '1' && y != 0)// affichage du sommet de l'arbre a voir si x ou y
				mlx_put_image_to_window(game->mlx, game->win, game->img_wall_off, px, py - TILE_SIZE);
			x++;
		}
		y++;
	}

	draw_player(game);
}
