#include "so_long.h"

static size_t	count_lines(char *path)// <- read_map()
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

char	**read_map(char *av)// <- game_init(game.c)
{
	int		fd;
	size_t	lines;
	char	**map;
	size_t	i;

	lines = count_lines(av);// -> ()
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
			free_map(map);// -> utils.c
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


void	init_vars(t_check *m)// <- check_map()
{
	m->i = 0;
	m->j = 0;
	m->check_i_p = 0;
	m->check_j_p = 0;
	m->check_i_e = 0;
	m->check_j_e = 0;
	m->tot_coin = 0;
	m->check_coin = 0;
	m->player = 0;
	m->exit = 0;
	m->wall = 0;
	m->tot = 0;
	m->n_ground = 0;
	m->lenght = 0;
	m->height = 0;
	m->result_err = 0;
}


int	check_map_size_square(char **map, t_check *m)// <- check_map()
{
	int	i;
	int	j;
	int	sto_j;

	i = 0;
	j = 0;
	sto_j = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '1'
				&& map[i][j] != '0' && map[i][j] != 'C')
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


int	check_map(char **map, t_game *game, t_check *m)// <- game_init(game.c)
{
	init_vars(m);// -> ()
	if (check_map_size_square(map, m) || m->height <= 1 || m->lenght <= 1)// -> ()
		exit_error("check_map_size_square", 1, game);// -> utils.c
	while (map[m->i] && m->result_err == 0)
	{
		m->j = 0;
		while (map[m->i][m->j] && m->result_err == 0)
		{
			if (map[0][m->j] != '1' || map[m->i][0] != '1' || map[m->height - 1][m->j] != '1'
					|| map[m->i][m->lenght - 1] != '1')
				exit_error("check_map - bord erreur", 1, game);// -> utils.c
			else if (map[m->i][m->j] != 'P' && map[m->i][m->j] != '1' && map[m->i][m->j] != '0' && map[m->i][m->j] != 'C' && map[m->i][m->j] != 'E')
				exit_error("check_map - caract", 1, game);
			else if (map[m->i][m->j] == 'P')
				(m->player)++;
			else if (map[m->i][m->j] == '0')
				(m->n_ground)++;
			m->j++;
		}
		m->i++;
	}
	if (m->player != 1 || /*m->exit != 1 ||*/check_path(map, game, m))// -> path.c
		exit_error("check_path", 1, game);// -> utils.c
	return (m->result_err);
}