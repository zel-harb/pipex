/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/20 21:34:42 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_first_arg(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
	{
		exit(1);
	}
}

int	count(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	found_cmd(char **str, t_pip *pip, char *var)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		res = ft_strjoin(ft_strjoin(str[i], "/"),var);
		if (access(res, X_OK) != 0)
		{
			j++;
			if (j == count(str))
			{
				free(res);
				ft_putstr_fd("bash : command not found\n", 2);
				exit(127);
			}
		}
		else
		{
			pip->path = str[i];
			free(res);
			return ;
		}
		free(res);
		i++;
	}
}
