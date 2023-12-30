/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:18:52 by idhaimy           #+#    #+#             */
/*   Updated: 2023/12/26 17:30:07 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	add_buffer_to_list(t_list **lst, char *buffer)
{
	t_list	*newnode;
	t_list	*lastnode;

	lastnode = ft_lstlast(*lst);
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return ;
	if (!lastnode)
		*lst = newnode;
	else
		lastnode->next = newnode;
	newnode->str = buffer;
	newnode->next = NULL;
}

int	found_newline(t_list *lst)
{
	int	i;

	if (NULL == lst)
		return (0);
	while (lst)
	{
		i = 0;
		while (lst->str[i])
		{
			if (lst->str[i] == '\n' || lst->str[i] == '\0')
				return (1);
			++i;
		}
		lst = lst->next;
	}
	return (0);
}

void	read_to_list(t_list **lst, int fd)
{
	char	*buffer;
	ssize_t	byte_read;

	while (!found_newline(*lst))
	{
		buffer = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
		if (!buffer)
			return ;
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (!byte_read || byte_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[byte_read] = '\0';
		add_buffer_to_list(lst, buffer);
	}
}

char	*get_linee(t_list *lst)
{
	char	*myline;
	int		line_count;

	line_count = count_my_line(lst);
	myline = (char *)malloc((sizeof(char) * line_count) + 1);
	if (!myline)
		return (NULL);
	copy_lstline(lst, myline);
	return (myline);
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;
	t_list			*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 0x7fffffff)
		return (NULL);
	if (read(fd, &line, 0) < 0)
	{
		while (lst)
		{
			tmp = lst->next;
			free(lst->str);
			free(lst);
			lst = tmp;
		}
		lst = NULL;
		return (NULL);
	}
	read_to_list(&lst, fd);
	if (!lst)
		return (NULL);
	line = get_linee(lst);
	clearlst(&lst);
	return (line);
}
