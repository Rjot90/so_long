/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffill_visual.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 20:47:35 by bullestico        #+#    #+#             */
/*   Updated: 2025/11/11 20:45:54 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Affichage specifique des texture proprio de l'algo
static void	print_flood2(char **grid, t_game *game, int x, int y)
{
	if (grid[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures->floor, x * 64, y * 64);
    else if (grid[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures->wall, x * 64, y * 64);
	else if (grid[y][x] == 'Q')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures->coinf, x * 64, y * 64);
	else if (grid[y][x] == 'J')
		mlx_put_image_to_window(game->mlx, game->win, game->textures->lavaf,
			 x * 64, y * 64);
}


//Affichage de la verification par algo
void    print_flood(char **grid, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->length)
		{
			if (grid[y][x] == 'F' || grid[y][x] == 'T')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->fill, x * 64, y * 64);
			else if (grid[y][x] == 'U')
            {
           		mlx_put_image_to_window(game->mlx, game->win,
					game->textures->prefill, x * 64, y * 64);
                    game->grid_bis[y][x] = 'F';  
            }
			print_flood2(grid, game, x, y);

			x++;
		}
		y++;
	}
    usleep(1e4);
}
