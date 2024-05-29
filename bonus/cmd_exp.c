/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 00:36:56 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/27 00:37:12 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd_exp(t_pip *pip, int *pfd)
{
	int		fd1;
	char	**cmd;

	fd1 = open(pip->av[1], O_RDONLY);
	if (access(pip->av[1], F_OK) == -1 || access(pip->av[1], R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		// perr(pip->av[1], 1);
		perror(pip->av[1]);
		if (!pip->path_env[0])
			ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
		exit(1);
	}
	else
	{
		dup2(fd1, 0);
		dup2(pfd[1], 1);
		close(fd1);
		ft_close(pfd, pip->nbr_pip);
		cmd = ft_split(pip->av[2], ' ');
		execve(cmd[0], cmd, pip->env);
		ft_putstr_fd("bash: ", 2);
		// perr(cmd[0], 1);
		perror(cmd[0]);
		ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
		if (!pip->path_env[0])
			ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
		exit(1);
	}
}

void	last_cmd_exp(t_pip *pip, int *pfd, int ac)
{
	int		fd2;
	char	**cmd;

	fd2 = open(pip->av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (access(pip->av[ac - 1], F_OK) == -1 || access(pip->av[ac - 1], R_OK) ==
		-1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(pip->av[ac - 1]);
		if (!pip->path_env[0])
			ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
		exit(1);
	}
	dup2(pfd[pip->index_pip - 2], 0);
	dup2(fd2, 1);
	close(fd2);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	execve(cmd[0], cmd, pip->env);
	ft_putstr_fd("bash: ", 2);
	perror(cmd[0]);
	ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
	if (!pip->path_env[0])
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	exit(127);
}

void	mid_cmd_exp(t_pip *pip, int *pfd)
{
	char	**cmd;

	dup2(pfd[pip->index_pip - 2], 0);
	dup2(pfd[pip->index_pip + 1], 1);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	execve(cmd[0], cmd, pip->env);
	ft_putstr_fd("bash: ", 2);
	perror(cmd[0]);
	ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
	if (!pip->path_env[0])
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	exit(1);
}

void	env_null_exp(t_pip *pip, int *pid, int *pfd, int ac)
{
	int i;

	i = 0;
	while (pip->index_av < ac - 1)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (pip->index_av == 2)
				first_cmd_exp(pip, pfd);
			else if (pip->index_av == ac - 2)
				last_cmd_exp(pip, pfd, ac);
			else
				mid_cmd_exp(pip, pfd);
		}
		pip->index_pip += 2;
		pip->index_av++;
		i++;
	}
}