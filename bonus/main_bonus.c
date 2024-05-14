/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/14 16:59:55 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

// void cmd_first(char **av,int pfd,t_pip *pip,char **env)
// {
// 	int fd;
// 	char *res;
// 	char **cmd;
	
// 	fd = open(av[1], O_RDONLY);
// 	dup2(fd,0);
// 	dup2(pfd[1],1);
// 	close(fd);
// 	close(pfd[1]);
// 	close(pfd[0]);
// 	cmd =ft_split(av[2],' ');
// 	found_cmd(pip->path_env, pip,cmd[0]);
// 	res = ft_strjoin(pip->path, "/");
// 	execve(ft_strjoin(res,cmd[0]), cmd, env);
// 	perr("execve");
// }
// void cmd_last(int ac,int pfd,char **av,t_pip *pip,int j,int k ,char **env)
// {
// 	int fd;
// 	int i;
// 	char *res;
// 	char **cmd;
	 

// 	i = j;
// 	fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
// 	dup2(pfd[j - 2], 0);
// 	dup2(fd, 1);
// 	close(fd);
// 	close(pfd[j - 2]);
// 	close(pfd[j + 1]);
// 	cmd = ft_split(av[k],' ');
// 	found_cmd(pip->path_env, pip,cmd[0]);
// 	res = ft_strjoin(pip->path, "/");
// 	execve(ft_strjoin(res,cmd[0]),cmd, env);
// 	perror("execve");
	

// }
// void cmd_mid(int j,int pfd,t_pip *pip,char **env ,int k,char **av)
// {

// 	char *res;
// 	char **cmd;
	
// 	dup2(pfd[j - 2],0);
// 	dup2(pfd[j + 1], 1);
// 	close(pfd[j - 2]);
// 	close(pfd[j + 1]);
// 	cmd = ft_split(av[k],' ');
// 	found_cmd(pip->path_env, pip,cmd[0]);
// 	res = ft_strjoin(pip->path, "/");
// 	execve(ft_strjoin(res,cmd[0]),cmd, env);
// 	perror("execve");
	
// }
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
	dprintf(2,"ac -> %d\n",ac);
	while(i < nbr)
	{
		pipe(pfd + i * 2);
		i ++;
	}
	 i = 0;
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
			// close(pfd[1]);
			// close(pfd[0]);
			ft_close(pfd, nbr);
			cmd =ft_split(av[2],' ');
			found_cmd(pip.path_env, &pip,cmd[0]);
			res = ft_strjoin(pip.path, "/");
			dprintf(2,"path -->%s \n",pip.path);
			execve(ft_strjoin(res,cmd[0]), cmd, env);
			perr("execve");
		}
		else if (k == ac - 2)
		{
			dprintf(2,"heba----> %d\n", j);
			fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
			dup2(pfd[j - 2], 0);
			dup2(fd2, 1);
			close(fd2);
			// close(pfd[j - 2]);
			// close(pfd[j + 1]);
			ft_close(pfd, nbr);
			cmd = ft_split(av[k],' ');
			found_cmd(pip.path_env, &pip,cmd[0]);
			res = ft_strjoin(pip.path, "/");
			execve(ft_strjoin(res,cmd[0]),cmd, env);
			perror("execve");
		}
		else
		{
			dprintf(2,"hihih av[k] %s\n",av[k]);
			dup2(pfd[j - 2],0);
			dup2(pfd[j + 1], 1);
			// close(pfd[j - 2]);
			// close(pfd[j + 1]);
			ft_close(pfd, nbr);
			cmd = ft_split(av[k],' ');
			
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
