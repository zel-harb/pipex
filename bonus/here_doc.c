/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:58:10 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/03 14:56:21 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_cmdh(t_pip *pip, int *pfd)
{
	char	*res;
	char	**cmd;

	dup2(pip->pfd1[0], 0);
	dup2(pfd[1], 1);
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[3], ' ');
	status(pip, cmd, 3, 1);
	help(pip, cmd, 1);
}

void	last_cmdh(t_pip *pip, int *pfd, int ac)
{
	char	*res;
	char	**cmd;
	char	*av;

	pip->fd2 = open(pip->av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	av = pip->av[ac - 1];
	if (access(av, F_OK) == -1 || access(av, R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(pip->av[ac - 1]);
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
		free(pip->pfd);
		free(pip->pid);
		exit(1);
	}
	dup2(pfd[pip->index_pip - 2], 0);
	dup2(pip->fd2, 1);
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	close(pip->fd2);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	status(pip, cmd, pip->index_av, 127);
	help(pip, cmd, 127);
}

void	mid_cmdh(t_pip *pip, int *pfd)
{
	char	*res;
	char	**cmd;

	dup2(pfd[pip->index_pip - 2], 0);
	dup2(pfd[pip->index_pip + 1], 1);
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av], ' ');
	status(pip, cmd, pip->index_av, 1);
	help(pip, cmd, 1);
}

void	all_here(t_pip *pip, int *pid, int *pfd, int ac)
{
	int	i;

	i = 0;
	while (pip->index_av < ac - 1)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			if (pip->index_av == 3)
				first_cmdh(pip, pfd);
			else if (pip->index_av == ac - 2)
				last_cmdh(pip, pfd, ac);
			else
				mid_cmdh(pip, pfd);
		}
		pip->index_pip += 2;
		pip->index_av++;
		i++;
	}
}
