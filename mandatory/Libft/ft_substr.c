/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 01:09:19 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/26 09:51:35 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	size_t	i;
	char	*p;

	i = 0;
	if (s == NULL)
		return (0);
	l = ft_strlen(s);
	while (i + start < l && i < len)
		i++;
	p = malloc(i + 1);
	if (!p)
		return (0);
	l = 0;
	while (i > 0)
	{
		p[l++] = s[start++];
		i--;
	}
	p[l] = '\0';
	return (p);
}

// int	main(void)
// {
//    char const s[]="zahiraa";
//    char *ds =ft_substr(s,3,7);
//    if(ds != NULL)
//    {
//    printf("%s\n",ds);
//    free(ds);
//    }
//    else{
// 	printf("waloo");
//    }
//    return (0);
// }
