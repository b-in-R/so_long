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

	w = 0;
	h = 0;
	img = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img)
		exit_error(path, game);
	return (img);
}

void	load_textures_map(t_game *game)
{
	game->img_wall_y = load_image(game, SPR_M "/wall_on.xpm");
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

	ft_memset(&m, 0, sizeof(t_check));
	read_map(av, game);
	game->mlx = mlx_init();
	map_width = ft_strlen(game->map[0]) * TILE_SIZE;
	map_height = get_map_height(game->map) * TILE_SIZE;
	game->height = map_height / TILE_SIZE - 1;
	game->win = mlx_new_window(game->mlx, map_width, map_height, "so_long");
	load_textures_map(game);
	if (check_map(game->map, game, &m))
		exit_error("Invalid map", game);
	game->moves = 0;
	init_player(game, game->player, &m);
	draw_map(game);
}
