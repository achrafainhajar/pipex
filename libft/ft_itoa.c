/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:59:35 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/09 20:35:49 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_negpos(int b, int i)
{
	char	*str;

	if (b < 0)
	{
		b = b * -1;
		str = malloc(sizeof(char) * i + 2);
		if (!str)
			return (0);
		str[i + 1] = 0;
		str[0] = '-';
	}
	else
	{
		str = malloc(sizeof(char) * i + 1);
		if (!str)
			return (0);
		if (b == 0)
			str[0] = '0';
		str[i] = 0;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	k;

	k = (long) n;
	i = ft_count(k);
	str = ft_negpos(k, i);
	if (str == NULL)
		return (0);
	if (k < 0)
	{
		k = k * -1;
		while (k > 0)
		{
			str[i--] = k % 10 + 48;
			k = k / 10;
		}
	}
	while (k > 0)
	{
		str[i - 1] = k % 10 + 48;
		k = k / 10;
		i--;
	}
	return (str);
}
