#include "so_long.h"

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = ft_calloc(height + 1, sizeof(char *));
	if (!copy)
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

void	pos_player_exit_ncoin(char **map, t_check *m, t_game *game)
{
	m->temp_i = 1;
	while (map[m->temp_i + 1])
	{
		m->temp_j = 1;
		while (map[m->temp_i][m->temp_j + 1])
		{
			if (map[m->temp_i][m->temp_j] == 'P')
			{
				m->check_i_p = m->temp_i;
				m->check_j_p = m->temp_j;
			}
			else if (map[m->temp_i][m->temp_j] == 'C')
				game->coin_total++;
			else if (map[m->temp_i][m->temp_j] == 'E')
			{
				game->exit_x = m->temp_j;
				game->exit_y = m->temp_i;
			}
			m->temp_j++;
		}
		m->temp_i++;
	}
}

int	check_path(char **map, t_game *game, t_check *m)
{
	char	**map_copy;

	map_copy = copy_map(map, m->height);
	if (!map_copy)
	{
		free_map(map_copy);
		return (1);
	}
	pos_player_exit_ncoin(map, m, game);
	game->coin_collected = 0;
	flood_fill(map_copy, m, m->check_i_p, m->check_j_p);
	free_map(map_copy);
	if (game->coin_total != m->check_coin || m->exit != 1 ||
			game->coin_total <= 0)
		return (1);
	return (0);
}
