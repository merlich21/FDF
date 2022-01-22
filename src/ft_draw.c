/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:46:55 by merlich           #+#    #+#             */
/*   Updated: 2022/01/21 21:25:28 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_my_mlx_pixel_put(t_fdf *params, int y, int x, int color)
{
	char	*dst;

	dst = params->addr + (x * params->size_line + \
						y * (params->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
	return ;
}

static void	ft_isometric(t_matrix *data, t_fdf *params)
{
	float	old_x;
	float	old_x1;
	float	old_y;
	float	old_y1;

	old_x = data->x;
	old_x1 = data->x1;
	old_y = data->y;
	old_y1 = data->y1;
	data->y = (data->x - data->y) * cos(params->angle);
	data->x = (data->x + data->y) * sin(params->angle) - \
				data->tab_altitudes[(int)old_x][(int)old_y];
	data->y1 = (data->x1 - data->y1) * cos(params->angle);
	data->x1 = (data->x1 + data->y1) * sin(params->angle) - \
				data->tab_altitudes[(int)old_x1][(int)old_y1];
}

static void	ft_set_params(t_matrix *data, t_fdf *params)
{
	data->x = data->x * params->zoom;
	data->y *= params->zoom;
	data->x1 *= params->zoom;
	data->y1 *= params->zoom;
	data->x += params->shift_x;
	data->y += params->shift_y;
	data->x1 += params->shift_x;
	data->y1 += params->shift_y;
	return ;
}

static void	ft_bresenham(t_matrix *data, t_fdf *params)
{
	float	delta_x;
	float	delta_y;
	float	delta_max;
	int		color;

	if (data->tab_colors[(int)data->x][(int)data->y] == 0)
		color = 0x00FFFFFF;
	else
		color = data->tab_colors[(int)data->x][(int)data->y];
	ft_isometric(data, params);
	ft_set_params(data, params);
	delta_x = data->x1 - data->x;
	delta_y = data->y1 - data->y;
	delta_max = fmax(fabs(delta_x), fabs(delta_y));
	delta_x /= delta_max;
	delta_y /= delta_max;
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		if (data->x < 0 || data->y < 0 || \
			data->x > params->window_x || data->y > params->window_y)
			break ;
		ft_my_mlx_pixel_put(params, data->y, data->x, color);
		data->x += delta_x;
		data->y += delta_y;
	}
}

void	ft_draw(t_matrix *data, t_fdf *params)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (i < data->rows - 1)
			{
				ft_set_x_y(i, j, data);
				ft_bresenham(data, params);
			}
			if (j < data->columns - 1)
			{
				ft_set_x1_y1(i, j, data);
				ft_bresenham(data, params);
			}
			j++;
		}
		i++;
	}
	return ;
}
