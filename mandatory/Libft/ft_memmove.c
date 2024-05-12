/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:18:57 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 00:02:59 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (dest == src)
		return ((void *)src);
	if (s > d)
	{
		ft_memcpy(d, s, len);
	}
	if (s < d)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dest);
}
// #include <string.h>

// int	main(void)
// {
// 	char *s = "salut";
// 	printf("s -> %p  \n", s);
// 	printf("a -> %p  \n", s+1);
// }
