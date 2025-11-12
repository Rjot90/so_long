/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:29:34 by apiscopo          #+#    #+#             */
/*   Updated: 2025/11/11 20:33:21 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void get_images_flood(t_game *game)
{
	int width;
	int height;

	game->textures->fill = mlx_xpm_file_to_image(game->mlx, "textures/fill.xpm", 
        &width, &height);
    game->textures->prefill = mlx_xpm_file_to_image(game->mlx, 
        "textures/prefill.xpm", &width, &height);
	game->textures->coinf = mlx_xpm_file_to_image(game->mlx, "textures/coinf.xpm",
		 &width, &height);
	game->textures->lavaf = mlx_xpm_file_to_image(game->mlx, "textures/lavaf.xpm",
		&width, &height);
}

void	get_images(t_game *game)
{
	int	width;
	int	height;

	game->textures->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&width, &height);
	game->textures->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &width, &height);
	game->textures->collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &width, &height);
	game->textures->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm",
			&width, &height);
	game->textures->player_face = mlx_xpm_file_to_image(game->mlx,
			"textures/player_face.xpm", &width, &height);
	game->textures->player_back = mlx_xpm_file_to_image(game->mlx,
			"textures/player_back.xpm", &width, &height);
	game->textures->player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player_left.xpm", &width, &height);
	game->textures->player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right.xpm", &width, &height);
	game->textures->lava = mlx_xpm_file_to_image(game->mlx,
			"textures/lava.xpm", &width, &height);
	get_images_flood(game);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->length)
		{
			if (game->grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->wall, x * 64, y * 64);
			else if (game->grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->collectible, x * 64, y * 64);
			else if (game->grid[y][x] == '0' || game->grid[y][x] == 'T')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->floor, x * 64, y * 64);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures->player_face, game->player_x * 64, game->player_y * 64);
}

void	put_enemy(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->length)
		{
			if (game->grid[y][x] == 'L')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->lava, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
