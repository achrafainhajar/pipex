/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aainhaja <aainhaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:23:37 by aainhaja          #+#    #+#             */
/*   Updated: 2021/11/15 04:33:38 by aainhaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	curr = ft_lstnew(f(lst->content));
	head = curr;
	lst = lst->next;
	while (lst)
	{
		curr->next = ft_lstnew(f(lst->content));
		if (!curr)
			ft_lstclear(&head, del);
		curr = curr->next;
		lst = lst->next;
	}
	return (head);
}
