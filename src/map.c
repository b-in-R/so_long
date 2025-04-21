#include "so_long.h"

static size_t	count_lines(char *path)
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
	free(line);
	close(fd);
	return (count);
}

void	read_map(char *av, t_game *game)
{
	int		fd;
	size_t	lines;
	size_t	i;

	lines = count_lines(av);
	if (lines == 0)
		return ;
	game->map = malloc(sizeof(char *) * (lines + 1));
	if (!game->map)
		return ;
	fd = open(av, O_RDONLY);
	i = 0;
	while (i < lines)
	{
		game->map[i] = get_next_line(fd);
		if (game->map[i][ft_strlen(game->map[i]) - 1] == '\n')
			game->map[i][ft_strlen(game->map[i]) - 1] = '\0';
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return ;
}

int	check_map_size_square(char **map, t_check *m)
{
	int	sto_j;

	m->ti = 0;
	m->tj = 0;
	sto_j = 0;
	while (map[m->ti])
	{
		m->tj = 0;
		if (map[m->ti][m->tj] != 'P' && map[m->ti][m->tj] != 'E' &&
				map[m->ti][m->tj] != '1'
				&& map[m->ti][m->tj] != '0' && map[m->ti][m->tj] != 'C')
			return (1);
		while (map[m->ti][m->tj])
			m->tj++;
		if (sto_j == 0)
			sto_j = m->tj;
		if (m->tj != sto_j)
			return (1);
		m->ti++;
		m->tot += m->tj;
	}
	m->lenght = m->tj;
	m->height = m->ti;
	return (0);
}

int	check_map(char **map, t_game *game, t_check *m)
{
	if (check_map_size_square(map, m) || m->height <= 1 || m->lenght <= 1)
		return (1);
	while (map[m->i])
	{
		m->j = 0;
		while (map[m->i][m->j])
		{
			if (map[0][m->j] != '1' || map[m->i][0] != '1' ||
					map[m->height - 1][m->j] != '1' ||
						map[m->i][m->lenght - 1] != '1')
				return (1);
			else if (map[m->i][m->j] != 'P' && map[m->i][m->j] != '1' &&
						map[m->i][m->j] != '0' && map[m->i][m->j] != 'C' &&
						map[m->i][m->j] != 'E')
				return (1);
			else if (map[m->i][m->j] == 'P')
				(m->player)++;
			m->j++;
		}
		m->i++;
	}
	if (m->player != 1 || check_path(map, game, m))
		return (1);
	return (0);
}
