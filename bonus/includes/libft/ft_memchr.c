/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhaimy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:48:55 by idhaimy           #+#    #+#             */
/*   Updated: 2023/11/04 18:13:52 by idhaimy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;

	ss = (const unsigned char *)s;
	while (n-- > 0)
	{
		if (*ss == (unsigned char)c)
			return ((void *)ss);
		ss++;
	}
	return (NULL);
}
