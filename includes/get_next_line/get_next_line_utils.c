/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:50:12 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/25 10:45:57 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

int	count_my_line(t_list *lst)
{
	int	len;
	int	i;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->str[i])
		{
			if (lst->str[i] == '\n')
			{
				len++;
				return (len);
			}
			len++;
			i++;
		}
		lst = lst->next;
	}
	return (len);
}

void	copy_lstline(t_list *lst, char *line)
{
	int	i;
	int	j;

	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->str[i])
		{
			if (lst->str[i] == '\n')
			{
				line[j++] = '\n';
				line[j] = '\0';
				return ;
			}
			line[j++] = lst->str[i++];
		}
		lst = lst->next;
	}
	line[j] = '\0';
}

void	free_all(t_list *newnode, char *buf, t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (!newnode->str[0])
	{
		free(buf);
		free(newnode);
	}
	else
		*list = newnode;
}

void	clearlst(t_list **lst)
{
	t_list	*newnode;
	t_list	*lastnode;
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newstr || !newnode)
		return ;
	lastnode = ft_lstlast(*lst);
	while (lastnode->str[i] && lastnode->str[i] != '\n')
		i++;
	while (lastnode->str[i] && lastnode->str[++i])
		newstr[j++] = lastnode->str[i];
	newstr[j] = '\0';
	newnode->str = newstr;
	newnode->next = NULL;
	free_all(newnode, newstr, lst);
}
