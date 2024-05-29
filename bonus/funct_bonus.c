/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:04:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/26 02:24:43 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	char	*str;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4) != 0)
		{
			str = ft_strnstr(env[i], "PATH", 4);
			return (str + 5);
		}
		i++;
	}
	return (NULL);
}

int	find(char *av)
{
	int		i;
	char	**v;

	i = 0;
	v = ft_split(av, ' ');
	if (access(v[0], X_OK) == 0)
	{
		ft_free(v, count_words(av, ' '));
		return (0);
	}
	else
	{
		ft_free(v, count_words(av, ' '));
		return (1);
	}
}
