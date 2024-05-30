/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_exp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:48:47 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/29 15:52:35 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmdh_exp(t_pip *pip, int *pfd)
{
	char	**cmd;

	dup2(pip->pfd1[0], 0);
	dup2(pfd[1], 1);
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[3], ' ');
	execve(cmd[0], cmd, pip->env);
	ft_putstr_fd("bash: ", 2);
	perror(cmd[0]);
	ft_free(cmd, count_words(pip->av[3], ' '));
    ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	exit(1);
}
void	last_cmdh_exp(t_pip *pip, int *pfd, int ac)
{
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
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	close(pip->fd2);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	execve(cmd[0], cmd, pip->env);
	ft_putstr_fd("bash: ", 2);
	perror(cmd[0]);
	ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
    ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	exit(127);
}
void	mid_cmdh_exp(t_pip *pip, int *pfd)
{
	char	*res;
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
    ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	exit(1);
}

void	env_here_doc_exp(t_pip *pip, int *pid, int *pfd, int ac)
{
	int i;

	i = 0;
	while (pip->index_av < ac - 1)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (pip->index_av == 3)
				first_cmdh_exp(pip, pfd);
			else if (pip->index_av == ac - 2)
				last_cmdh_exp(pip, pfd, ac);
			else
				mid_cmdh_exp(pip, pfd);
		}
		pip->index_pip += 2;
		pip->index_av++;
		i++;
	}
}