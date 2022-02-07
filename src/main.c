/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:28:05 by merlich           #+#    #+#             */
/*   Updated: 2022/01/21 23:11:16 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_key_hook(int keycode, t_fdf *params)
{
	if (keycode == 53)
	{
		mlx_destroy_image(params->mlx_ptr, params->img);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static void	ft_init(t_matrix *data, t_fdf *params, char *filename)
{
	params->zoom = 4;
	params->angle = 90.15;
	params->window_x = 1920;
	params->window_y = 1080;
	params->shift_x = params->window_x / 12;
	params->shift_y = params->window_y / 2;
	data->filename = filename;
	return ;
}

static void	ft_draw_map(t_matrix *data, t_fdf *params)
{
	params->mlx_ptr = mlx_init();
	params->win_ptr = mlx_new_window(params->mlx_ptr, params->window_x, \
									params->window_y, "FDF");
	params->img = mlx_new_image(params->mlx_ptr, params->window_x * 4, \
									params->window_y * 4);
	params->addr = mlx_get_data_addr(params->img, &params->bits_per_pixel, \
									&params->size_line, &params->endian);
	ft_draw(data, params);
	mlx_put_image_to_window(params->mlx_ptr, \
							params->win_ptr, params->img, 0, 0);
	mlx_hook(params->win_ptr, 02, 1L << 0, ft_key_hook, params);
	mlx_loop(params->mlx_ptr);
	return ;
}

int	main(int argc, char **argv)
{
	t_matrix	data1;
	t_fdf		params1;
	t_matrix	*data;
	t_fdf		*params;

	data = &data1;
	params = &params1;
	ft_init(data, params, argv[1]);
	if (argc == 2)
	{
		if (open(data->filename, O_RDONLY) == -1 || ft_read_file(data) == -1)
			return (-1);
		ft_draw_map(data, params);
	}
	return (0);
}
