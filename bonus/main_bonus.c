/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/16 11:45:01 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

void	ft_close(int *pfd, int nbr)
{
	int i = 0;
	while(i < nbr * 2)
	{
		close(pfd[i]);
		i++;
	}
}

int main (int ac, char **av,char **env)
{
	t_pip pip;
	int nbr;
	int i;
	int pfd[(ac - 4)*2];
	int pid[ac - 3];
	int fd1;
	int fd2;
	char *res;
	char **cmd;
	int j;
	int k;
	char buffer[200];
	nbr = ac -4;
	i = 0;
	j = 0;
	k =2;
	pip.path_env = ft_split(get_path(env), ':');	
	while(i < nbr)
	{
		pipe(pfd + i * 2);
		i ++;
	}
	 i = 0;
	 dprintf(2,"hi %s\n",pip.path_env[0]);
	 while(k < ac - 1)
	 {
		pid[i] = fork();
		if(pid[i] == 0)
		{
		if(k == 2)
		{
			fd1 = open(av[1], O_RDONLY);
			dup2(fd1,0);
			dup2(pfd[1],1);
			close(fd1);
			ft_close(pfd, nbr);
			cmd =ft_split(av[2],' ');
			if (find(av[2]) == 0)
			{
				execve(cmd[0], cmd, env);
				perr("execve");
			}
			else if(av[2][0] == '\0' || vide(av[2]) == 1)
			{
				ft_putstr_fd("bash : command not found \n",2);
				exit(1);
			}
			else if (ft_strncmp(av[2], "/", 1) == 0 || ft_strncmp(av[2], "./",2) == 0)
				perr(av[2]);
			found_cmd(pip.path_env, &pip,cmd[0]);
			res = ft_strjoin(pip.path, "/");
			execve(ft_strjoin(res,cmd[0]), cmd, env);
			perr("execve");
		}
		else if (k == ac - 2)
		{
			fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
			dup2(pfd[j - 2], 0);
			dup2(fd2, 1);
			close(fd2);
			ft_close(pfd, nbr);
			cmd = ft_split(av[k],' ');
			if(env == NULL)
			{
				execve(cmd[0],cmd, env);
				ft_putstr_fd("bash: ", 2);
				perror(cmd[0]);
			}
			if (find(av[k]) == 0)
			{
				execve(cmd[0], cmd, env);
				perr("execve");
			}
			else if(av[k][0] == '\0' || vide(av[k]) == 1)
			{
				ft_putstr_fd("bash : command not found \n",2);
				exit(1);
			}
			else if (ft_strncmp(av[k], "/", 1) == 0 || ft_strncmp(av[k], "./",2) == 0)
				perr(av[k]);
			found_cmd(pip.path_env, &pip,cmd[0]);
			res = ft_strjoin(pip.path, "/");
			execve(ft_strjoin(res,cmd[0]),cmd, env);
			perror("execve");
		}
		else
		{
			dup2(pfd[j - 2],0);
			dup2(pfd[j + 1], 1);
			ft_close(pfd, nbr);
			cmd = ft_split(av[k],' ');
			if(env == NULL)
			{
				execve(cmd[0],cmd, env);
				ft_putstr_fd("bash: ", 2);
				perror(cmd[0]);
			}
			if (find(av[k]) == 0)
			{
				execve(cmd[0], cmd, env);
				perr("execve");
			}
			else if(av[k][0] == '\0' || vide(av[k]) == 1)
			{
				ft_putstr_fd("bash : command not found \n",2);
				exit(1);
			}
			else if (ft_strncmp(av[k], "/", 1) == 0 || ft_strncmp(av[k], "./",2) == 0)
				perr(av[k]);
			found_cmd(pip.path_env, &pip,cmd[0]);
			res = ft_strjoin(pip.path, "/");
			execve(ft_strjoin(res,cmd[0]),cmd, env);
			perror("execve");
		}
		}
			j = j+2;

			k++;
		i++;
		
	 }
	 i = 0;
		ft_close(pfd, nbr);
	 while(i < ac -3)
	 {
		waitpid(pid[i], NULL, 0);
		i++;
	 }
	
}
