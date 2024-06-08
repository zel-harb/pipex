/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:03:46 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/08 21:17:07 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmdh_null(t_pip *pip, int *pfd, int i)
{
	char	**cmd;

	dup2(pip->pfd1[0], 0);
	dup2(pfd[1], 1);
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	execve(cmd[0], cmd, pip->env);
	ft_putstr_fd("bash: ", 2);
	perror(cmd[0]);
	ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
	free_all(pip, i);
	exit(1);
}

void	last_cmdh_null(t_pip *pip, int *pfd, int ac, int i)
{
	char	**cmd;
	char	*av;

	pip->fd2 = open(pip->av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
	av = pip->av[ac - 1];
	if (pip->fd2 < 0)
	{
		ft_putstr_fd("bash: ", 2);
		perror(pip->av[ac - 1]);
		free_all(pip, i);
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
	ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
	free_all(pip, i);
	exit(127);
}

void	mid_cmdh_null(t_pip *pip, int *pfd, int i)
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
	ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
	free_all(pip, i);
	exit(1);
}

void	env_here_doc_null(t_pip *pip, int ac, int j)
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
			if (pip->index_av == 3)
				first_cmdh_null(pip, pip->pfd, j);
			else if (pip->index_av == ac - 2)
				last_cmdh_null(pip, pip->pfd, ac, j);
			else
				mid_cmdh_null(pip, pip->pfd, j);
		}
		pip->index_pip += 2;
		pip->index_av++;
		i++;
	}
}
