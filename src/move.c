/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo < apiscopo@student.42lausanne.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:28:57 by apiscopo          #+#    #+#             */
/*   Updated: 2025/11/14 13:19:46 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	valid_move(t_game *game, int dx, int dy)
{
	if (game->grid[game->player_y + dy][game->player_x + dx] == '1')
		return (1);
	if (game->grid[game->player_y + dy][game->player_x + dx] == 'E' &&
		game->coin != 0)
		return (1);
	if (game->grid[game->player_y + dy][game->player_x + dx] == 'C')
	{
		game->coin--;
		game->grid[game->player_y + dy][game->player_x + dx] = '0';
	}
	if (game->grid[game->player_y + dy][game->player_x + dx] == 'T'
		&& game->coin == 0)
	{
		ft_printf("You win!\n");
		free_resources(game);
		exit(0);
	}
	if (game->grid[game->player_y + dy][game->player_x + dx] == 'L')
	{
		ft_printf("You lose!\n");
		free_resources(game);
		exit(0);
	}
	return (0);
}

void	move_player(t_game *game, int dx, int dy)
{
	char	*move;

	if (!valid_move(game, dx, dy))
	{
		move = ft_itoa(game->move);
		mlx_string_put(game->mlx, game->win,
			20, game->height * 64 + 20, 0x000000, move);
		free(move);
		move_player_two(game, dx, dy);
		game->move++;
		move = ft_itoa(game->move);
		ft_printf("move: %d\n", game->move);
		mlx_string_put(game->mlx, game->win,
			20, game->height * 64 + 20, 0xFFFFFF, move);
		free(move);
	}
	if (game->coin == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->textures->exit,
			game->pos_ex * 64, game->pos_ey * 64);
}

void	move_player_two(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + dx;
	new_y = game->player_y + dy;
	if (dx == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures->player_right,
			new_x * 64, new_y * 64);
	else if (dx == -1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures->player_left,
			new_x * 64, new_y * 64);
	else if (dy == 1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures->player_face,
			new_x * 64, new_y * 64);
	else if (dy == -1)
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures->player_back,
			new_x * 64, new_y * 64);
	mlx_put_image_to_window(game->mlx, game->win, game->textures->floor,
		game->player_x * 64, game->player_y * 64);
	game->player_x = new_x;
	game->player_y = new_y;
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		move_player(game, 0, -1);
	}
	else if (keycode == KEY_S)
	{
		move_player(game, 0, 1);
	}
	else if (keycode == KEY_A)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures->player_left, game->player_x * 64,
			game->player_y * 64);
		move_player(game, -1, 0);
	}
	else if (keycode == KEY_D)
	{
		move_player(game, 1, 0);
	}
	else if (keycode == KEY_ESC)
		free_resources(game);
	return (1);
}
