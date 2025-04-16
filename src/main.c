
#include "so_long.h"

int	main(int ac, char **av)
{
	t_game		game;
	t_player	player;

	if (ac != 2)
		exit_error("ac != 2", 0, NULL);// -> utils.c
	game.player = &player;
	game_init(&game, av[1]);// -> game.c 
	// voir pourquoi handle_input, close_game, render_frame ici et pourquoi cet ordre?
	mlx_key_hook(game.win, handle_input, &game);// -> game.c
	mlx_hook(game.win, 17, 0, close_game, &game);// -> utils.c
	mlx_loop_hook(game.mlx, render_frame, &game);// -> render.c
	mlx_loop(game.mlx);
	return (0);
}