/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/07 14:43:15 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include<string.h>

void child_cmd1(char **av,t_pip *pip,char **env)
{
     int fd;
     char *res;
     
    fd = open(av[1],O_RDONLY);
        dup2(fd,0);
        dup2(pip->pfd[1],1); 
        close (fd);
        close(pip->pfd[1]);
        close(pip->pfd[0]);
        full_pip(pip,av);
        if(find(av[2]) == 0)
        {
            execve(pip->cmd1[0],pip->cmd1,env);
            perror("execve");
        }
            if (ft_strncmp(av[2], "/", 1) == 0 ||ft_strncmp(av[2], "./", 2)== 0 )
            {
                perror(av[2]);
                exit(1);
            }
            found_cmd(pip->path_env,pip,pip->cmd1[0]);
            res = ft_strjoin(pip->path,"/");
            execve(ft_strjoin(res,pip->cmd1[0]),pip->cmd1,env);
            perror("execve");
    
}

void child_cmd2(char **av,t_pip *pip,char **env)
{
    int fd1;
    char *res1;
    
    pip->pid1 = fork();
    if(pip->pid1 == 0)
    {
        fd1 = open(av[4],O_WRONLY | O_CREAT | O_TRUNC, 0666);
        dup2(pip->pfd[0],0);
        dup2(fd1,1);
        close(fd1);
        close(pip->pfd[0]);
        close(pip->pfd[1]);
        full_pip(pip,av);
        if(find(av[3]) == 0)
        {
            execve(pip->cmd2[0],pip->cmd2,env);
            perror("execve");
        }
        if (ft_strncmp(av[3], "/", 1) == 0 ||ft_strncmp(av[3], "./", 2)== 0 )
        {
            perror(av[3]);
            exit(1);
        }
        found_cmd(pip->path_env,pip,pip->cmd2[0]);
        res1 = ft_strjoin(pip->path,"/");
        execve(ft_strjoin(res1,pip->cmd2[0]),pip->cmd2,env);
        perror("execve");
    }
}

int main(int ac, char **av,char **env)
{
    t_pip pip;
    
    if(ac != 5)
    {
         ft_putstr_fd("Error\n",2);
         exit(1);
    }
    if(access(av[1], F_OK) == -1 || access(av[1], R_OK) == -1)
    {
         perror(av[1]);
         exit(1);
    }
    pipe(pip.pfd) ;
    pip.path_env = ft_split(get_path(env),':');
    if(pipe(pip.pfd) == -1)
    {
        perror("pipe");
        exit(1);
    }
    pip.pid =fork();
    if(pip.pid < 0)
    {
        perror("fork fail");
        exit(1);
    }
     else if(pip.pid == 0)
        child_cmd1(av,&pip,env);
    else
        child_cmd2(av,&pip,env);
    close(pip.pfd[0]);
    close(pip.pfd[1]);
    waitpid(pip.pid, NULL, 0);
    waitpid(pip.pid1, NULL, 0);
    return 0;
  }
    
