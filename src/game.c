#include "so_long.h"


int	handle_input(int key, t_game *game)// <- main
{
	t_player	*p;

	p = game->player;
	if (key == XK_Escape)
		close_game(game);// -> utils.c
	else if (key == XK_w || key == XK_Up)
		move_up(game, p);// -> moving.c
	else if (key == XK_s || key == XK_Down)
		move_down(game, p);// -> moving.c
	else if (key == XK_a || key == XK_Left)
		move_left(game, p);// -> moving.c
	else if (key == XK_d || key == XK_Right)
		move_right(game, p);// -> moving.c
	return (0);
}

void	*load_image(t_game *game, char *path)// <- load_textures()
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img)
		exit_error(path, 1, game);// -> utils.c
	return (img);
}

void	load_textures_map(t_game *game)// <- game_init()
{
	game->img_wall_y = load_image(game, SPR_M "/wall_on.xpm");// -> ()
	game->img_wall_y_tree = load_image(game, SPR_M "/wall_on_tree.xpm");
	game->img_wall_n_tree = load_image(game, SPR_M "/wall_off_tree.xpm");
	game->img_floor = load_image(game, SPR_M "/floor.xpm");
	game->img_player = load_image(game, SPR_C "/player.xpm");
	game->img_player_tree = load_image(game, SPR_C "/player_tree.xpm");
	game->img_exit_y = load_image(game, SPR_E "/on.xpm");
	game->img_exit_y_tree = load_image(game, SPR_E "/on_tree.xpm");
	game->img_exit_n = load_image(game, SPR_E "/off.xpm");
	game->img_exit_n_tree = load_image(game, SPR_E "/off_tree.xpm");
	game->img_coin_y = load_image(game, SPR_C "/coin_on.xpm");
	game->img_coin_y_tree = load_image(game, SPR_C "/coin_on_tree.xpm");
	game->img_coin_n = load_image(game, SPR_C "/coin_off.xpm");
	game->img_coin_n_tree = load_image(game, SPR_C "/coin_off_tree.xpm");
	game->img_exit_build[0] = load_image(game, SPR_E "/build1.xpm");
	game->img_exit_build[1] = load_image(game, SPR_E "/build2.xpm");
	game->img_exit_build[2] = load_image(game, SPR_E "/build3.xpm");
	game->img_exit_build[3] = load_image(game, SPR_E "/build4.xpm");
	game->img_exit_build[4] = load_image(game, SPR_E "/build5.xpm");
	game->img_exit_build_tree[0] = load_image(game, SPR_E "/build1_tree.xpm");
	game->img_exit_build_tree[1] = load_image(game, SPR_E "/build2_tree.xpm");
	game->img_exit_build_tree[2] = load_image(game, SPR_E "/build3_tree.xpm");
	game->img_exit_build_tree[3] = load_image(game, SPR_E "/build4_tree.xpm");
	game->img_exit_build_tree[4] = load_image(game, SPR_E "/build5_tree.xpm");
}

int	get_map_height(char **map)// <- game_init()
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}


void	init_map_game(t_game *game, t_check *m, int *map_width, int *map_height)
{
	*map_width = ft_strlen(game->map[0]) * TILE_SIZE;
	*map_height = get_map_height(game->map) * TILE_SIZE;// -> ()
		if (check_map(game->map, game, m))// -> map.c
		exit_error("check_map", 1, game);// -> utils.c
	game->win_w = *map_width + MARGIN_LEFT + MARGIN_RIGHT;
	game->win_h = *map_height + MARGIN_TOP + MARGIN_BOTTOM;
	game->height = *map_height / TILE_SIZE - 1;
}

void	load_textures_ui(t_game *game)
{
	game->ui_corner_topleft = load_image(game, "./sprites/ui/water.xpm");
	game->ui_corner_topright = load_image(game, "./sprites/ui/water.xpm");
	game->ui_corner_botleft = load_image(game, "./sprites/ui/water.xpm");
	game->ui_corner_botright = load_image(game, "./sprites/ui/water.xpm");
}

void	draw_ui(t_game *game, int *map_width, int *map_height)
{
	mlx_put_image_to_window(game->mlx, game->win, game->ui_corner_botleft,
		0, *map_height - TILE_SIZE * 2);
	mlx_put_image_to_window(game->mlx, game->win, game->ui_corner_botright,
		*map_width - TILE_SIZE * 2, *map_height - TILE_SIZE * 2);
	mlx_put_image_to_window(game->mlx, game->win, game->ui_corner_topleft,
		0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->ui_corner_topright,
		*map_width - TILE_SIZE * 2, 0);
}

void	game_init(t_game *game, char *av)// <- main
{
	t_check		m;
	int			map_width;
	int			map_height;

	game->offset_x = MARGIN_LEFT;
	game->offset_y = MARGIN_TOP;
	game->map = read_map(av);// -> map.c
	if (!game->map)
		exit_error("game_init - read_map", 0, NULL);// -> utils.c
	game->mlx = mlx_init();

	init_map_game(game, &m, &map_width, &map_height);

	game->win = mlx_new_window(game->mlx, game->win_w, game->win_h, "so_long");
	game->moves = 0;
	init_player(game, game->player, &m);// -> player.c
	load_textures_map(game);// -> ()
	draw_map(game);// -> render.c
	
	load_textures_ui(game);// -> ()
	draw_ui(game, &map_width, &map_height);
}