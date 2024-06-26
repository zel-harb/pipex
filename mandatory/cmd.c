/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 03:14:03 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/08 21:14:22 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_cmd3(char **av, t_pip *pip, char **env, int i)
{
	int		fd;
	char	*res;

	fd = open(av[1], O_RDONLY);
	if (access(av[1], F_OK) == -1 || access(av[1], R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(av[1]);
		if (i == 0)
			ft_free(pip->path_env, count_words(get_path(env), ':'));
		exit(1);
	}
	else
	{
		dup_close1(fd, pip, av);
		execve(pip->cmd1[0], pip->cmd1, env);
		ft_putstr_fd("bash: ", 2);
		perror(pip->cmd1[0]);
		ft_free(pip->cmd1, count_words(av[2], ' '));
		ft_free(pip->cmd2, count_words(av[3], ' '));
		if (i == 0)
			ft_free(pip->path_env, count_words(get_path(env), ':'));
		exit(1);
	}
}

void	child_cmd4(char **av, t_pip *pip, char **env, int i)
{
	int		fd1;
	char	*res1;

	pip->pid1 = fork();
	if (pip->pid1 == 0)
	{
		fd1 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (access(av[4], F_OK) == -1 || access(av[4], R_OK) == -1)
		{
			ft_putstr_fd("bash: ", 2);
			perror(av[4]);
			if (i == 0)
				ft_free(pip->path_env, count_words(get_path(env), ':'));
			exit(1);
		}
		dup_close2(fd1, pip, av);
		execve(pip->cmd2[0], pip->cmd2, env);
		ft_putstr_fd("bash: ", 2);
		perror(pip->cmd2[0]);
		ft_free(pip->cmd1, count_words(av[2], ' '));
		ft_free(pip->cmd2, count_words(av[3], ' '));
		if (i == 0)
			ft_free(pip->path_env, count_words(get_path(env), ':'));
		exit(127);
	}
}

void	child_cmd1(char **av, t_pip *pip, char **env)
{
	int		fd;
	char	*res;

	fd = open(av[1], O_RDONLY);
	if (access(av[1], F_OK) == -1 || access(av[1], R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(av[1]);
		ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
		exit(1);
	}
	else if (av[2][0] == '\0' || vide(av[2]) == 1)
	{
		ft_free(pip->path_env, count_words(get_path(env), ':'));
		ft_output(av[2], "  : command not found \n");
		exit(1);
	}
	else
		help_cmd1(pip, fd, env, av);
}

void	child_cmd2(char **av, t_pip *pip, char **env)
{
	int		fd1;
	char	*res1;

	pip->pid1 = fork();
	if (pip->pid1 == -1)
		exit(1);
	if (pip->pid1 == 0)
	{
		fd1 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd1 < 0)
		{
			ft_putstr_fd("bash: ", 2);
			perror(av[4]);
			ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
			exit(1);
		}
		help_cmd2(pip, fd1, env, av);
	}
}

void	output_sp(t_pip *pip, char *av, int value)
{
	char	*res1;
	char	*res2;

	res1 = ft_strjoin("bash : ", av);
	res2 = ft_strjoin(res1, " : command not found \n");
	ft_putstr_fd(res2, 2);
	free(res1);
	free(res2);
	ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	exit(value);
}
