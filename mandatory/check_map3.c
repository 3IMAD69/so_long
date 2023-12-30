/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 10:26:14 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/30 10:26:15 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**create_copy_map(char **map, int rows, int colums)
{
	char	**copy_map;
	int		i;

	i = 0;
	copy_map = (char **)malloc(rows * sizeof(char *));
	while (i < rows)
	{
		copy_map[i] = (char *)malloc(colums + 1 * sizeof(char));
		ft_strlcpy(copy_map[i], map[i], colums + 1);
		i++;
	}
	return (copy_map);
}

int	get_coins_count(char **real_map, int rows)
{
	int	i;
	int	j;
	int	coins;

	coins = 0;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (real_map[i][j] != '\0')
		{
			if (real_map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	return (coins);
}
