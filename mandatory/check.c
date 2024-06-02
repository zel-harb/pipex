/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/02 14:03:29 by zel-harb         ###   ########.fr       */
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
	char	*res2;

	ft_putstr_fd("str: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	res1 = ft_strjoin("bash : ", str);
	res2 = ft_strjoin(res1, res);
	ft_putstr_fd(res2, 2);
	free(res1);
	free(res2);
}

void	free_cnf(t_pip *pip, char *res, char *var)
{
	ft_output(var, " : command not found \n");
	free(res);
	ft_free(pip->cmd1, count_words(pip->av[2], ' '));
	ft_free(pip->cmd2, count_words(pip->av[3], ' '));
	ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	exit(127);
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
		res = double_strj(str[i], var);
		if (access(res, X_OK) != 0)
		{
			j++;
			if (j == count(str))
				free_cnf(pip, res, var);
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
