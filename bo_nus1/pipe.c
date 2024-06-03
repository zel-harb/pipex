/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:28:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/02 18:13:36 by zel-harb         ###   ########.fr       */
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
		pipe(pfd + i * 2);
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
	if(ft_cmp("here_doc", av[1]) == 0)
	{
		pip->pfd = malloc(sizeof(int) *(ac -5) * 2);
		pip->pid = malloc (sizeof(int) * (ac -4));
		pip->nbr_pip = ac - 5;
	}
	else
	{
		pip->pfd = malloc(sizeof(int) *(ac -4) * 2);
		pip->pid = malloc (sizeof(int) * (ac -3));
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
	if(ft_cmp("here_doc", pip->av[1]) == 0)
	{
	while (i < ac -4)
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

	i = 0;
	while (name_moves[i])
	{
		if (name_moves[i] != s1[i] && name_moves[i] != '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
void	write_pipe(t_pip *pip)
{
	char	*len;

	write(1, ">", 2);
	len = get_next_line(0);
	while (len && ft_cmp(pip->av[2], len) != 0)
	{
		write(pip->pfd1[1], len, ft_strlen(len));
		free(len);
		write(1, ">", 2);
		len = get_next_line(0);
	}
	free(len);
	get_next_line(-1);
}

void	here_close_wait(t_pip *pip)
{
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	waitpid(pip->pfd1[0], &pip->value, 0);
	waitpid(pip->pfd1[1], &pip->value, 0);
}