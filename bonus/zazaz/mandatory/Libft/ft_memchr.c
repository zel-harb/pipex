/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 00:11:06 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 22:18:46 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*a;
	unsigned char		ic;
	size_t				i;

	a = s;
	ic = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (a[i] == ic)
			return ((void *)(a + i));
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*s;
// 	char		c;

// 	s = "zahira";
// 	c = 'r';
// 	printf("%s \n",ft_memchr(s, c, 6));
// 	//printf("%s\n", memchr(s, c, 20));
// }
