/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:53:28 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/08 21:17:28 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_pip *pip, int i)
{
	if (i == 0)
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	free(pip->pfd);
	free(pip->pid);
}

void	first_cmd_null(t_pip *pip, int *pfd, int i)
{
	int		fd1;
	char	**cmd;

	fd1 = open(pip->av[1], O_RDONLY);
	if (access(pip->av[1], F_OK) == -1 || access(pip->av[1], R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(pip->av[1]);
		free_all(pip, i);
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
		perror(cmd[0]);
		ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
		free_all(pip, i);
		exit(1);
	}
}

void	last_cmd_null(t_pip *pip, int *pfd, int ac, int i)
{
	int		fd2;
	char	**cmd;
	char	*av;

	fd2 = open(pip->av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	av = pip->av[ac - 1];
	if (fd2 < 0)
	{
		ft_putstr_fd("bash: ", 2);
		perror(pip->av[ac - 1]);
		free_all(pip, i);
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
	free_all(pip, i);
	exit(127);
}

void	mid_cmd_null(t_pip *pip, int *pfd, int i)
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
	free_all(pip, i);
	exit(1);
}

void	env_null(t_pip *pip, int ac, int j)
{
	int	i;

	i = 0;
	while (pip->index_av < ac - 1)
	{
		pip->pid[i] = fork();
		if (pip->pid[i] == -1)
			exit(1);
		if (pip->pid[i] == 0)
		{
			if (pip->index_av == 2)
				first_cmd_null(pip, pip->pfd, j);
			else if (pip->index_av == ac - 2)
				last_cmd_null(pip, pip->pfd, ac, j);
			else
				mid_cmd_null(pip, pip->pfd, j);
		}
		pip->index_pip += 2;
		pip->index_av++;
		i++;
	}
}
