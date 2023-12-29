/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:11:26 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/10 18:25:28 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**freearray(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**write_to_arr(char const *s, char **arr, char *tmp_str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] != c)
	{
		arr[j] = ft_strdup(&tmp_str[0]);
		if (!arr[j])
			return (freearray(arr));
		j++;
	}
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1] != '\0'))
		{
			arr[j] = ft_strdup(&tmp_str[i + 1]);
			if (!arr[j])
				return (freearray(arr));
			j++;
		}
		i++;
	}
	arr[j] = 0;
	return (arr);
}

int	get_size(char const *s, char *tmp_str, char c)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
		{
			size++;
			tmp_str[i + 1] = '\0';
		}
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	*tmp_str;
	char	**arr;
	int		size;

	size = 0;
	if (!s)
		return (NULL);
	tmp_str = ft_strdup(s);
	if (!tmp_str)
		return (0);
	size = get_size(s, tmp_str, c);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
	{
		free(tmp_str);
		return (NULL);
	}
	if (size == 0)
		arr[0] = NULL;
	else
		arr = write_to_arr(s, arr, tmp_str, c);
	free(tmp_str);
	return (arr);
}

// #include <stdio.h>
// int main()
// {
//     char **strings;
//     int i  = 0;
//     strings = ft_split("shadow wizard money gang", ' ');
//      while (strings[i] != NULL) {
//         printf("%s\n", strings[i]);
//         i++;
//     }
//     for (int i = 0; strings[i] != NULL; ++i)
// 		free(strings[i]);
// 	free(strings);
//     return (0);
// }