/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:35:25 by merlich           #+#    #+#             */
/*   Updated: 2022/01/21 23:04:36 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* ft_row_count function 
counts the number of rows in the matrix */

static void	ft_rows_n_columns_count(t_matrix *data)
{
	int		fd;
	int		flag;
	char	*line;
	char	**tab;

	flag = 0;
	data->rows = 0;
	data->columns = 0;
	fd = open(data->filename, O_RDONLY);
	line = get_next_line(fd);
	tab = ft_split(line, ' ');
	while (line)
	{
		data->rows++;
		while ((tab) && (tab[data->columns]) && (flag == 0))
		{
			free(tab[data->columns]);
			data->columns++;
		}
		flag = 1;
		free(line);
		line = get_next_line(fd);
	}
	free(tab);
	close(fd);
}

/* ft_create_matrix creates matrix*/

static int	**ft_create_matrix(t_matrix *data)
{
	int	i;
	int	**matrix;

	i = 0;
	matrix = (int **)ft_calloc(sizeof(int *), (data->rows + 1));
	if (NULL == matrix)
		return (NULL);
	while (i < data->rows + 1)
	{
		matrix[i] = (int *)ft_calloc(sizeof(int), (data->columns));
		if (NULL == matrix[i])
		{
			while (i > 0)
			{
				i--;
				free(matrix[i]);
			}
			free(matrix);
			return (NULL);
		}
		i++;
		matrix[i] = NULL;
	}
	return (matrix);
}

/* ft_create_matrix creates matrix*/

void	ft_free_matrix_rows(int **matrix, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	return ;
}

/* ft_fill_matrix fills matrix according to input file (map) */

static void	ft_fill_matrix(int i, t_matrix *data, char *line)
{
	int		j;
	char	**row;
	char	**elem;

	j = 0;
	elem = NULL;
	row = ft_split(line, ' ');
	if (NULL == row)
		return ;
	while (row[j])
	{
		data->tab_altitudes[i][j] = ft_atoi(row[j]);
		elem = ft_split(row[j], ',');
		if (elem[1])
		{
			data->tab_colors[i][j] = ft_hex_atoi(elem[1]);
			free(elem[1]);
		}
		free(elem[0]);
		free(elem);
		free(row[j]);
		j++;
	}
	free(row);
	return ;
}

/* ft_get_matrix_from_file function transforms
the input file in the matrix */

int	ft_read_file(t_matrix *data)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	ft_rows_n_columns_count(data);
	data->tab_altitudes = ft_create_matrix(data);
	if (NULL == data->tab_altitudes)
		return (-1);
	data->tab_colors = ft_create_matrix(data);
	if (NULL == data->tab_colors)
		return (-1);
	fd = open(data->filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		ft_fill_matrix(i, data, line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
