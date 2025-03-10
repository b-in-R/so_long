

#include "so_long.h"

#include <X11/keysym.h>// keycodes

//-------------------------pour fermeture fenetre------------------------
int close_window(void *param)
{
    (void)param;
    exit(0);
    return (0);
}

int	handle_keypress(int keycode, void *param)
{
	if (keycode == XK_Escape)
		exit(0);
	return (0);
}
//------------------------------------------------------------------------


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 400, 400, "start");
	img.img = mlx_new_image(mlx, 400, 400);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
		&img.line_length, &img.endian);

	//my_mlx_pixel_put(&img, 200, 200, 0x00FF0000);
	put_img(&img);// ft_put_img.c carre pixels

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);



//----------------------pour fermeture fenetre---------------
	mlx_hook(mlx_win, 17, 0, close_window, NULL);
	mlx_key_hook(mlx_win, handle_keypress, NULL);
//-----------------------------------------------------------


	mlx_loop(mlx);

	return (0);
}