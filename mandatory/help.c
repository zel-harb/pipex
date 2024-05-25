/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 05:25:52 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/25 04:08:43 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	help_cmd1(t_pip *pip, int fd, char **env, char **av)
{
	char	*res;

	dup_close1(fd, pip, av);
	if (find(av[2]) == 0)
	{
		execve(pip->cmd1[0], pip->cmd1, env);
		perr("execve");
	}
	else if (ft_strncmp(av[2], "/", 1) == 0 || ft_strncmp(av[2], "./", 2) == 0)
	{
		ft_free(pip->cmd1, count_words(av[2], ' '));
		ft_free(pip->cmd2, count_words(av[3], ' '));
		ft_free(pip->path_env, count_words(get_path(env), ':'));
		perr(av[2]);
		exit(1);
	}
	found_cmd(pip->path_env, pip, pip->cmd1[0]);
	res = ft_strjoin(pip->path, "/");
	execve(ft_strjoin(res, pip->cmd1[0]), pip->cmd1, env);
	perr("execve");
	exit(1);
}

void	help_cmd2(t_pip *pip, int fd, char **env, char **av)
{
	char	*res;

	dup_close2(fd, pip, av);
	if (av[3][0] == '\0' || vide(av[3]) == 1)
	{
		ft_free(pip->cmd1, count_words(av[2], ' '));
		ft_free(pip->cmd2, count_words(av[3], ' '));
		ft_free(pip->path_env, count_words(get_path(env), ':'));
		ft_output(av[3], "  : command not found \n");
		exit(127);
	}
	 if (find(av[3]) == 0)
	{
		execve(pip->cmd2[0], pip->cmd2, env);
		perror(av[3]);
		exit(127);
	}
	else if (ft_strncmp(av[3], "/", 1) == 0 || ft_strncmp(av[3], "./", 2) == 0)
	{
		ft_free(pip->cmd1, count_words(av[2], ' '));
		ft_free(pip->cmd2, count_words(av[3], ' '));
		ft_free(pip->path_env, count_words(get_path(env), ':'));
		perr(av[3]);
		exit(127);
	}
	found_cmd(pip->path_env, pip, pip->cmd2[0]);
	res = ft_strjoin(pip->path, "/");
	execve(ft_strjoin(res, pip->cmd2[0]), pip->cmd2, env);
	perror("execve");
	exit(127);
}
