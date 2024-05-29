/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/28 21:47:14 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		if (pip.path_env == NULL)
		{
			// env_null(&pip, pid, pfd, ac);
			// dprintf(2, "klsajksaajmxzasl");
			env_here_doc_null(&pip, pid, pfd, ac);
			here_close_wait(&pip);
		}
		else
		{
			// dprintf(2,"hiii\n");
			all_here(&pip, pid, pfd, ac);
			here_close_wait(&pip);
			ft_free(pip.path_env, count_words(get_path(env), ':'));
		}
		// here_close_wait(&pip);
		return (pip.value >> 8);
	}
	else if (pip.path_env == NULL)
	{
		env_null(&pip, pid, pfd, ac);
		ft_close(pfd, pip.nbr_pip);
		wait_pid(pid, ac, &pip);
	}
	else if (!pip.path_env[0])
	{
		env_null_exp(&pip, pid, pfd, ac);
		ft_close(pfd, pip.nbr_pip);
		wait_pid(pid, ac, &pip);
		ft_free(pip.path_env, count_words(get_path(env), ':'));
	}
	else
	{
		all_cmd(&pip, pid, pfd, ac);
		ft_close(pfd, pip.nbr_pip);
		wait_pid(pid, ac, &pip);
		ft_free(pip.path_env, count_words(get_path(env), ':'));
	}
	return (pip.value >> 8);
}
