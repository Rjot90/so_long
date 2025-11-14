/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_twice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo < apiscopo@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:28:10 by apiscopo          #+#    #+#             */
/*   Updated: 2025/11/14 17:10:05 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_flood(t_game *game)
{
	if (!fill_grid_bis(game))
		return (0);
	return (1);
}

int	fill_grid_bis(t_game *game)
{
	int		i;

	game->grid_bis = (char **)malloc(sizeof(char *) * (game->rd_num_y + 1));
	if (!game->grid_bis)
		return (0);
	i = 0;
	while (i < game->rd_num_y)
	{
		game->grid_bis[i] = ft_strdup(game->grid[i]);
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
