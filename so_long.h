

#ifndef SO_LONG_H

# define SO_LONG_H

# include "./libft/libft.h"
# include "./mlx_linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	put_img(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);


#endif
