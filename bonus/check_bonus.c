/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/30 13:53:22 by zel-harb         ###   ########.fr       */
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
void ft_free_stra(char *str,char *res)
{
	free(str);
	free(res);
}
char *double_strjoin(char *str,char *var,t_pip *pip)
{
	char *res;
	char *res2;
	
	res = ft_strjoin(str, "/");
	res2 = ft_strjoin(res, var);
	free(res);
	return(res2);
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
		res = double_strjoin(str[i],var,pip);
		if (access(res, X_OK) != 0)
		{
			if (j++ == count(str))
			{
				free(res);
				ft_putstr_fd("bash : command not found\n", 2);
				return (1);
			}
		}
		else
		{
			pip->path = str[i];
			free(res);
			return (0);
		}
		free(res);
	}
	return (0);
}
