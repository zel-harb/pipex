/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:41:42 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/08 21:15:55 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmd(t_pip *pip, int *pfd)
{
	char	**cmd;

	pip->fd1 = open(pip->av[1], O_RDONLY);
	if (access(pip->av[1], F_OK) == -1 || access(pip->av[1], R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
		free(pip->pfd);
		free(pip->pid);
		perr(pip->av[1], 1);
	}
	else
	{
		dup2(pip->fd1, 0);
		dup2(pfd[1], 1);
		close(pip->fd1);
		ft_close(pfd, pip->nbr_pip);
		cmd = ft_split(pip->av[2], ' ');
		status(pip, cmd, 2, 1);
		help(pip, cmd, 1);
	}
}

void	last_cmd(t_pip *pip, int *pfd, int ac)
{
	char	*res;
	char	**cmd;
	char	*av;

	pip->fd2 = open(pip->av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	av = pip->av[ac - 1];
	if (pip->fd2 < 0)
	{
		ft_putstr_fd("bash: ", 2);
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
		free(pip->pfd);
		free(pip->pid);
		perror(pip->av[ac - 1]);
		exit(1);
	}
	dup2(pfd[pip->index_pip - 2], 0);
	dup2(pip->fd2, 1);
	close(pip->fd2);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	status(pip, cmd, pip->index_av, 127);
	help(pip, cmd, 127);
}

void	mid_cmd(t_pip *pip, int *pfd)
{
	char	*res;
	char	**cmd;

	dup2(pfd[pip->index_pip - 2], 0);
	dup2(pfd[pip->index_pip + 1], 1);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	status(pip, cmd, pip->index_av, 1);
	help(pip, cmd, 1);
}

void	all_cmd(t_pip *pip, int ac)
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
				first_cmd(pip, pip->pfd);
			else if (pip->index_av == ac - 2)
				last_cmd(pip, pip->pfd, ac);
			else
				mid_cmd(pip, pip->pfd);
		}
		pip->index_pip += 2;
		pip->index_av++;
		i++;
	}
}
