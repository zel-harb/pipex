/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/14 14:11:31 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

void cmd_first(char **av,int pfd,t_pip *pip,char **env)
{
	int fd;
	char *res;
	char **cmd;
	
	fd = open(av[1], O_RDONLY);
	dup2(fd,0);
	dup2(pfd[1],1);
	close(fd);
	close(pfd[1]);
	close(pfd[0]);
	cmd =ft_split(av[2],' ');
	found_cmd(pip->path_env, pip,cmd[0]);
	res = ft_strjoin(pip->path, "/");
	execve(ft_strjoin(res,cmd[0]), cmd, env);
	perr("execve");
}
void cmd_last(int ac,int pfd,char **av,t_pip *pip,int j,int k ,char **env)
{
	int fd;
	int i;
	char *res;
	char **cmd;
	 

	i = j;
	fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	dup2(pfd[j - 2], 0);
	dup2(fd, 1);
	close(fd);
	close(pfd[j - 2]);
	close(pfd[j + 1]);
	cmd = ft_split(av[k],' ');
	found_cmd(pip->path_env, pip,cmd[0]);
	res = ft_strjoin(pip->path, "/");
	execve(ft_strjoin(res,cmd[0]),cmd, env);
	perror("execve");
	

}
void cmd_mid(int j,int pfd,t_pip *pip,char **env ,int k,char **av)
{

	char *res;
	char **cmd;
	
	dup2(pfd[j - 2],0);
	dup2(pfd[j + 1], 1);
	close(pfd[j - 2]);
	close(pfd[j + 1]);
	cmd = ft_split(av[k],' ');
	found_cmd(pip->path_env, pip,cmd[0]);
	res = ft_strjoin(pip->path, "/");
	execve(ft_strjoin(res,cmd[0]),cmd, env);
	perror("execve");
	
}

int main (int ac, char **av,char **env)
{
	int i;
}
