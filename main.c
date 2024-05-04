/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/04 21:11:25 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int main(int ac, char **av, char **env)
// {
//     t_pip pip;
//     if(ac != 5)
//     {
//         ft_putstr_fd("Error\n",2);
//         exit(1);
//     }
//     check_first_arg(av[1]);
//     char *en;
//     en = get_path(env);
   
//     full_pip(&pip,av);
//      found_cmd(en,pip->cmd1[0],)
   
//    // printf("----->%s\n",pip->cmd1[0]);


// }
int main(int ac, char **av,char **env)
{
    t_pip pip;
    pid_t pid;
    
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
    
        int fd = open(av[1],O_RDONLY);
        int fd1 = open(av[4],O_RDONLY);
    int pfd[2];
    pipe(pfd) ;

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
        dup2(fd,0);
        close (fd);
        dup2(pfd[1],1); 
        close(pfd[1]);
        close(pfd[0]);
        full_pip(&pip,av);
        found_cmd(get_path(env),&pip,pip.cmd1[0]);
        printf("---pid %s\n",pip.path);
        char *res;
        res = ft_strjoin(pip.path,"/");
        execve(ft_strjoin(res,pip.cmd1[0]),pip.cmd1,env);
         perror("execve");
         exit(1);
    }
    else
    {
        pid_t pid1;
        pid1 = fork();
        if(pid1 == 0)
        {
            dup2(fd1,1);
            close(fd1);
            dup2(pfd[0],0);
            close(pfd[0]);
            close(pfd[1]);
            found_cmd(get_path(env),&pip,pip.cmd2[0]);
            char *res1;
            res1 = ft_strjoin(pip.path,"/");
            execve(ft_strjoin(res1,pip.cmd2[0]),pip.cmd2,env);
            perror("execve");
            exit(1);
            
            
            
        }
    }
    return 0;
  

    


    





    
//    full_pip(&pip,av);
//    found_cmd(get_path(env),&pip);
    //if(pip.n_cmd1 > 1)
      //  check_option(pip);
        // int i;
        // i =0 ;
    // while(pip.path[i])
    // {
        // printf("---%s\n",pip.path);
    //     i++;
    // }
    // ft_free(pip.cmd1,pip.n_cmd1);
    
    
    
    
}