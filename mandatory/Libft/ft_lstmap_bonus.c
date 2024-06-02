/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:45:24 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 01:45:49 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_node;
	void	*result;

	if (!lst || !f || !del)
		return (NULL);
	new_head = NULL;
	new_node = NULL;
	while (lst)
	{
		result = f(lst->content);
		new_node = ft_lstnew(result);
		if (new_node == NULL)
		{
			ft_lstclear(&new_head, del);
			del(result);
			return (NULL);
		}
		ft_lstadd_back(&new_head, new_node);
		lst = lst->next;
	}
	return (new_head);
}

// void del(void *ptr)
// {
// 	free(ptr);
// }

// void *upper(void *contenu)
// {
// 	char *buff = ft_strdup((char *)contenu);
// 	int i = -1;
// 	while (buff[++i])
// 		buff[i] -= 32;
// 	return (buff);
// }
// int main()
// {

// 	t_list *head = NULL;
// 	ft_lstadd_back(&head, ft_lstnew(strdup("abc")));
// 	ft_lstadd_back(&head, ft_lstnew(strdup("ggg")));
// 	ft_lstadd_back(&head, ft_lstnew(strdup("xxx")));

// 	t_list *new_head = ft_lstmap(head, upper, del);
// 	while (new_head)
// 	{
// 			printf("->  %s\n", new_head->content);
// 			new_head = new_head->next;
// 	}
// }