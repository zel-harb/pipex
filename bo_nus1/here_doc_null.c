/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:03:46 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/02 17:43:36 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmdh_null(t_pip *pip, int *pfd)
{
	char	**cmd;

	dup2(pip->pfd1[0], 0);
	dup2(pfd[1], 1);
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[2], ' ');
	execve(cmd[0], cmd, pip->env);
	ft_putstr_fd("bash: ", 2);
	perr(cmd[0], 1);
}

void	last_cmdh_null(t_pip *pip, int *pfd, int ac)
{
	int		fd2;
	char	**cmd;

	fd2 = open(pip->av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (access(pip->av[ac - 1], F_OK) == -1 || access(pip->av[ac - 1], R_OK) ==
		-1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(pip->av[ac - 1]);
		exit(1);
	}
	dup2(pfd[pip->index_pip - 2], 0);
	dup2(pip->fd2, 1);
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	close(pip->fd2);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	execve(cmd[0], cmd, pip->env);
	ft_putstr_fd("bash: ", 2);
	perror(cmd[0]);
	exit(127);
}

void	mid_cmdh_null(t_pip *pip, int *pfd)
{
	char	**cmd;

	dup2(pfd[pip->index_pip - 2], 0);
	dup2(pfd[pip->index_pip + 1], 1);
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	execve(cmd[0], cmd, pip->env);
	ft_putstr_fd("bash: ", 2);
	perror(cmd[0]);
	exit(1);
}

void	env_here_doc_null(t_pip *pip, int *pid, int *pfd, int ac)
{
	int i;

	i = 0;
	while (pip->index_av < ac - 1)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (pip->index_av == 2)
				first_cmdh_null(pip, pfd);
			else if (pip->index_av == ac - 2)
				last_cmdh_null(pip, pfd, ac);
			else
				mid_cmdh_null(pip, pfd);
		}
		pip->index_pip += 2;
		pip->index_av++;
		i++;
	}
}