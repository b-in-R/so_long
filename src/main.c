
#include "so_long.h"

int	check_extension(char *str)
{
	int	l;

	l = ft_strlen(str);
	if (l < 4)
		return (1);
	if (!(str[l - 4] == '.' && str[l - 3] == 'b' &&
			str[l - 2] == 'e' && str[l - 1] == 'r'))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game		game;
	t_player	player;

	if (ac != 2 || check_extension(av[1]))
	{
		ft_printf("Error\nmap.ber missing\n");
		return (1);
	}
	ft_memset(&game, 0, sizeof(t_game));
	ft_memset(&player, 0, sizeof(t_player));
	game.player = &player;
	game_init(&game, av[1]);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}