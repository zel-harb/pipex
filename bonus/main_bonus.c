/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/05 17:06:03 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_here_doc(t_pip *pip, int *pfd, int *pid, int ac)
{
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	ft_close(pfd, pip->nbr_pip);
	here_close_wait(pip);
	wait_pid(pid, ac, pip);
}

void	here_doc(t_pip *pip, int ac)
{
	if (pip->path_env == NULL)
	{
		env_here_doc_null(pip, ac, 1);
		close_here_doc(pip, pip->pfd, pip->pid, ac);
		free_all(pip, 1);
	}
	else if (pip->path_env[0] == NULL)
	{
		env_here_doc_null(pip, ac, 0);
		close_here_doc(pip, pip->pfd, pip->pid, ac);
		free_all(pip, 0);
	}
	else
	{
		all_here(pip, pip->pid, pip->pfd, ac);
		close_here_doc(pip, pip->pfd, pip->pid, ac);
		free_all(pip, 0);
	}
}

void	mult_pip(t_pip *pip, int ac)
{
	if (pip->path_env == NULL)
	{
		env_null(pip, ac, 1);
		ft_close(pip->pfd, pip->nbr_pip);
		wait_pid(pip->pid, ac, pip);
		free_all(pip, 1);
	}
	else if (!pip->path_env[0])
	{
		env_null(pip, ac, 0);
		ft_close(pip->pfd, pip->nbr_pip);
		wait_pid(pip->pid, ac, pip);
		free_all(pip, 0);
	}
	else
	{
		all_cmd(pip, ac);
		ft_close(pip->pfd, pip->nbr_pip);
		wait_pid(pip->pid, ac, pip);
		free_all(pip, 0);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pip	pip;

	if (ac < 5 || ft_strcmp("here_doc", av[1]) == 0 && ac < 6)
	{
		ft_putstr_fd("More/less arguments\n", 2);
		exit(1);
	}
	full_pipe(&pip, av, ac, env);
	pip_pipe(pip, pip.pfd);
	if (ft_strcmp("here_doc", av[1]) == 0)
	{
		pipe(pip.pfd1);
		write_pipe(&pip);
		pip.index_av = pip.index_av + 1;
		here_doc(&pip, ac);
	}
	else
	{
		mult_pip(&pip, ac);
	}
	return (pip.value >> 8);
}
