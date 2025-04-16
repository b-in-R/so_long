#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SIZE 64
# define MOVE_STEP 16
# define MAX_ANIM_FRAME 4
# define MARGIN_TOP 200
# define MARGIN_BOTTOM 128
# define MARGIN_LEFT 128
# define MARGIN_RIGHT 128

# define SPR_M "./sprites/map"
# define SPR_C "./sprites/car"
# define SPR_E "./sprites/exit"

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>

# include <stdio.h>


typedef struct s_draw
{
	int	x;
	int	y;
	int	px;
	int	py;
}		t_draw;

typedef struct s_player
{
	int		x;// position joueur
	int		y;// position joueur
	int		px;// position pixel X (x * TILE_SIZE)
	int		py;// position pixel Y (y * TILE_SIZE)
	int		targ_px;
	int		targ_py;
	int		anim_frame;// 0 a 4
	int		moving;// 1 si deplacement
	char	direction;// 'u' 'd' 'l' 'r' 's'(still) 
}			t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			win_w;
	int			win_h;
	int			offset_x;
	int			offset_y;
	int			height;

	void		*img_player;
	void		*img_player_tree;
	void		*img_wall_y;
	void		*img_wall_y_tree;
	void		*img_wall_n_tree;
	void		*img_floor;
	void		*img_exit_y;
	void		*img_exit_y_tree;
	void		*img_exit_n;
	void		*img_exit_n_tree;
	void		*img_coin_y;
	void		*img_coin_y_tree;
	void		*img_coin_n;
	void		*img_coin_n_tree;
	void		*img_exit_build[5];
	void		*img_exit_build_tree[5];

	void		*ui_corner_topleft;
	void		*ui_corner_topright;
	void		*ui_corner_botleft;
	void		*ui_corner_botright;

	int			ex_anim_start;
	int			ex_anim_frame;
	int			ex_anim_timer;

	char		**map;
	int			*player_x;
	int			*player_y;
	int			exit_x;
	int			exit_y;
	int			moves;
	int			coin_collected;
	int			coin_total;

	t_player	*player;
}				t_game;

typedef struct s_check
{
	int	i;
	int	j;
	int	check_i_p;// position x player
	int	check_j_p;// position y player
	int	check_i_e;// position x exit
	int	check_j_e;// position y exit
	int	tot_coin;// nombre tot coin
	int	check_coin;// nombre de coin vu avec flood_fill pour check validite
	int	player;// nombre de P pour check validite
	int	exit;// nombre de E pour check validite
	int	wall;// inutile
	int	tot;// nombre de cases tot (inutile)
	int	n_ground;// nombre de 0 (inutile)
	int	lenght;// longueur map
	int	height;// hauteur map
	int	result_err;// erreur si 1
}		t_check;


// game.c
void	game_init(t_game *game, char *map_path);
int		handle_input(int keycode, t_game *game);

// render.c
void	draw_map(t_game *game);
void	draw_player(t_game *game);
int		render_frame(t_game *game);
void	draw_exit(t_game *game, t_draw *d);

// map.c
int		check_map(char **map, t_game *game, t_check *m);
char	**read_map(char *path);

// path.c
int		check_path(char **map, t_game *game, t_check *m);

// moving.c
void	move_up(t_game *game, t_player *p);
void	move_down(t_game *game, t_player *p);
void	move_left(t_game *game, t_player *p);
void	move_right(t_game *game, t_player *p);

// player.c
void	update_player_pos(t_game *game, t_player *p);
void	init_player(t_game *game, t_player *p, t_check *c);
void	draw_tile(t_game *game, int y, int x);

// utils.c
void	exit_error(char *str, int map_free, t_game *game);
int		close_game(t_game *game);
void	free_map(char **map);

#endif