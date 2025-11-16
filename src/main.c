/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:11:18 by apiscopo          #+#    #+#             */
/*   Updated: 2025/11/15 18:59:21 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_null(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->winf = NULL;
	game->grid = NULL;
	game->grid_bis = NULL;
	game->height = 0;
	game->length = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->pos_ex = 0;
	game->pos_ey = 0;
	game->coin = 0;
	game->move = 0;
	game->grid_c = 0;
	game->grid_e = 0;
	game->grid_l = 0;
	game->file = 0;
}

int	exit_param(void *param)
{
	(void)param;
	exit(0);
}

int	begin_render(t_game *game)
{
	int max;
	int min;

	max = 40;
	min = 40;
	put_null(game);
	game->rd_num_x = rand() % (max - min + 1) + min;
	game->rd_num_y = rand() % (max - min + 1) + min;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_printf("Error, impossible to init mlx\n"), 0);
	game->win = mlx_new_window(game->mlx, game->rd_num_x * 64,
			game->rd_num_y * 64 + 32, "so_long");
	if (!game->win)
		return (ft_printf("Error, impossible to init window\n"), 0);
	game->textures = (t_textures *)malloc(sizeof(t_textures));
	if (!game->textures)
		return (ft_printf("Error, impossible to create textures\n"), 0);
	get_images(game);
	generate(game);
	printf("SALADE DE MERDE\n");
	check_call(game);
	flood_fill(game, game->player_x, game->player_y);
	if (game->coin != game->grid_c || game->grid_e == 0 || game->grid_e > 4)
		return (begin_render(game));
	render_map(game);
	put_enemy(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2 || argc > 2)
	{
		ft_printf("usage: %s 'map'\n", argv[0]);
	}
	printf("SALADE DE MERDE\n");
	begin_render(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, exit_param, NULL);
	mlx_loop(game.mlx);
	free_resources(&game);
	return (1);
}
