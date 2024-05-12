/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:13:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/12 09:43:20 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

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

int vide(char *av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(av[i])
	{
		if(av[i] == ' ')
			j++;
		i++;
	}
	
	if(j == ft_strlen(av))
		return (1);
	return (0);
}
