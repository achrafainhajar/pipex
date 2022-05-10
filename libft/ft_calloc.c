/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:08:44 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/12 03:44:45 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	i;
	int	*str;

	i = 0;
	str = malloc(size * count);
	if (!str)
		return (0);
	ft_memset(str, 0, size * count);
	return (str);
}
