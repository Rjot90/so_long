// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   generate_map.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bullestico <bullestico@student.42.fr>      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/11/11 23:51:15 by bullestico        #+#    #+#             */
// /*   Updated: 2025/11/12 00:14:16 by bullestico       ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/so_long.h"

// static int  generate_line(t_game *game)
// {
//     int x;
//     int y;
//     char *line;

//     x = 0;
//     y = 0;
//     while (y < game->rd_num_y)
//     {
//         x = 0;
//         while (x < game->rd_num_x)
//         {
//             //strdup aleatoire saud cas premiere et last line
//             x++;
//         }
//         y++;
//     }
    
// }

// int generate(t_game *game)
// {
//     int max;
//     int min;
//     int rd_num_x;
//     int rd_num_y;
    
//     max = 20;
//     min = 15;
//     game->rd_num_x = rand() % (max - min +1) + min;
//     game->rd_num_y = rand() % (max - min +1) + min;
    
//     game->grid = (char **)malloc(sizeof(char) * rd_num_y);
//     if (!game->grid)
//         return (1);
//     if (!generate_line(game))
//         return (1);
//     return (0);
// }
