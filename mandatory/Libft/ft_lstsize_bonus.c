/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:49:32 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 20:30:25 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (lst == NULL)
		return (0);
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	t_list	*he;

//   he = ft_lstnew("str0");
// 	ft_lstadd_front(&he,ft_lstnew("str1"));
// 	ft_lstadd_front(&he,ft_lstnew("str2"));
// 	ft_lstadd_front(&he,ft_lstnew("str3"));
// 	printf("**%d\n",ft_lstsize(he));
// 	while(he){
// 		printf("->%s\n",(char *) he->content);
// 		he =he->next;}
// }
