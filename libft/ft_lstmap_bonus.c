/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erikcousillas <erikcousillas@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:46:27 by erikcousill       #+#    #+#             */
/*   Updated: 2024/09/18 12:33:20 by erikcousill      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = malloc(sizeof(t_list));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_node->content = f(lst->content);
		new_node->next = NULL;
		if (new_list == NULL)
			new_list = new_node;
		else
			temp->next = new_node;
		temp = new_node;
		lst = lst->next;
	}
	return (new_list);
}
