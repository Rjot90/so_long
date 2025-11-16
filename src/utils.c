/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 03:53:07 by apiscopo          #+#    #+#             */
/*   Updated: 2025/11/15 17:38:19 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_call(t_game *game)
{
	if (!check_map(game))
		return (0);
	if (!check_wall(game))
		return (0);
	if (check_coin(game) == 0)
		return (0);
	if (!check_double(game))
		return (0);
	if (!pos_player(game))
		return (0);
	if (!size_map(game))
		return (0);
	if (!check_flood(game))
		return (0);
	return (1);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->grid_bis[y][x] == 'P')
		game->grid_bis[y][x] = '0';
	if (x < 0 || y < 0 || (game->grid_bis[y][x] != '0'
		&& game->grid_bis[y][x] != 'E' && game->grid_bis[y][x] != 'C'
		&& game->grid_bis[y][x] != 'P' && game->grid_bis[y][x] != 'L'))
		return ;
	if (game->grid_bis[y][x] == '0')
		game->grid_bis[y][x] = 'U';
	if (game->grid_bis[y][x] == 'C')
	{
		game->grid_bis[y][x] = 'Q';
		game->grid_c++;
	}
	if (game->grid_bis[y][x] == 'L')
		game->grid_bis[y][x] = 'J';
	if (game->grid_bis[y][x] == 'E')
	{
		game->grid_e++;
		game->grid_bis[y][x] = 'U';
	}
	print_flood(game->grid_bis, game);
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
}

void	free_grid(char **grid)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	grid = NULL;
}

void	free_resources(t_game *game)
{
	if (game->textures->wall)
		mlx_destroy_image(game->mlx, game->textures->wall);
	if (game->textures->floor)
		mlx_destroy_image(game->mlx, game->textures->floor);
	if (game->textures->player_face)
		mlx_destroy_image(game->mlx, game->textures->player_face);
	if (game->textures->player_back)
		mlx_destroy_image(game->mlx, game->textures->player_back);
	if (game->textures->player_left)
		mlx_destroy_image(game->mlx, game->textures->player_left);
	if (game->textures->player_right)
		mlx_destroy_image(game->mlx, game->textures->player_right);
	if (game->textures->collectible)
		mlx_destroy_image(game->mlx, game->textures->collectible);
	if (game->textures->exit)
		mlx_destroy_image(game->mlx, game->textures->exit);
	if (game->textures->lava)
		mlx_destroy_image(game->mlx, game->textures->lava);
	free_ressources_grid(game);
}

void	free_ressources_grid(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	#ifdef _linux_
		if (game->win)
			mlx_destroy_display(game->mlx);
	# else
	if (game->mlx)
		free(game->mlx);
	if (game->textures)
		free(game->textures);
	free_grid(game->grid);
	free_grid(game->grid_bis);
}

#endif
