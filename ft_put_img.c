
#include "so_long.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void	put_img(t_data *img)
{
	// carre rouge
	my_mlx_pixel_put(img, 200, 200, 0X00FF0000);
	my_mlx_pixel_put(img, 201, 200, 0X00FF0000);
	my_mlx_pixel_put(img, 202, 200, 0X00FF0000);
	my_mlx_pixel_put(img, 203, 200, 0X00FF0000);
	my_mlx_pixel_put(img, 204, 200, 0X00FF0000);
	my_mlx_pixel_put(img, 200, 201, 0X00FF0000);
	my_mlx_pixel_put(img, 201, 201, 0X00FF0000);
	my_mlx_pixel_put(img, 202, 201, 0X00FF0000);
	my_mlx_pixel_put(img, 203, 201, 0X00FF0000);
	my_mlx_pixel_put(img, 204, 201, 0X00FF0000);
	my_mlx_pixel_put(img, 200, 202, 0X00FF0000);
	my_mlx_pixel_put(img, 201, 202, 0X00FF0000);
	my_mlx_pixel_put(img, 202, 202, 0X00FF0000);
	my_mlx_pixel_put(img, 203, 202, 0X00FF0000);
	my_mlx_pixel_put(img, 204, 202, 0X00FF0000);
	my_mlx_pixel_put(img, 200, 203, 0X00FF0000);
	my_mlx_pixel_put(img, 201, 203, 0X00FF0000);
	my_mlx_pixel_put(img, 202, 203, 0X00FF0000);
	my_mlx_pixel_put(img, 203, 203, 0X00FF0000);
	my_mlx_pixel_put(img, 204, 203, 0X00FF0000);
	my_mlx_pixel_put(img, 200, 204, 0X00FF0000);
	my_mlx_pixel_put(img, 201, 204, 0X00FF0000);
	my_mlx_pixel_put(img, 202, 204, 0X00FF0000);
	my_mlx_pixel_put(img, 203, 204, 0X00FF0000);
	my_mlx_pixel_put(img, 204, 204, 0X00FF0000);

	// carre vert
	my_mlx_pixel_put(img, 200, 205, 0X0000FF00);
	my_mlx_pixel_put(img, 201, 205, 0X0000FF00);
	my_mlx_pixel_put(img, 202, 205, 0X0000FF00);
	my_mlx_pixel_put(img, 203, 205, 0X0000FF00);
	my_mlx_pixel_put(img, 204, 205, 0X0000FF00);
	my_mlx_pixel_put(img, 200, 206, 0X0000FF00);
	my_mlx_pixel_put(img, 201, 206, 0X0000FF00);
	my_mlx_pixel_put(img, 202, 206, 0X0000FF00);
	my_mlx_pixel_put(img, 203, 206, 0X0000FF00);
	my_mlx_pixel_put(img, 204, 206, 0X0000FF00);
	my_mlx_pixel_put(img, 200, 207, 0X0000FF00);
	my_mlx_pixel_put(img, 201, 207, 0X0000FF00);
	my_mlx_pixel_put(img, 202, 207, 0X0000FF00);
	my_mlx_pixel_put(img, 203, 207, 0X0000FF00);
	my_mlx_pixel_put(img, 204, 207, 0X0000FF00);
	my_mlx_pixel_put(img, 200, 208, 0X0000FF00);
	my_mlx_pixel_put(img, 201, 208, 0X0000FF00);
	my_mlx_pixel_put(img, 202, 208, 0X0000FF00);
	my_mlx_pixel_put(img, 203, 208, 0X0000FF00);
	my_mlx_pixel_put(img, 204, 208, 0X0000FF00);
	my_mlx_pixel_put(img, 200, 209, 0X0000FF00);
	my_mlx_pixel_put(img, 201, 209, 0X0000FF00);
	my_mlx_pixel_put(img, 202, 209, 0X0000FF00);
	my_mlx_pixel_put(img, 203, 209, 0X0000FF00);
	my_mlx_pixel_put(img, 204, 209, 0X0000FF00);

	// jaune pas ouf
	my_mlx_pixel_put(img, 250, 205, 0X0000FF00);
	my_mlx_pixel_put(img, 251, 205, 0X00FF0000);
	my_mlx_pixel_put(img, 252, 205, 0X0000FF00);
	my_mlx_pixel_put(img, 253, 205, 0X00FF0000);
	my_mlx_pixel_put(img, 254, 205, 0X0000FF00);
	my_mlx_pixel_put(img, 250, 206, 0X00FF0000);
	my_mlx_pixel_put(img, 251, 206, 0X0000FF00);
	my_mlx_pixel_put(img, 252, 206, 0X00FF0000);
	my_mlx_pixel_put(img, 253, 206, 0X0000FF00);
	my_mlx_pixel_put(img, 254, 206, 0X00FF0000);
	my_mlx_pixel_put(img, 250, 207, 0X0000FF00);
	my_mlx_pixel_put(img, 251, 207, 0X00FF0000);
	my_mlx_pixel_put(img, 252, 207, 0X0000FF00);
	my_mlx_pixel_put(img, 253, 207, 0X00FF0000);
	my_mlx_pixel_put(img, 254, 207, 0X0000FF00);
	my_mlx_pixel_put(img, 250, 208, 0X00FF0000);
	my_mlx_pixel_put(img, 251, 208, 0X0000FF00);
	my_mlx_pixel_put(img, 252, 208, 0X00FF0000);
	my_mlx_pixel_put(img, 253, 208, 0X0000FF00);
	my_mlx_pixel_put(img, 254, 208, 0X00FF0000);
	my_mlx_pixel_put(img, 250, 209, 0X0000FF00);
	my_mlx_pixel_put(img, 251, 209, 0X00FF0000);
	my_mlx_pixel_put(img, 252, 209, 0X0000FF00);
	my_mlx_pixel_put(img, 253, 209, 0X00FF0000);
	my_mlx_pixel_put(img, 254, 209, 0X0000FF00);

	// test jaune - ok
	my_mlx_pixel_put(img, 250, 200, 0X00FFFF00);
	my_mlx_pixel_put(img, 251, 200, 0X00FFFF00);
	my_mlx_pixel_put(img, 252, 200, 0X00FFFF00);
	my_mlx_pixel_put(img, 253, 200, 0X00FFFF00);
	my_mlx_pixel_put(img, 254, 200, 0X00FFFF00);
	my_mlx_pixel_put(img, 250, 201, 0X00FFFF00);
	my_mlx_pixel_put(img, 251, 201, 0X00FFFF00);
	my_mlx_pixel_put(img, 252, 201, 0X00FFFF00);
	my_mlx_pixel_put(img, 253, 201, 0X00FFFF00);
	my_mlx_pixel_put(img, 254, 201, 0X00FFFF00);
	my_mlx_pixel_put(img, 250, 202, 0X00FFFF00);
	my_mlx_pixel_put(img, 251, 202, 0X00FFFF00);
	my_mlx_pixel_put(img, 252, 202, 0X00FFFF00);
	my_mlx_pixel_put(img, 253, 202, 0X00FFFF00);
	my_mlx_pixel_put(img, 254, 202, 0X00FFFF00);
	my_mlx_pixel_put(img, 250, 203, 0X00FFFF00);
	my_mlx_pixel_put(img, 251, 203, 0X00FFFF00);
	my_mlx_pixel_put(img, 252, 203, 0X00FFFF00);
	my_mlx_pixel_put(img, 253, 203, 0X00FFFF00);
	my_mlx_pixel_put(img, 254, 203, 0X00FFFF00);
	my_mlx_pixel_put(img, 250, 204, 0X00FFFF00);
	my_mlx_pixel_put(img, 251, 204, 0X00FFFF00);
	my_mlx_pixel_put(img, 252, 204, 0X00FFFF00);
	my_mlx_pixel_put(img, 253, 204, 0X00FFFF00);
	my_mlx_pixel_put(img, 254, 204, 0X00FFFF00);
}