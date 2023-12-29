/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:25:39 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/15 12:53:53 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return ((void *)src);
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (source < destination)
	{
		while (n > 0)
		{
			destination[n - 1] = source[n - 1];
			n--;
		}
	}
	else
	{
		while (n-- > 0)
			*destination++ = *source++;
	}
	return (dest);
}
