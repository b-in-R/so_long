
#include "so_long.h"


int	handle_input(int key, t_game *game)
{
	if (key == XK_Escape)
		close_game(game);
	else if (key == XK_w || key == XK_Up)
		move_up(game);
	else if (key == XK_s || key == XK_Down)
		move_down(game);
	else if (key == XK_a || key == XK_Left)
		move_left(game);
	else if (key == XK_d || key == XK_Right)
		move_right(game);
	return (0);
}



void	load_textures(t_game *game)
{
	int	w;
	int	h;

	game->img_wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &w, &h);
	game->img_floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &w, &h);
	game->img_coin = mlx_xpm_file_to_image(game->mlx, "sprites/coin.xpm", &w, &h);
}




void	game_init(t_game *game, char *av)
{
	game->mlx = mlx_init();
	game->map = read_map(av);
	if (!game->map)
		exit_error("game_init - read_map", 0, NULL);// a voir si besoin de free map ou mlx?
	if (check_map(game->map, game))
		exit_error("check_map", 1, game);
	game->win_w = ft_strlen(game->map[0]) * TILE_SIZE;
	game->win_h = get_map_height(game->map) * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, "so_long");
	game->moves = 0;
	load_textures(game);
	draw_map(game);
}