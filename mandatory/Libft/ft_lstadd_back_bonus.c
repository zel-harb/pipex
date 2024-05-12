/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:42:39 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 13:47:29 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (lst == NULL || new == NULL)
		return ;
	p = *lst;
	if (*lst)
	{
		p = ft_lstlast(p);
		p->next = new;
	}
	else
		*lst = new;
}

// int	main(void)
// {  t_list *he = NULL;
// 	ft_lstadd_front(&he,ft_lstnew("str1"));
// 	ft_lstadd_front(&he,ft_lstnew("str2"));
// 	ft_lstadd_front(&he,ft_lstnew("str3"));
// 	while(he){
// 		printf("->%s\n",(char *) he->content);
// 		he =he->next;
// 	}

// 	//printf("**%d\n",ft_lstsize(he));
// 		//h=ft_lstlast(he);
// 	//printf("->%s\n",(char *)h->content);

// 	t_list *h=ft_lstnew("zah");
// 	ft_lstadd_back(&he,h);
// 	while(he){
// 		printf("->%s\n",(char *) he->content);
// 		he =he->next;
// 	}

// }