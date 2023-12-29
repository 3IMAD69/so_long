/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:01:34 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/15 11:56:13 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	if (!dest && !src)
		return (0);
	if (src == dest)
		return ((void *)src);
	destination = (unsigned char *)dest;
	source = (unsigned char *)src;
	while (n-- > 0)
		*destination++ = *source++;
	return (dest);
}
