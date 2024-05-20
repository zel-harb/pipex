/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:11:18 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/20 16:44:38 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perr(char *str,int value)
{
	perror(str);
	exit(value);
}

int	ft_strcmp(char *s1,  char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i] == '\n' ||((s1[i] == s2[i]) && s1[i] && s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && s1[i] && s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
