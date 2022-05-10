/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:31:51 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/04 21:31:51 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*s1, const char	*s2, size_t	n)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	if (s2[0] == '\0')
		return ((char *)s1 + (i - b));
	while (s1[i] && i < n)
	{
		b = 0;
		if (s1[i] == s2[b])
		{
			while ((s2[b] == s1[i]) && i < n && s2[b++] && s1[i++])
				if (s2[b] == '\0')
					return ((char *)s1 + (i - b));
		}
		i++;
		i = i - b;
	}
	return (0);
}
