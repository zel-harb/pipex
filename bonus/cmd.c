/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:41:42 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/19 21:05:56 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(t_pip *pip, int *pfd)
{
	char	*res;
	char	**cmd;

	pip->fd1 = open(pip->av[1], O_RDONLY);
	if (access(pip->av[1], F_OK) == -1 || access(pip->av[1], R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(pip->av[1]);
		exit(1);
	}
	else
	{
		dup2(pip->fd1, 0);
		dup2(pfd[1], 1);
		close(pip->fd1);
		ft_close(pfd, pip->nbr_pip);
		cmd = ft_split(pip->av[2], ' ');
		if (find(pip->av[2]) == 0)
		{
			execve(cmd[0], cmd, pip->env);
			perr("execve");
		}
		else if (pip->av[2][0] == '\0' || vide(pip->av[2]) == 1)
		{
			ft_putstr_fd("bash : command not found \n", 2);
			exit(1);
		}
		else if (ft_strncmp(pip->av[2], "/", 1) == 0 || ft_strncmp(pip->av[2],
				"./", 2) == 0)
			perr(pip->av[2]);
		found_cmd(pip->path_env, pip, cmd[0]);
		res = ft_strjoin(pip->path, "/");
		execve(ft_strjoin(res, cmd[0]), cmd, pip->env);
		perror(cmd[0]);
		exit(1);
	}
}

void	last_cmd(t_pip *pip, int *pfd, int ac)
{
	char	*res;
	char	**cmd;

	pip->fd2 = open(pip->av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (access(pip->av[ac - 1], F_OK) == -1 || access(pip->av[ac - 1], R_OK) ==
		-1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(pip->av[ac - 1]);
		exit(1);
	}
	dup2(pfd[pip->index_pip - 2], 0);
	dup2(pip->fd2, 1);
	close(pip->fd2);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	if (find(pip->av[pip->index_av]) == 0)
	{
		execve(cmd[0], cmd, pip->env);
		perror(cmd[0]);
		exit(127);
	}
	else if (pip->av[pip->index_av][0] == '\0'
		|| vide(pip->av[pip->index_av]) == 1)
	{
		ft_putstr_fd("bash : command not found \n", 2);
		exit(127);
	}
	else if (ft_strncmp(pip->av[pip->index_av], "/", 1) == 0
		|| ft_strncmp(pip->av[pip->index_av], "./", 2) == 0)
		perr(pip->av[pip->index_av]);
	found_cmd(pip->path_env, pip, cmd[0]);
	res = ft_strjoin(pip->path, "/");
	execve(ft_strjoin(res, cmd[0]), cmd, pip->env);
	perror(cmd[0]);
	exit(127);
}


void	mid_cmd(t_pip *pip, int *pfd)
{
	char	*res;
	char	**cmd;

	dup2(pfd[pip->index_pip - 2], 0);
	dup2(pfd[pip->index_pip + 1], 1);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	if (find(pip->av[pip->index_av]) == 0)
	{
		execve(cmd[0], cmd, pip->env);
		perr("execve");
	}
	else if (pip->av[pip->index_av][0] == '\0'
		|| vide(pip->av[pip->index_av]) == 1)
	{
		ft_putstr_fd("bash : command not found \n", 2);
		exit(1);
	}
	else if (ft_strncmp(pip->av[pip->index_av], "/", 1) == 0
		|| ft_strncmp(pip->av[pip->index_av], "./", 2) == 0)
		perr(pip->av[pip->index_av]);
	found_cmd(pip->path_env, pip, cmd[0]);
	res = ft_strjoin(pip->path, "/");
	execve(ft_strjoin(res, cmd[0]), cmd, pip->env);
	perror(cmd[0]);
	exit(1);
}

void	all_cmd(t_pip *pip, int *pid, int *pfd, int ac)
{
	int	i;

	i = 0;
	while (pip->index_av < ac - 1)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (pip->index_av == 2)
				first_cmd(pip, pfd);
			else if (pip->index_av == ac - 2)
				last_cmd(pip, pfd, ac);
			else
				mid_cmd(pip, pfd);
		}
		pip->index_pip += 2;
		pip->index_av++;
		i++;
	}
}
