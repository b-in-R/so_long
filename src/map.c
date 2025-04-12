
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
	m->player = 0;
	m->exit = 0;
	m->wall = 0;
	m->tot = 0;// nombre cases total
	m->n = 0;// nombre cases remplies -> peut etre pas besoin, gere par if (map[i][j] != 'P' && ...)
	m->lenght = 0;// longueur map
	m->height = 0;// hauteur map
	m->result_err = 0;// erreur si 1
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

void	check_path(char **map, t_game *game, t_check *m)
{
	
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
				m.player++;
			else if (map[m.i][m.j] == 'E')
				m.exit++;
			if (m.player > 1 || m.exit > 1)
				exit_error("player > 1 || exit > 1", 1, map);
			m.j++;
		}
		m.i++;
	}
	check_path(map, game, &m);
	return (m.result_err);
}