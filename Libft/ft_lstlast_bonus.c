/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:45:14 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 20:34:36 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;
	int		size;
	int		i;

	tmp = lst;
	i = 0;
	if (tmp == NULL)
		return (NULL);
	size = ft_lstsize(tmp);
	while (i < size - 1)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

/*
int	main(void)
{  t_list *he = ft_lstnew("str0");
	ft_lstadd_front(&he,ft_lstnew("str1"));
	ft_lstadd_front(&he,ft_lstnew("str2"));
	ft_lstadd_front(&he,ft_lstnew("str3"));
	while(he){
		printf("->%s\n",(char *) he->content);
		he =he->next;
	}

	//printf("**%d\n",ft_lstsize(he));
	t_list *h;
	h=ft_lstlast(he);
	printf("->%s\n",(char *)h->content);


}*/
