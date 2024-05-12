/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:54:44 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 19:50:44 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = next;
	}
	*lst = NULL;
}
/*void	del(void *c)
{
	t_list	*tmp;
	t_list	*next;

	free(c);
}*/
/*
int main (){
   char *str0 =ft_strdup("zooo");
   char *str1=ft_strdup("zoo1");
   char *str2=ft_strdup("zoo2");
	char *str3=ft_strdup("zoo3");
	t_list *he = ft_lstnew(str0);
	ft_lstadd_front(&he,ft_lstnew(str1));
	ft_lstadd_front(&he,ft_lstnew(str2));
	ft_lstadd_front(&he,ft_lstnew(str3));
	ft_lstclear(&he,del);
  while(he){
		printf("->%s\n",(char *) he->content);
		he =he->next;
	}

	}
*/
