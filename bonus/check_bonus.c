/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/30 14:17:53 by zel-harb         ###   ########.fr       */
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

char	*double_strjoin(char *str, char *var, t_pip *pip)
{
	char	*res;
	char	*res2;

	res = ft_strjoin(str, "/");
	res2 = ft_strjoin(res, var);
	free(res);
	return (res2);
}

void	free_put(char *res, char *str, int i, t_pip *pip)
{
	if (i == 0)
		ft_putstr_fd("bash : command not found\n", 2);
	else
		pip->path = str;
	free(res);
}

int	found_cmd(char **str, t_pip *pip, char *var)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = 1;
	while (str[i++])
	{
		res = double_strjoin(str[i], var, pip);
		if (access(res, X_OK) != 0)
		{
			if (j++ == count(str))
			{
				free_put(res, str[i], 0, pip);
				return (1);
			}
		}
		else
		{
			free_put(res, str[i], 1, pip);
			return (0);
		}
		free(res);
	}
	return (0);
}
