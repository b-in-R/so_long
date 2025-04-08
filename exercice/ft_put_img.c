
#include "exercice.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	do_square(t_data *img, int x, int y, int color, int range)
{
	int	count;
	int	temp;
	int	z;

	count = 0;
	temp = range;
	while (temp > 0)
	{
		count = 0;
		z = x;
		while (count <= range)
		{
			my_mlx_pixel_put(img, z, y, color);
			z++;
			count++;
		}
		y++;
		temp--;
	}
}

int	put_img(t_data *img, int event)
{
	int	col_red;
	int	col_blue;
	int	col_green;
	int	col_white;
	int	col_torq;
	int	col_yell;
	int	col_pink;

	/*
		codes couleur base:	rouge:	0X00 FF0000
							vert:	0X00 00FF00
							bleu:	0X00 0000FF
	*/
	col_red = 0X00FF0000;// rouge
	col_blue = 0X000000FF;// bleu
	col_green = 0X0000FF00;// vert

	col_white = 0X00FFFFFF;// blc -> tous
	col_torq = 0X0000FFFF;// turquoise -> vert + bleu
	col_yell = 0X00FFFF00;// jaune -> rouge + vert
	col_pink = 0X00FF00FF;// rose -> rouge + bleu
	

	if (event == 1)
	{
		do_square(img, 150, 150, col_white, 50);
		do_square(img, 200, 150, col_green, 50);
		do_square(img, 150, 200, col_blue, 50);
		do_square(img, 200, 200, col_red, 50);

		do_square(img, 0, 0, col_white, 50);
		do_square(img, 50, 0, col_torq, 50);
		do_square(img, 0, 50, col_yell, 50);
		do_square(img, 50, 50, col_pink, 50);
	}


	do_square(img, 390, 350, create_trbg(0, 102, 48, 191), 50);
	/*
	// exemple pixel couleur:

		my_mlx_pixel_put(img, 200, 200, col_red);
	*/
	return (0);
}