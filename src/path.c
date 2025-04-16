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


void	flood_fill(char **map, t_check *m, int i, int j)// <- check_path()
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

void	pos_player_exit_ncoin(char **map, t_check *m, t_game *game)// <- check_path()
{
	int	i;
	int	j;

	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			if (map[i][j] == 'P')
			{
				m->check_i_p = i;
				m->check_j_p = j;
			}
			else if (map[i][j] == 'C')
				m->tot_coin++;
			else if (map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

int	check_path(char **map, t_game *game, t_check *m)// <- check_map(map.c)
{
	char	**map_copy;

	map_copy = copy_map(map, m->height);
	if (!map_copy)
		exit_error("check_path - copy_map", 1, game);
	pos_player_exit_ncoin(map, m, game);// -> ()
	game->coin_total = m->tot_coin;
	game->coin_collected = 0;
	flood_fill(map_copy, m, m->check_i_p, m->check_j_p);// -> ()
	free_map(map_copy);
	if (m->tot_coin != m->check_coin || m->exit != 1)
		return (1);
	return (0);
}
