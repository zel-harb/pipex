/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/05 15:09:49 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int main(int ac, char **av,char **env)
{
    t_pip pip;
    pid_t pid;
    pid_t pid1;
    int fd1;
    int fd;
    char *res;
    char *res1;
    char **path;
    int i;
    i =0;
    
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
    
    int pfd[2];
    pipe(pfd) ;
    path = ft_split(get_path(env),':');
    // while(path[i])
    // {
    //     dprintf(2,"-->%s \n",path[i]);
    //     i++;
    // }

    if(pipe(pfd) == -1)
    {
        perror("pipe");
        exit(1);
    }
    
    pid =fork();
    if(pid < 0)
    {
        perror("fork fail");
        exit(1);
    }
     else if(pid == 0)
    {
       fd = open(av[1],O_RDONLY, 0777);
        dup2(fd,0);
        dup2(pfd[1],1); 
        close (fd);
        close(pfd[1]);
        close(pfd[0]);
        full_pip(&pip,av);
        if(find(av[2]) == 0)
        {
            execve(pip.cmd1[0],pip.cmd1,env);
            perror("execve");
            exit(1);
        }
        else
        {
            found_cmd(path,&pip,pip.cmd1[0]);
            res = ft_strjoin(pip.path,"/");
            execve(ft_strjoin(res,pip.cmd1[0]),pip.cmd1,env);
            perror("execve");
            exit(1);
        }
    }
    else
    {
        pid1 = fork();
        if(pid1 == 0)
        {
            fd1 = open(av[4],O_WRONLY | O_CREAT | O_TRUNC, 0777);
            dup2(pfd[0],0);
            dup2(fd1,1);
            close(fd1);
            close(pfd[0]);
            close(pfd[1]);
            full_pip(&pip,av);
            if(find(av[3]) == 0)
            {
                execve(pip.cmd2[0],pip.cmd2,env);
                perror("execve");
                exit(1);
            }
            found_cmd(path,&pip,pip.cmd2[0]);
            res1 = ft_strjoin(pip.path,"/");
            execve(ft_strjoin(res1,pip.cmd2[0]),pip.cmd2,env);
            perror("execve");
            exit(1); 
        }
    }
    return 0;
  }
    
