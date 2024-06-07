/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:04:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/07 20:29:26 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		ft_free(v, count_words(av, ' '));
		return (0);
	}
	else
	{
		ft_free(v, count_words(av, ' '));
		return (1);
	}
}

void	help(t_pip *pip, char **cmd, int value)
{
	char	*res;
	char	*av;

	av = pip->av[pip->index_av];
	if (av[ft_strlen(av) - 1] == '\n')
	{
		ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
		free_all(pip, 0);
		exit(127);
	}
	else if (found_cmd(pip->path_env, pip, cmd[0]) == 1)
	{
		ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
		free_all(pip, 0);
		exit(127);
	}
	res = ft_strjoin(ft_strjoin(pip->path, "/"), cmd[0]);
	execve(res, cmd, pip->env);
	perror(cmd[0]);
	ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
	ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	exit(value);
}

void	status(t_pip *pip, char **cmd, int i, int value)
{
	if (find(pip->av[i]) == 0)
	{
		execve(cmd[0], cmd, pip->env);
		perr("execve", value);
	}
	else if (pip->av[i][0] == '\0' || vide(pip->av[i]) == 1)
	{
		ft_putstr_fd("bash : : command not found \n", 2);
		exit(value);
	}
	else if (ft_strncmp(pip->av[i], "/", 1) == 0 || ft_strncmp(pip->av[i], "./",
			2) == 0)
	{
		ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
		free(pip->pfd);
		free(pip->pid);
		perr(pip->av[i], value);
	}
}

void	here_close_wait(t_pip *pip)
{
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	waitpid(pip->pfd1[0], &pip->value, 0);
	waitpid(pip->pfd1[1], &pip->value, 0);
}
