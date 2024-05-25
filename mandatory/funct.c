/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:04:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/25 03:33:13 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	full_pip(t_pip *pip, char **av)
{
	pip->cmd1 = ft_split(av[2], ' ');
	pip->cmd2 = ft_split(av[3], ' ');
	pip->av = av ;
	pip->value = 0;
}

char	*get_path(char **env)
{
	char	*str;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH", 4) != 0)
		{
			str = ft_strnstr(env[i], "PATH", 4);
			return (str + 5);
		}
		i++;
	}
	return (NULL);
}

int	find(char *av)
{
	int		i;
	char	**v;

	i = 0;
	v = ft_split(av, ' ');
	if (access(v[0], X_OK) == 0)
	{
		ft_free(v,count_words(av,' '));
		return (0);
	}
	else
	{
		ft_free(v,count_words(av,' '));
		return (1);
	}
}

void	dup_close1(int fd, t_pip *pip, char **av)
{
	dup2(fd, 0);
	dup2(pip->pfd[1], 1);
	close(fd);
	close(pip->pfd[1]);
	close(pip->pfd[0]);
	full_pip(pip, av);
}

void	dup_close2(int fd1, t_pip *pip, char **av)
{
	dup2(pip->pfd[0], 0);
	dup2(fd1, 1);
	close(fd1);
	close(pip->pfd[0]);
	close(pip->pfd[1]);
	full_pip(pip, av);
}
