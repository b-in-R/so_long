

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_space)
		printf("space\n");
	if (keycode == XK_1)
		printf("1\n");
	if (keycode == XK_Escape)
	{
		printf("Exit\n");
		exit(0);
	}
	return (0);
}

int	mouse_hook(int button, t_vars *param)
{
	if (button == 1)
		printf("mouse left\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 400, "hooks");
	
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.mlx);
	
	return (0);
}
