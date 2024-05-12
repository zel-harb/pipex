/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:44:19 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 15:23:01 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
// void	del(void* c)
// {
// 	free(c);
// }

// int	main(void)
// {
// 	char *str1= ft_strdup("zahira");
// 	char *str2 =ft_strdup("zooo");
// 	t_list *s1=ft_lstnew(str1);
// 	t_list *s2 =ft_lstnew(str2);
// 	printf("->%s\n",(char *) s1->content);
// 	printf("->%s\n",(char *) s2->content);
// 	ft_lstdelone(s2,del);
// 	ft_lstdelone(s1,del);
// 	printf("->%s\n",(char *) s1->content);
// 	printf("->%s\n",(char *) s2->content);
// }
