/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:29:33 by merlich           #+#    #+#             */
/*   Updated: 2022/01/21 20:56:44 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_x_y(int a, int b, t_matrix *data)
{
	data->x = a;
	data->x1 = a + 1;
	data->y = b;
	data->y1 = b;
	return ;
}

void	ft_set_x1_y1(int a1, int b1, t_matrix *data)
{
	data->x = a1;
	data->x1 = a1;
	data->y = b1;
	data->y1 = b1 + 1;
	return ;
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int					res;
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *) s1;
	p2 = (const unsigned char *) s2;
	res = 0;
	i = 0;
	while ((i < n) && ((p1[i] != '\0') || (p2[i] != '\0')))
	{
		if (p1[i] != p2[i])
		{
			res = p1[i] - p2[i];
			break ;
		}
		i++;
	}
	return (res);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char *) b;
	while (i < len)
	{
		s1[i] = c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*ptr;

	len = count * size;
	ptr = malloc(len);
	if (NULL == ptr)
	{
		return (NULL);
	}
	else
	{
		ptr = ft_memset(ptr, '\0', len);
	}
	return (ptr);
}
