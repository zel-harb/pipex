/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/27 15:48:20 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_first_arg(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit(1);
}

int	count(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	found_cmd(char **str, t_pip *pip, char *var)
{
	char	*res;
	char	*res2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		res = ft_strjoin(str[i], "/");
		res2 = ft_strjoin(res, var);
		if (access(res2 ,X_OK) != 0)
		{
			j++;
			if (j == count(str))
			{
				free(res);
				free(res2);
				ft_putstr_fd("bash : command not found\n", 2);
				return 1;
			}
		}
		else
		{
			pip->path = str[i];
			free(res);
			free(res2);
			return 0;
		}
		free(res);
		free(res2);;
		i++;
	}
	return 0;
}