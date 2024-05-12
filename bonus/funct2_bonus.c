/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:11:18 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/11 21:16:51 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	null_env(char **av, t_pip *pip, char **env)
{
	if (pip->pid == 0)
	{
		child_cmd3(av, pip, env);
	}
	else
	{
		child_cmd4(av, pip, env);
		close_wait(pip);
	}
}

void	check_pip(t_pip *pip)
{
	if (pipe(pip->pfd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pip->pid = fork();
	if (pip->pid < 0)
	{
		perror("fork fail");
		exit(1);
	}
}

void	perr(char *str)
{
	perror(str);
	exit(1);
}

void	close_wait(t_pip *pip)
{
	close(pip->pfd[0]);
	close(pip->pfd[1]);
	waitpid(pip->pid, NULL, 0);
	waitpid(pip->pid1, NULL, 0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && s1[i] && s2[i] && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
