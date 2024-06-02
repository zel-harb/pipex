/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:58:06 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/26 17:24:33 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ds;
	int		i;
	int		len;

	ds = (char *)s;
	i = 0;
	len = ft_strlen(s) + 1;
	while (i < len)
	{
		if (s[i] == (char)c)
		{
			return (ds + i);
		}
		i++;
	}
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
//  int	main(void)
// {
// 	char	*s;
// 	char	c;

// 	s = "zahira\0harba";
// 	c = '\0';
// 	printf("%s\n", ft_strchr(s, c)+1);
// }
