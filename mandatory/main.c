/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/13 22:29:21 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

void	child_cmd3(char **av, t_pip *pip, char **env)
{
	int		fd;
	char	*res;

	fd = open(av[1], O_RDONLY);
	if (access(av[1], F_OK) == -1 || access(av[1], R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(av[1]);
	}
	else
	{
		dup2(fd, 0);
		dup2(pip->pfd[1], 1);
		close(fd);
		close(pip->pfd[1]);
		close(pip->pfd[0]);
		full_pip(pip, av);
		execve(pip->cmd1[0], pip->cmd1, env);
		ft_putstr_fd("bash: ", 2);
		perror(pip->cmd1[0]);
		exit(1);
	}
}

void	child_cmd4(char **av, t_pip *pip, char **env)
{
	int		fd1;
	char	*res1;

	pip->pid1 = fork();
	if (pip->pid1 == 0)
	{
		fd1 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		dup2(pip->pfd[0], 0);
		dup2(fd1, 1);
		close(fd1);
		close(pip->pfd[0]);
		close(pip->pfd[1]);
		full_pip(pip, av);
		execve(pip->cmd2[0], pip->cmd2, env);
		ft_putstr_fd("bash: ", 2);
		perror(pip->cmd2[0]);
		exit(1);
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
	}
	else if(av[2][0] == '\0' || vide(av[2]) == 1)
	{
		ft_putstr_fd("bash : command not found \n",2);
		exit(1);
	}
	else
	{
		dup_close1(fd, pip, av);
		if (find(av[2]) == 0)
		{
			execve(pip->cmd1[0], pip->cmd1, env);
			perr("execve");
		}
		else if (ft_strncmp(av[2], "/", 1) == 0 || ft_strncmp(av[2], "./",
					2) == 0)
			perr(av[2]);
		found_cmd(pip->path_env, pip, pip->cmd1[0]);
		res = ft_strjoin(pip->path, "/");
		execve(ft_strjoin(res, pip->cmd1[0]), pip->cmd1, env);
		perr("execve");
	}
}

void	child_cmd2(char **av, t_pip *pip, char **env)
{
	int		fd1;
	char	*res1;

	pip->pid1 = fork();
	if (pip->pid1 == 0)
	{
		fd1 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		dup_close2(fd1, pip, av);
		if (find(av[3]) == 0)
		{
			execve(pip->cmd2[0], pip->cmd2, env);
			perror("execve");
		}
		else if(av[3][0] =='\0' || vide(av[3]) == 1 )
		{
			ft_putstr_fd("bash : command not found \n",2);
			exit(1);
		}
		if (ft_strncmp(av[3], "/", 1) == 0 || ft_strncmp(av[3], "./", 2) == 0)
		{
			perror(av[3]);
			exit(1);
		}
		found_cmd(pip->path_env, pip, pip->cmd2[0]);
		res1 = ft_strjoin(pip->path, "/");
		execve(ft_strjoin(res1, pip->cmd2[0]), pip->cmd2, env);
		perror("execve");
	}
}

int	main(int ac, char **av, char **env)
{
	t_pip	pip;

	if (ac != 5)
	{
		ft_putstr_fd("More agrs\n", 2);
		exit(1);
	}
	pipe(pip.pfd);
	pip.path_env = ft_split(get_path(env), ':');
	
	//dprintf(2, "path : %s\n", pip.path_env[0]);
	// if(ft_strlen(get_path(env)) == 0 )
	// {
	// 	pip.pid = fork();
	// 	null_env(av, &pip, env);
	// }
	if (!pip.path_env)
	{
		dprintf(2,"hi\n");
		pip.pid = fork();
		null_env(av, &pip, env);
	}
	
	else if (!pip.path_env[0])
	{
		dprintf(2,"hi\n");
		pip.pid = fork();
		null_env(av, &pip, env);
	}
	else
	{
		check_pip(&pip);
		if (pip.pid == 0)
			child_cmd1(av, &pip, env);
		else
			child_cmd2(av, &pip, env);
		close_wait(&pip);
	}
	return (0);
}