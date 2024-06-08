/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:28:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/08 06:01:02 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int *pfd, int nbr)
{
	int	i;

	i = 0;
	while (i < nbr * 2)
	{
		close(pfd[i]);
		i++;
	}
}

void	pip_pipe(t_pip pip, int *pfd)
{
	int	i;

	i = 0;
	while (i < pip.nbr_pip)
	{
		if (pipe(pfd + i * 2) == -1)
			exit(1);
		i++;
	}
}

void	full_pipe(t_pip *pip, char **av, int ac, char **env)
{
	if (ac < 5)
	{
		ft_putstr_fd("More/less arguments\n", 2);
		exit(1);
	}
	pip->av = av;
	pip->env = env;
	pip->path_env = ft_split(get_path(env), ':');
	if (ft_strcmp("here_doc", av[1]) == 0)
	{
		pip->pfd = malloc(sizeof(int) * (ac - 5) * 2);
		pip->pid = malloc(sizeof(int) * (ac - 4));
		pip->nbr_pip = ac - 5;
	}
	else
	{
		pip->pfd = malloc(sizeof(int) * (ac - 4) * 2);
		pip->pid = malloc(sizeof(int) * (ac - 3));
		pip->nbr_pip = ac - 4;
	}
	pip->index_av = 2;
	pip->index_pip = 0;
	pip->value = 0;
}

void	wait_pid(int *pid, int ac, t_pip *pip)
{
	int	i;

	i = 0;
	if (ft_strcmp("here_doc", pip->av[1]) == 0)
	{
		while (i < ac - 4)
		{
			waitpid(pid[i], &pip->value, 0);
			i++;
		}
	}
	else
	{
		while (i < ac - 3)
		{
			waitpid(pid[i], &pip->value, 0);
			i++;
		}
	}
}

int	ft_cmp(char *s1, char *name_moves)
{
	int	i;
	int	len1;
	int	len2;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(name_moves);
	while (name_moves[i] && s1[i])
	{
		if (name_moves[i] != s1[i])
		{
			return (1);
		}
		i++;
	}
	if (len1 == len2 - 1)
		return (0);
	else
		return (1);
}
