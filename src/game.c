
#include "so_long.h"


int	handle_input(int key, t_game *game)
{
	t_player	*p;

	p = game->player;
	if (key == XK_Escape)
		close_game(game);
	else if (key == XK_w || key == XK_Up)
		move_up(game, p);
	else if (key == XK_s || key == XK_Down)
		move_down(game, p);
	else if (key == XK_a || key == XK_Left)
		move_left(game, p);
	else if (key == XK_d || key == XK_Right)
		move_right(game, p);
	return (0);
}

void	*load_image(t_game *game, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img)
		exit_error(path, 1, game);
	return (img);
}

void	load_textures(t_game *game)
{
	game->img_wall_on = load_image(game, "../sprites/wall_on.xpm");
	game->img_wall_off = load_image(game, "../sprites/wall_off.xpm");
	game->img_floor = load_image(game, "../sprites/floor.xpm");
	game->img_player_still = load_image(game, "../sprites/player_still.xpm");
	game->img_player_jump_up = load_image(game, "../sprites/player_jump_up.xpm");
	game->img_player_jump_down = load_image(game, "../sprites/player_jump_down.xpm");
	game->img_player_jump_high = load_image(game, "../sprites/player_jump_high.xpm");
	game->img_exit_on = load_image(game, "../sprites/exit_on.xpm");
	game->img_exit_off = load_image(game, "../sprites/exit_off.xpm");
	game->img_coin = load_image(game, "../sprites/coin_on.xpm");
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}


void	game_init(t_game *game, char *av)
{
	t_check		m;
	int			map_width;
	int			map_height;

	game->offset_x = MARGIN_LEFT;
	game->offset_y = MARGIN_TOP;
	map_width = ft_strlen(game->map[0]) * TILE_SIZE;
	map_height = get_map_height(game->map) * TILE_SIZE;
	game->mlx = mlx_init();
	game->map = read_map(av);
	if (!game->map)
		exit_error("game_init - read_map", 0, NULL);// a voir si besoin de free map ou mlx?
	if (check_map(game->map, game, &m))
		exit_error("check_map", 1, game);
	game->win_w = map_width + MARGIN_LEFT + MARGIN_RIGHT;
	game->win_h = map_height + MARGIN_TOP + MARGIN_BOTTOM;

	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, "so_long");
	game->moves = 0;
	init_player(game, game->player, &m);
	load_textures(game);
	draw_map(game);
}