/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/30 20:29:41 by zel-harb         ###   ########.fr       */
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

void	here_doc(t_pip *pip, int *pfd, int *pid, int ac)
{
	if (pip->path_env == NULL)
	{
		env_here_doc_null(pip, pid, pfd, ac);
		close_here_doc(pip, pfd, pid, ac);
	}
	else if (!pip->path_env[0])
	{
		env_here_doc_exp(pip, pid, pfd, ac);
		close_here_doc(pip, pfd, pid, ac);
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	}
	else
	{
		all_here(pip, pid, pfd, ac);
		close_here_doc(pip, pfd, pid, ac);
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	}
}

void	close_wait(t_pip *pip, int *pfd, int *pid, int ac)
{
	ft_close(pfd, pip->nbr_pip);
	wait_pid(pid, ac, pip);
}

void	mult_pipe(t_pip *pip, int *pfd, int *pid, int ac)
{
	if (pip->av == NULL)
	{
		env_null(pip, pid, pfd, ac);
		close_wait(pip, pfd, pid, ac);
	}
	else if (!pip->path_env[0])
	{
		env_null_exp(pip, pid, pfd, ac);
		close_wait(pip, pfd, pid, ac);
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	}
	else
	{
		all_cmd(pip, pid, pfd, ac);
		close_wait(pip, pfd, pid, ac);
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	}
}

int	main(int ac, char **av, char **env)
{
	t_pip	pip;
	int		pfd[(ac - 4) * 2];
	int		pid[ac - 3];

	full_pipe(&pip, av, ac, env);
	pip_pipe(pip, pfd);
	if (ft_cmp("here_doc", av[1]) == 0)
	{
		pipe(pip.pfd1);
		write_pipe(&pip);
		pip.index_av = pip.index_av + 1;
		here_doc(&pip, pfd, pid, ac);
		return (pip.value >> 8);
	}
	else if (pip.path_env == NULL)
		mult_pipe(&pip, pfd, pid, ac);
	return (pip.value >> 8);
}
