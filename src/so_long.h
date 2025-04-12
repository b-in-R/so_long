
#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>

# include <stdio.h>



typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		win_w;
	int		win_h;

	void	*img_player;
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_coin;

	char	**map;
	int		*player_x;
	int		*player_y;
	int		moves;
}			t_game;

typedef struct s_check
{
	int	i;
	int	j;
	int	check_i_p;// position x player
	int	check_j_p;// position y player
	int	check_i_e;// position x exit
	int	check_j_e;// position y exit
	int	n_coin;// position x coin
	int	player;
	int	exit;
	int	wall;
	int	tot;// nombre de cases tot
	int	n_ground;// nombre de 0
	int	lenght;// longueur map
	int	height;// hauteur map
	int	result_err;// erreur si 1

}		t_check;


// game.c
void	game_init(t_game *game, char *map_path);
int		handle_input(int keycode, t_game *game);
void	load_textures(t_game *game);

// utils.c
int		close_game(t_game *game);
void	exit_error(char *str, int map_free, t_game *game);

// render.c
int		render_frame(t_game *game);
void	draw_map(t_game *game);

// map.c
int		check_map(char **map, t_game *game);
char	**read_map(char *path);
void	check_path(char **map, t_game *game, t_check *m);

// utils.c
void	exit_error(char *str, int map_free, t_game *game);
int		close_game(t_game *game);
void	free_map(char **map);

#endif
