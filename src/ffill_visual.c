/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffill_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bullestico <bullestico@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:47:35 by bullestico        #+#    #+#             */
/*   Updated: 2025/11/11 16:37:39 by bullestico       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


//Creation de la fenetre pour le visualizer
void    init_winf(t_game *game)
{
    game->fmlx = mlx_init();
    game->winf = mlx_new_window(game->fmlx, game->height, game->length, "Checking...");
    ft_printf("zo\n");
}

//Affichage de la verification par algo
void    print_flood(char **grid, t_game *game)
{
	int	x;
	int	y;

	y = 0;
    ft_printf("zo\n");
	while (y < game->height)
	{
		x = 0;
		while (x < game->length)
		{
			if (grid[y][x] == 'F')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->fill, x * 64, y * 64);
			else if (grid[y][x] == 'U')
            {
           		mlx_put_image_to_window(game->fmlx, game->win,
					game->textures->prefill, x * 64, y * 64);
                    game->grid_bis[y][x] = 'F';  
            }
			else if (grid[y][x] == '0' || game->grid[y][x] == 'T')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->floor, x * 64, y * 64);
            else if (grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->wall, x * 64, y * 64);
			x++;
		}
		y++;
	}
    usleep(1e3);
}
