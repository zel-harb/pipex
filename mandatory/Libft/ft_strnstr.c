/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 09:07:45 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 00:41:12 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s && len == 0)
		return (NULL);
	if (!(*to_find))
		return ((char *)s);
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] == to_find[j] && to_find[j] && s[i + j] && i + j < len)
			j++;
		if (j == (size_t)ft_strlen(to_find))
			return ((char *)s + i);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	*ptr;

// 	char s1[30] = "lorem ipsum dolor sit amet";
// 	ptr = ft_strnstr(s1, "dolor", 15);
// 	printf("%s\n", ptr);
// 	// char* ptr1 = ft_strnstr(s1, "pine", 5);
// 	// printf("%s\n", ptr1);
// 	return (0);
// }
