/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:11:18 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/26 03:14:25 by zel-harb         ###   ########.fr       */
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
		child_cmd4(av, pip, env);
	close_wait(pip);
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
	write(2, ">>> here: ", 9);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	ft_putstr_fd("bash : ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": no such file or ..\n", 2);
}

void	close_wait(t_pip *pip)
{
	close(pip->pfd[0]);
	close(pip->pfd[1]);
	waitpid(pip->pid, &(pip->value), 0);
	waitpid(pip->pid1, &pip->value, 0);
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
