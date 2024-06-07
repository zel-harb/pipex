/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/07 20:40:10 by zel-harb         ###   ########.fr       */
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

void	free_double(char *res, char *res2)
{
	free(res);
	free(res2);
}

char	*str_join(char *str, char *var)
{
	char	*res;
	char	*res2;

	res = ft_strjoin(str, "/");
	res2 = ft_strjoin(res, var);
	free(res);
	return (res2);
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
		res = str_join(str[i], var);
		if (access(res, X_OK) != 0)
		{
			j++;
			if (j == count(str))
				ft_output_fnc(var, " : command not found \n", res, pip);
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
