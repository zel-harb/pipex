/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/25 03:47:42 by zel-harb         ###   ########.fr       */
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

void	ft_output(char *str, char *res)
{
	char	*res1;
	char 	*res2;

	res1 = ft_strjoin("bash : ", str);
	res2 = ft_strjoin(res1, res);
	ft_putstr_fd(res2, 2);
	free(res1);
	free(res2);
}

void	found_cmd(char **str, t_pip *pip, char *var)
{
	char	*res;
	char *res2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		res = ft_strjoin(str[i], "/");
		res2 = ft_strjoin(res, var);
		if (access(res2, X_OK) != 0)
		{
			j++;
			if (j == count(str))
			{
				ft_output(var, " : command not found \n");
				free(res);
				free(res2);
				ft_free(pip->cmd1, count_words(pip->av[2], ' '));
				ft_free(pip->cmd2, count_words(pip->av[3], ' '));
	 			ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
				exit(127);
			}
		}
		else
		{
			pip->path = str[i];
			free(res);
			free(res2);
			return ;
		}
		free(res);
		free(res2);
		i++;
	}
}
