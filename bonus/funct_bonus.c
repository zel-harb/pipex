/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:04:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/13 16:18:21 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	full_pip(t_pip *pip, char **av,int ac)
{
	pip->cmd1 = ft_split(av[2], ' ');
	pip->cmd2 = ft_split(av[ac - 1], ' ');
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
		return (0);
	}
	else
		return (1);
}

void	dup_close1(int fd, t_pip *pip, char **av,int ac)
{
	dup2(fd, 0);
	dup2(pip->pfd[1], 1);
	close(fd);
	close(pip->pfd[1]);
	close(pip->pfd[0]);
	full_pip(pip, av,ac);
}

void	dup_close2(int fd1, t_pip *pip, char **av,int *pfd,int j ,int ac)
{
	dup2(pfd[j - 2], 0);
	dup2(fd1, 1);
	close(fd1);
	close(pfd[j - 2]);
	close(pfd[j + 1]);
	full_pip(pip, av,ac);
}
