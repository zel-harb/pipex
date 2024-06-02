/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:58:10 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/27 18:10:52 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*p;

	len = ft_strlen(s1);
	i = 0;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
// int main()
// {    char s[]="zahhh";
// 	printf("%s\n",ft_strdup(s));
// 	printf("%s\n",strdup(s));

// }