/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 20:34:25 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/12 03:18:32 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s1, int c, size_t n)
{
	unsigned char	*str;

	str = s1;
	while (n != 0)
	{
		*str = (unsigned char)c;
		str++;
		n--;
	}
	return (s1);
}
