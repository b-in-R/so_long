
#include "so_long.h"

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = ft_calloc(height + 1, sizeof(char *));
	if (!copy)// a voir
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy);
			return (NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}


void	flood_fill(char **map, t_check *m, int i, int j)
{
	if (map[i][j] == '1' || map[i][j] == 'V')
		return ;
	if (map[i][j] == 'C')
		m->check_coin++;
	if (map[i][j] == 'E')
		m->exit = 1;
	map[i][j] = 'V';
	flood_fill(map, m, i + 1, j);
	flood_fill(map, m, i - 1, j);
	flood_fill(map, m, i, j + 1);
	flood_fill(map, m, i, j - 1);
}



int	check_path(char **map, t_game *game, t_check *m)
{
	char	**map_copy;

	map_copy = copy_map(map, m->height);
	if (!map_copy)
		exit_error("check_path - copy_map", 1, game);
	player_pos_coin(map, m);// definit pos player et n_coin
	game->coin_total = m->tot_coin;
	game->coin_collected = 0;
	flood_fill(map_copy, m, m->check_i_p, m->check_j_p);// a voir si copie de m aussi
	free_map(map_copy);
	if (m->tot_coin != m->check_coin || m->exit == 0)
		return (1);
	return (0);
}