/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/25 05:47:53 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd(t_pip *pip, char **av, char **env)
{
	check_pip(pip);
	if (pip->pid == 0)
		child_cmd1(av, pip, env);
	else
		child_cmd2(av, pip, env);
	close_wait(pip);
}

int	main(int ac, char **av, char **env)
{
	t_pip	pip;

	if (ac != 5)
	{
		ft_putstr_fd("More/less arguments\n", 2);
		exit(1);
	}
	pipe(pip.pfd);
	pip.path_env = ft_split(get_path(env), ':');
	pip.env = env;
	if (!pip.path_env)
	{
		pip.pid = fork();
		null_env(av, &pip, env);
	}
	else if (!pip.path_env[0])
	{
		pip.pid = fork();
		null_env(av, &pip, env);
		ft_free(pip.path_env, count_words(get_path(pip.env), ':'));
		
	}
	else
	{
		cmd(&pip, av, env);
		ft_free(pip.path_env, count_words(get_path(env), ':'));
	}
	return (pip.value >> 8);
}
