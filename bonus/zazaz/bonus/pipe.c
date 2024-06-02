/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:28:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/23 06:52:10 by zel-harb         ###   ########.fr       */
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
	if (ac > 5 || ac < 5)
	{
		ft_putstr_fd("More/less arguments\n", 2);
		exit(1);
	}
	pip->av = av;
	pip->env = env;
	pip->path_env = ft_split(get_path(env), ':');
	pip->nbr_pip = ac - 4;
	pip->index_av = 2;
	pip->index_pip = 0;
	pip->value = 0;
}

void	wait_pid(int *pid, int ac, t_pip *pip)
{
	int	i;

	i = 0;
	while (i < ac - 3)
	{
		waitpid(pid[i], &pip->value, 0);
		i++;
	}
}
int	ft_cmp(char *s1, char *name_moves)
{
	int	i;

	i = 0;
	while (name_moves[i])
	{
		if (name_moves[i] != s1[i] && name_moves[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
void	write_pipe(t_pip *pip)
{
	char	*len;

	len = get_next_line(0);
	while (len && ft_cmp(pip->av[2], len) != 0)
	{
		write(pip->pfd1[1], len, ft_strlen(len));
		len = get_next_line(0);
	}
}
void	here_close_wait(t_pip *pip)
{
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	waitpid(pip->pfd1[0], &pip->value, 0);
	waitpid(pip->pfd1[1], &pip->value, 0);
}