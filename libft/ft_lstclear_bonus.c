/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 23:05:27 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/14 21:09:41 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void*))
{
	t_list	*tab;
	t_list	*temp;

	tab = *lst;
	temp = tab;
	while (temp != NULL)
	{
		tab = tab->next;
		del(temp->content);
		free(temp);
		temp = tab;
	}
	*lst = NULL;
}
