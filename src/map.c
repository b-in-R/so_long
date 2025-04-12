
#include "so_long.h"

static size_t	count_lines(char *path) // static?
{
	int		fd;
	size_t	count;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	**read_map(char *av)
{
	int		fd;
	size_t	lines;
	char	**map;
	size_t	i;

	lines = count_lines(av);
	if (lines == 0)
		return (NULL);
	
	map = malloc(sizeof(char *) * (lines + 1));
	if (!map)
		return (NULL);
	
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		free(map);
		return (NULL);
	}

	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
		{
			free_map(map);
			close(fd);
			return (NULL);
		}
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}




void	init_vars(t_check *m)
{
	m->i = 0;
	m->j = 0;
	m->check_i_p = 0;
	m->check_j_p = 0;
	m->check_i_e = 0;
	m->check_j_e = 0;
	m->n_coin = 0;
	m->player = 0;
	m->exit = 0;
	m->wall = 0;
	m->tot = 0;
	m->n_ground = 0;
	m->lenght = 0;
	m->height = 0;
	m->result_err = 0;
}


int	check_map_size_square(char **map, t_check *m)
{
	int	i;
	int	j;
	int	sto_j;

	i = 0;
	sto_j = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '1'
				&& map[i][j] != '0')
			return (1);
		while (map[i][j])
			j++;
		if (sto_j == 0)
			sto_j = j;
		if (j != sto_j)
			return (1);
		i++;
		m->tot += j;
	}
	m->lenght = j;
	m->height = i;
	return (0);
}

void	player_exit_pos(char **map, t_check *m)
{
	m->i = 1;
	while (map[m->i])
	{
		m->j = 0;
		while (map[m->i][m->j] && (map[m->i][m->j] != 'P' || map[m->i][m->j] != 'E'
				|| map[m->i][m->j] != 'C'))
		{
			if (map[m->i][m->j] == 'P')
			{
				m->check_i_p = m->i;
				m->check_j_p = m->j;
			}
			else if (map[m->i][m->j] == 'E')
			{
				m->check_i_e = m->i;
				m->check_j_e = m->j;
			}
			else if (map[m->i][m->j] == 'C')
				(m->n_coin)++;
			(m->j)++;
		}
		(m->i)++;
	}
	m->i = 0;//a voir si inutile (set dans path_recursive)
	m->j = 0;//a voir si inutile (set dans path_recursive)
}


int	path_recursive(char **map, t_check *m)// ou pas recursif
{
	m->i = m->check_i_p;
	m->j = m->check_j_p;
	while (m->n_coin > 0 && map[m->i])// a voir si on passe a travers exit si pas de coin
	{
		// reset m->j ??
		while (m->n_coin > 0 && map[m->i][m->j])
		{
			if (map[m->i][m->j] == 'C')
			{
				(m->n_coin)--;
			}
			(m->j)++;// a faire si c'est wall, retour etape precedente
		}
		(m->i)++;// a faire si c'est wall, retour etape precedente
	}

}



int	check_path(char **map, t_game *game, t_check *m)
{
	player_exit_pos(map, m);// definit pos player et exit
	if (path_recursive(map, m))
		exit_error("path player - exit", 1, game);
	




	return (0);
}


int	check_map(char **map, t_game *game)
{
	t_check	m;

	init_vars(&m);
	if (check_map_size_square(map, &m) || m.height <= 1 || m.lenght <= 1)
		exit_error("check_map_size_square", 1, game);
	while (map[m.i] && m.result_err == 0)
	{
		m.j = 0;
		while (map[m.i][m.j] && m.result_err == 0)
		{
			if (map[0][m.j] != '1' || map[m.i][0] != '1' || map[m.height][m.j] != '1'
					|| map[m.i][m.lenght] != '1')
				exit_error("check_map - bord erreur", 1, game);
			else if (map[m.i][m.j] == 'P')
				(m.player)++;
			else if (map[m.i][m.j] == 'E')
				(m.exit)++;
			else if (map[m.i][m.j] == '0')
				(m.n_ground)++;
			if (m.player != 1 || m.exit != 1)
				exit_error("player != 1 || exit != 1", 1, map);
			m.j++;
		}
		m.i++;
	}
	if (check_path(map, game, &m))
		exit_error("check_path", 1, map);
	return (m.result_err);
}