/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:30:22 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/04 21:30:22 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*str11;
	const unsigned char	*str22;

	str11 = (const unsigned char *)str1;
	str22 = (const unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (str11[i] != str22[i])
			return (str11[i] - str22[i]);
		i++;
	}
	return (0);
}
