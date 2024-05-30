/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:11:18 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/30 20:36:41 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	perr(char *str, int value)
{
	perror(str);
	exit(value);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i] == '\n' || ((s1[i] == s2[i]) && s1[i] && s2[i]))
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && s1[i] && s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	help(t_pip *pip, char **cmd, int value)
{
	char	*res;

	if (found_cmd(pip->path_env, pip, cmd[0]) == 1)
	{
		ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
		exit(127);
	}
	res = ft_strjoin(ft_strjoin(pip->path, "/"), cmd[0]);
	execve(res, cmd, pip->env);
	perror(cmd[0]);
	ft_free(cmd, count_words(pip->av[pip->index_av], ' '));
	ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	exit(value);
}
