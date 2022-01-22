/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_atoi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:34:31 by merlich           #+#    #+#             */
/*   Updated: 2022/01/18 22:25:30 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_isspace(const char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\f' || str[*i] == '\n' || \
			str[*i] == '\r' || str[*i] == '\t' || str[*i] == '\v')
	{
		*i = *i + 1;
	}
	return ;
}

static void	ft_is_ox(const char *str, int *i)
{
	if (str[*i] == '0')
	{
		*i = *i + 1;
	}
	if ((str[*i] == 'x') || (str[*i] == 'X'))
	{
		*i = *i + 1;
	}
	return ;
}

unsigned long int	ft_hex_atoi(const char *str)
{
	int					i;
	int					j;
	unsigned long long	res;

	i = 0;
	j = 0;
	res = 0;
	if (str)
	{
		ft_isspace(str, &i);
		ft_is_ox(str, &i);
		while ((j < 8) && (str[i] != '\0') && (str[i] != '\n'))
		{
			if (str[i] >= '0' && str[i] <= '9')
				res = res * 16 + (str[i] - '0');
			else if (str[i] >= 'a' && str[i] <= 'f')
				res = res * 16 + (str[i] - 'W');
			else if (str[i] >= 'A' && str[i] <= 'F')
				res = res * 16 + (str[i] - '7');
			i++;
			j++;
		}
	}
	return (res);
}
