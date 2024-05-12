/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:34:46 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 19:50:16 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char s[] = "zahira";
// 	//ft_bzero(s, 8);
// 	// printf("%s\n",s);
// 		bzero(s,2);
// 	printf("%s\n", s);
// }
