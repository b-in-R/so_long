

#ifndef SO_LONG_H

# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"

#include <X11/keysym.h>

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;



int		put_img(t_data *img, int event);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


// create_trgb.c -> exercices
int	create_trbg(int t, int r, int g, int b);
int	get_t(int trgb);
int	get_r(int trgb);
int	get_g(int trgb);
int	get_b(int trgb);


#endif
