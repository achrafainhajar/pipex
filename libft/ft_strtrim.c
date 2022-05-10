/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:35:40 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/12 20:29:17 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = 0;
		i++;
	}
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		l;
	char	*str;

	if (!s1 || !set)
		return (0);
	l = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]) != 0 && s1[i])
		i++;
	while (ft_strchr(set, s1[l]) != 0 && s1[i])
		l--;
	str = malloc(sizeof(char) * (l - i) + 2);
	if (!str)
		return (0);
	return (ft_strnlcpy(str, s1 + i, l - i + 2));
}
