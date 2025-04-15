
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
	game->img_wall_y = load_image(game, "./sprites/wall_on.xpm");
	game->img_wall_y_tree = load_image(game, "./sprites/wall_on_tree.xpm");
	game->img_wall_n_tree = load_image(game, "./sprites/wall_off_tree.xpm");
	game->img_floor = load_image(game, "./sprites/floor.xpm");
	game->img_player = load_image(game, "./sprites/player.xpm");
	game->img_player_tree = load_image(game, "./sprites/player_tree.xpm");
	game->img_exit_y = load_image(game, "./sprites/exit_on.xpm");
	game->img_exit_y_tree = load_image(game, "./sprites/exit_on_tree.xpm");
	game->img_exit_n = load_image(game, "./sprites/exit_off.xpm");
	game->img_exit_n_tree = load_image(game, "./sprites/exit_off_tree.xpm");
	game->img_coin_y = load_image(game, "./sprites/coin_on.xpm");
	game->img_coin_y_tree = load_image(game, "./sprites/coin_on_tree.xpm");
	game->img_coin_n = load_image(game, "./sprites/coin_off.xpm");
	game->img_coin_n_tree = load_image(game, "./sprites/coin_off_tree.xpm");
	game->img_exit_build[0] = load_image(game, "./sprites/exit_build1.xpm");
	game->img_exit_build[1] = load_image(game, "./sprites/exit_build2.xpm");
	game->img_exit_build[2] = load_image(game, "./sprites/exit_build3.xpm");
	game->img_exit_build[3] = load_image(game, "./sprites/exit_build4.xpm");
	game->img_exit_build[4] = load_image(game, "./sprites/exit_build5.xpm");
	game->img_exit_build_tree[0] = load_image(game, "./sprites/exit_build1_tree.xpm");
	game->img_exit_build_tree[1] = load_image(game, "./sprites/exit_build2_tree.xpm");
	game->img_exit_build_tree[2] = load_image(game, "./sprites/exit_build3_tree.xpm");
	game->img_exit_build_tree[3] = load_image(game, "./sprites/exit_build4_tree.xpm");
	game->img_exit_build_tree[4] = load_image(game, "./sprites/exit_build5_tree.xpm");
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
	game->map = read_map(av);
	if (!game->map)
		exit_error("game_init - read_map", 0, NULL);// a voir si besoin de free map ou mlx?
	map_width = ft_strlen(game->map[0]) * TILE_SIZE;
	map_height = get_map_height(game->map) * TILE_SIZE;
	game->mlx = mlx_init();
	if (check_map(game->map, game, &m))
		exit_error("check_map", 1, game);
	game->win_w = map_width + MARGIN_LEFT + MARGIN_RIGHT;
	game->win_h = map_height + MARGIN_TOP + MARGIN_BOTTOM;
	game->height = map_height / TILE_SIZE - 1;

	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, "so_long");
	game->moves = 0;
	init_player(game, game->player, &m);
	load_textures(game);
	draw_map(game);
}