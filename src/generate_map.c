 /* ************************************************************************** */
 /*                                                                            */
 /*                                                        :::      ::::::::   */
 /*   generate_map.c                                     :+:      :+:    :+:   */
 /*                                                    +:+ +:+         +:+     */
 /*   By: bullestico <bullestico@student.42.fr>      +#+  +:+       +#+        */
 /*                                                +#+#+#+#+#+   +#+           */
 /*   Created: 2025/11/11 23:51:15 by bullestico        #+#    #+#             */
 /*   Updated: 2025/11/12 00:14:16 by bullestico       ###   ########.fr       */
 /*                                                                            */
 /* ************************************************************************** */

 #include "../includes/so_long.h"

// static void fill_one(t_game *game, int y)
// {
//     int x;

//     x = 0;
//     while (x < game->rd_num_x)
//         game->grid[y][x++] = '1';
// }
/*

TAB =
    0 = 0;
    1 = 1;
    2 = P;
    3 = E;
    4 = L
    5 = C;

ok donc si il faut avoir une map carre c la base on recoit ca

1111111111111111111
1?

on doit decider perso je prefere avoir un perso en premiere case
creation d un flag PLAYER pour la premiere case

ce flag est passer a un une fois la premiere passe de la fonction
au second appel il doit mettre un 0 si il ne mets pas de 0 le FLAG RESTE A 1 SINON IL PASSE A 2

maintenant on a ca

vu que le flag player est a 1 il ne peux plus reapparaitre (qu un seul player possible)

111111111111111111
1P0

supposons que nous avons un 0
le flag floor passe a 1 le flag rep reste a 0
on doit determiner le prochain char qui en prenant en compte mes flags rep et floor

du coup on doit avoir une formule qui va dire TRUE ou FALSE pour la repetition plus le chiffre est grand plus la chance devient faible au resultat mais doit 
quand meme avoir une tolerance pour eviter ce genre de cas

111111111111111111
1P01EC10101CC
*/

static char generate_char(t_game *game)
{
	char c;
	int r;

	r = rand() % 100;
	if (!game->proba->flag_player && r < 5)
	{
		game->proba->flag_player = 1;
		game->proba->rep = 0;
		return ('P');
	}
	if (!game->proba->has_exit && r > 95)
	{
		game->proba->has_exit = 1;
		game->proba->rep = 0;
		return ('E');
	}
	if (r < 50)
		c = '0';
	else if (r < 70)
		c = 'C';
	else
		c = '1';
	if (c == game->proba->grid_char_before)
		game->proba->rep++;
	else
		game->proba->rep = 0;
	return (c);
}

static void print_gen(t_game *game, int y, int x)
{
    mlx_put_image_to_window(game->mlx, game->win,
			game->textures->wall, x * 64, y * 64);
    // usleep(1e3);
    mlx_put_image_to_window(game->mlx, game->win,
			game->textures->floor, x * 64, y * 64);
    // usleep(1e3);
    mlx_put_image_to_window(game->mlx, game->win,
			game->textures->collectible, x * 64, y * 64);
    // usleep(1e3);
	if (game->grid[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->wall, x * 64, y * 64);
	else if (game->grid[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->floor, x * 64, y * 64);
	else if (game->grid[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->player_face, x * 64, y * 64);
	else if (game->grid[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->collectible, x * 64, y * 64);
	else if (game->grid[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->exit, x * 64, y * 64);
	else if (game->grid[y][x] == 'L')
				mlx_put_image_to_window(game->mlx, game->win,
					game->textures->lava, x * 64, y * 64);
    // usleep(1e4);
}

static int generate_line(t_game *game)
{
	int y;
	int x;

	y = 0;
    srand(time(NULL));
	while (y < game->rd_num_y)
	{
		x = 0;
		game->grid[y] = malloc(sizeof(char) * (game->rd_num_x + 1));
		if (!game->grid[y])
			return (1);
		while (x < game->rd_num_x)
		{
			if (y == 0 || y == game->rd_num_y - 1
				|| x == 0 || x == game->rd_num_x - 1)
				{
					game->grid[y][x] = '1';
					print_gen(game, y, x);
				}
			else
			{
				game->grid[y][x] = generate_char(game);
				game->proba->grid_char_before = game->grid[y][x];
                print_gen(game, y, x);
			}
			x++;
		}
		game->grid[y][x] = '\0';
		y++;
	}
	y = 0;
	while (y < game->rd_num_y)
	{
		printf("%s\n", game->grid[y]);
		y++;
	}
	return (0);
}

int generate(t_game *game)
{
	game->grid = ft_calloc(game->rd_num_y + 1, sizeof(char *));
	if (!game->grid)
		return (1);
	game->proba = (t_proba *)malloc(sizeof(t_proba));
	game->proba->flag_player = 0;
	game->proba->rep = 0;
	game->proba->grid_char_before = 0;
	game->proba->has_exit = 0;
	if (generate_line(game))
		return (1);
	return (0);
}

