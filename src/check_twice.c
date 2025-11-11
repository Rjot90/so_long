/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_twice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bullestico <bullestico@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:28:10 by apiscopo          #+#    #+#             */
/*   Updated: 2025/11/11 16:29:46 by bullestico       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_flood(int fd, int n_lines, t_game *game, char *file)
{
	close(fd);
	fd = open(file, O_RDONLY);
	if (!fill_grid_bis(fd, n_lines, game))
		return (0);
	return (1);
}

int	fill_grid_bis(int fd, int n_lines, t_game *game)
{
	char	*line;
	int		i;

	game->grid_bis = (char **)malloc(sizeof(char *) * (n_lines + 1));
	if (!game->grid_bis)
		return (0);
	i = 0;
	while (i < n_lines)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		game->grid_bis[i] = ft_strdup(line);
		free(line);
		if (!game->grid_bis[i])
			return (0);
		i++;
	}
	game->grid_bis[i] = NULL;
	return (1);
}

int	check_coin(t_game *game)
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
			if (game->grid[y][x] == 'C')
				game->coin++;
			x++;
		}
		y++;
	}
	return (game->coin);
}
