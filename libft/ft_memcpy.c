/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:38:59 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/12 03:20:13 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest1;
	unsigned const char	*src1;
	size_t				i;

	i = 0;
	dest1 = (unsigned char *) dest;
	src1 = (unsigned const char *) src;
	if (dest == src)
		return (dest);
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
