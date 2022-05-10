/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:48:27 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/14 22:01:21 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char	*src, size_t	size)
{
	size_t	i;
	size_t	b;
	size_t	l;
	size_t	k;

	if (!dest && !size)
		return (ft_strlen(src));
	l = 0;
	b = ft_strlen(dest);
	k = ft_strlen(src);
	i = 0;
	if (size > b)
		l = k + b;
	else if (size <= b || !size)
		l = k + size;
	while (src[i] && b + 1 < size)
	{
		dest[b] = (char)src[i];
		i++;
		b++;
	}
	dest[b] = 0;
	return (l);
}
