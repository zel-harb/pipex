/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/03 16:35:31 by zel-harb         ###   ########.fr       */
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

void	free_here(t_pip *pip)
{
	ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	free(pip->pfd);
	free(pip->pid);
}

void	here_doc(t_pip *pip, int ac)
{
	if (pip->path_env == NULL)
	{
		env_null(pip, pip->pid, pip->pfd, ac);
		close_here_doc(pip, pip->pfd, pip->pid, ac);
		free(pip->pfd);
		free(pip->pid);
	}
	else if (pip->path_env[0] == NULL)
	{
		env_null(pip, pip->pid, pip->pfd, ac);
		close_here_doc(pip, pip->pfd, pip->pid, ac);
		free_here(pip);
	}
	else
	{
		all_here(pip, pip->pid, pip->pfd, ac);
		close_here_doc(pip, pip->pfd, pip->pid, ac);
		free_here(pip);
	}
}

void	mult_pip(t_pip *pip, int ac)
{
	if (pip->path_env == NULL)
	{
		env_null(pip, pip->pid, pip->pfd, ac);
		ft_close(pip->pfd, pip->nbr_pip);
		wait_pid(pip->pid, ac, pip);
		free(pip->pfd);
		free(pip->pid);
	}
	else if (!pip->path_env[0])
	{
		env_null_exp(pip, pip->pid, pip->pfd, ac);
		ft_close(pip->pfd, pip->nbr_pip);
		wait_pid(pip->pid, ac, pip);
		free_here(pip);
	}
	else
	{
		all_cmd(pip, ac);
		ft_close(pip->pfd, pip->nbr_pip);
		wait_pid(pip->pid, ac, pip);
		free_here(pip);
	}
}

int	main(int ac, char **av, char **env)
{
	t_pip	pip;

	full_pipe(&pip, av, ac, env);
	
	pip_pipe(pip, pip.pfd);
	if (ft_cmp("here_doc", av[1]) == 0)
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
