/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 22:19:51 by merlich           #+#    #+#             */
/*   Updated: 2022/01/22 22:52:33 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct s_matrix
{
	char	*filename;
	int		rows;
	int		columns;
	int		**tab_altitudes;
	int		**tab_colors;
	float	x;
	float	y;
	float	x1;
	float	y1;
}	t_matrix;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;

	int		window_x;
	int		window_y;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		zoom;
	int		shift_x;
	int		shift_y;
	double	angle;
}	t_fdf;

int				ft_read_file(t_matrix *data);
void			ft_draw(t_matrix *data, t_fdf *params);
void			ft_free_matrix_rows(int **matrix, int rows);
int				ft_atoi(const char *str);
unsigned int	ft_hex_atoi(const char *str);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*get_next_line(int fd);
size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strjoin(char *s1, char const	*s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			ft_strdup(const char *str, char *ptr);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			ft_set_x_y(int a, int b, t_matrix *data);
void			ft_set_x1_y1(int a, int b, t_matrix *data);

#endif
