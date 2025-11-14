/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo < apiscopo@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:39:26 by nopauli           #+#    #+#             */
/*   Updated: 2025/11/14 17:12:45 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_line(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		count++;
		free(line);
	}
	if (count <= 2)
		return (0);
	return (count);
}

int	pos_exit(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'E')
			{
				game->pos_ex = x;
				game->pos_ey = y;
				game->grid[y][x] = 'T';
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	pos_player(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			if (game->grid[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				game->grid[y][x] = '0';
				if (!pos_exit(game))
					return (0);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	fill_grid(int fd, int lines, t_game *game)
{
	char	*line;
	int		i;

	game->grid = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!game->grid)
		return (0);
	i = 0;
	while (i < lines)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		game->grid[i] = ft_strdup(line);
		free(line);
		if (!game->grid[i])
		{
			free_grid (game->grid);
			return (0);
		}
		i++;
	}
	game->grid[i] = NULL;
	return (1);
}

int	read_map(char *file)
{
	int		fd;
	int		n_line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	n_line = count_line(fd);
	if (n_line <= 2)
		return (0);
	close(fd);
	fd = open(file, O_RDONLY);
	return (1);
}
