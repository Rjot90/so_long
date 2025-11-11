/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 17:54:31 by apiscopo          #+#    #+#             */
/*   Updated: 2025/11/11 20:32:10 by apiscopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define BUFFER_SIZE 10
# include "../libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <unistd.h>

/* OS Detection */
# ifdef __APPLE__
#  define OS_MAC 1
# else
#  define OS_LINUX 1
# endif

/* Keycodes for Mac */
# ifdef OS_MAC
#  define KEY_W          13
#  define KEY_A          0
#  define KEY_S          1
#  define KEY_D          2
#  define KEY_M          46
#  define KEY_LEFT       123
#  define KEY_RIGHT      124
#  define KEY_ESC        53
#  include "../mlx/mlx_mac/mlx.h"
# endif

/* Keycodes for Linux */
# ifdef OS_LINUX
#  define KEY_W          119
#  define KEY_A           97
#  define KEY_S          115
#  define KEY_D          100
#  define KEY_M          109
#  define KEY_LEFT       65361
#  define KEY_RIGHT      65363
#  define KEY_ESC        65307
#  include "../mlx/mlx_linux/mlx.h"
# endif

typedef struct s_textures
{
	void	*player_face;
	void	*player_back;
	void	*player_left;
	void	*player_right;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit;
	void	*lava;
	void	*lavaf;
	void	*fill;
	void	*coinf;
	void	*prefill;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*fmlx;
	void		*win;
	void		*winf;
	char		**grid;
	char		**grid_bis;
	int			height;
	int			length;
	int			player_x;
	int			player_y;
	int			pos_ex;
	int			pos_ey;
	int			coin;
	int			move;
	int			grid_c;
	int			grid_e;
	int			grid_l;
	char		*file;
	t_textures	*textures;
}	t_game;

char	*get_next_line(int fd);
void	*gnl_calloc(size_t count, size_t size);
char	*gnl_strjoin(const char *s1, const char *s2);
size_t	gnl_strlen(const char *str);
char	*gnl_strchr(const char *str, int c);
char	*ft_free(char *buffer, char *buf);
char	*read_file(int fd, char *res);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);

int		ft_printf(const char *str, ...);
ssize_t	ft_putc(char c);
ssize_t	ft_putnbr(int n);
ssize_t	ft_putstr(char *str);
ssize_t	ft_putptr(void *ptr);
ssize_t	ft_putun(unsigned int n);
ssize_t	ft_puthex(unsigned int n, int index);
ssize_t	convert(const char *str, va_list *args);

int		begin_render(t_game *game);
int		check_call(int fd, int n_line, t_game *game, char *file);
int		read_map(char *file, t_game *game);
int		check_map(t_game *game);
int		check_wall(t_game *game);
int		check_coin(t_game *game);
int		size_map(t_game *game);
int		check_double(t_game *game);
int		count_line(int fd);
int		size_map(t_game *game);
int		get_line_length(char *line);
int		pos_player(t_game *game);
int		pos_exit(t_game *game);
int		fill_grid_bis(int fd, int lines, t_game *game);
int		fill_grid(int fd, int lines, t_game *game);
void    init_winf(t_game *game);
int		check_flood(int fd, int n_lines, t_game *game, char *file);
void    print_flood(char **grid, t_game *game);
void	flood_fill(t_game *game, int x, int y);

void	move_player(t_game *game, int dx, int dy);
void	move_player_two(t_game *game, int dx, int dy);
void	put_enemy(t_game *game);
void	render_map(t_game *game);
void	get_images(t_game *game);
int		handle_key(int keycode, t_game *game);
int		valid_move(t_game *game, int dx, int dy);

void	free_resources(t_game *game);
void	free_grid(char **grid);
void	put_null(t_game *game);
void	free_ressources_grid(t_game *game);

#endif