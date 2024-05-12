/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:24:39 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/24 18:37:44 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ds;
	int		i;
	int		len;

	ds = (char *)s;
	i = 0;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
			return (ds + len);
		len--;
	}
	return (NULL);
}
//  int	main(void)
// {
// 	char	*s;
// 	char	c;

// 	s =  "";
// 	c = '\0';
// 	// printf("%s\n", ft_strrchr(s, c));
// 	printf("%s\n",strrchr(s, c)+1);
// }
