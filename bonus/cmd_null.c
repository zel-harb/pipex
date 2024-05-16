/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 19:53:28 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/16 20:09:08 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void first_cmd_null(t_pip *pip,int *pfd)
{
    int fd1;
	char **cmd;
    
	fd1 = open(pip->av[1], O_RDONLY);
	if (access(pip->av[1], F_OK) == -1 || access(pip->av[1], R_OK) == -1)
	{
		ft_putstr_fd("bash: ", 2);
		perror(pip->av[1]);
	}
    else
    {
        dup2(fd1,0);
	    dup2(pfd[1],1);
	    close(fd1);
	    ft_close(pfd,pip->nbr_pip);
	    cmd =ft_split(pip->av[2],' ');
        execve(cmd[0], cmd,pip->env);
		ft_putstr_fd("bash: ", 2);
		perror(cmd[0]);
		exit(1);
    }
}

void last_cmd_null(t_pip *pip,int *pfd,int ac)
{
    int fd2;
	char **cmd;

    fd2 = open(pip->av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	dup2(pfd[pip->index_pip - 2], 0);
	dup2(fd2, 1);
	close(fd2);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av],' ');
    execve(cmd[0], cmd,pip->env);
	ft_putstr_fd("bash: ", 2);
	perror(cmd[0]);
	exit(1);
    
}
void mid_cmd_null(t_pip *pip,int *pfd)
{
    char **cmd;

    dup2(pfd[pip->index_pip - 2],0);
	dup2(pfd[pip->index_pip + 1], 1);
	ft_close(pfd, pip->nbr_pip);
	cmd = ft_split(pip->av[pip->index_av],' ');
    execve(cmd[0], cmd,pip->env);
	ft_putstr_fd("bash: ", 2);
	perror(cmd[0]);
	exit(1);
}
void env_null(t_pip *pip,int *pid,int *pfd,int ac)
{
    int i;

	i = 0;
	 while(pip->index_av < ac - 1)
	 {
		pid[i] = fork();
		if(pid[i] == 0)
		{
		if(pip->index_av == 2)
		 first_cmd_null(pip,pfd);
		else if (pip->index_av == ac - 2)
			last_cmd_null(pip,pfd,ac);
		else
			mid_cmd_null(pip,pfd);
		}
			pip->index_pip += 2;

			pip->index_av++;
		i++;
		
	 }
}
