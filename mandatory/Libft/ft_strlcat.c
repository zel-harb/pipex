/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:25:47 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/27 15:05:02 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	if (!dest && !size)
		return (ft_strlen(src));
	i = 0;
	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && (i + dlen) < (size - 1))
	{
		dest[dlen + i] = src[i];
		i++;
	}
	dest[dlen + i] = '\0';
	return (dlen + slen);
}

// int	main(void)
// {
// 	char s[] = "salut";
// 	char d[10] = "non";
// 	// printf("%s\n%s\n", s, d);
// 	printf("%zu\n", ft_strlcat(NULL, s, 0));
// 	// printf("%s\n", d);
// }
