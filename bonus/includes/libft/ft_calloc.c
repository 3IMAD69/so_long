/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 19:21:07 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/12 16:54:40 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > ((size_t)-1 / size))
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	else
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}
