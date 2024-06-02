/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:44:52 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 20:29:30 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void f(void *c)
{
	char	*str;

  str = (char *)c;
   strcpy(str, "3");
}
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int	main(void)
{
	t_list	*he;

	he = ft_lstnew(strdup("str0"));
	ft_lstadd_front(&he, ft_lstnew(strdup("str1")));
	ft_lstadd_front(&he, ft_lstnew(strdup("str2")));
	ft_lstadd_front(&he, ft_lstnew(strdup("str3")));
	ft_lstiter(he, f);
	printf("\nModified List:\n");
   while (he)
	{
		printf("->%s\n", (char *)he->content);
		he = he->next;
	}
	return (0);
}
*/
