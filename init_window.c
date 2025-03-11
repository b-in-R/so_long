

#include "so_long.h"

#include <X11/keysym.h>// keycodes


//-------------------------pour fermeture fenetre------------------------
int close_window(void *param)
{
	t_vars	*vars = (t_vars *)param;
	mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    return (0);
}

int	handle_keypress(int keycode, void *param)
{
	static int		img_shown = 0;
	t_vars			*vars = ((t_data **)param)[0];
	t_data			*img = ((t_data **)param)[1];

	if (keycode == XK_Escape)
		close_window(vars);
	if (keycode == XK_space && img_shown == 0)
	{
		put_img(img, 1);
		mlx_put_image_to_window(vars->mlx, vars->win, img->img, 0, 0);
		img_shown = 1;
	}
	return (0);
}
//------------------------------------------------------------------------


int	main(void)
{
	t_vars	vars;
	t_data	img;
	void	*param[2];

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 400, 400, "start");

	img.img = mlx_new_image(vars.mlx, 400, 400);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);

	param[0] = &vars;
	param[1] = &img;

	mlx_key_hook(vars.win, handle_keypress, param);
	//put_img(&img, 1);
	//mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);


//----------------------pour fermeture fenetre---------------
	mlx_hook(vars.win, 17, 0, close_window, &vars);//croix
//	mlx_key_hook(vars.win, handle_keypress, NULL);//esc
//-----------------------------------------------------------


	mlx_loop(vars.mlx);

	return (0);
}