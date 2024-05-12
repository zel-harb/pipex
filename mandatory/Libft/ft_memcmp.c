/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 01:31:10 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 15:14:58 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ds1;
	unsigned char	*ds2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	ds1 = (unsigned char *)s1;
	ds2 = (unsigned char *)s2;
	while (i < n)
	{
		if ((ds1[i] != ds2[i]))
			return (ds1[i] - ds2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	const char s1[] = "zahira";
// 	const char s2[] = "zatora";
// 	printf("%d\n", ft_memcmp(s1, s2, 3));
// 	//printf("%d\n", memcmp(s1, s2, 3));
// }