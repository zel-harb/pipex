/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/01 17:58:46 by zel-harb         ###   ########.fr       */
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
    
    if(ac != 5)
    {
         ft_putstr_fd("Error\n",2);
        exit(1);
    }
    if(!open(av[1],O_RDONLY))
    {
         ft_putstr_fd("Error1\n",2);
        exit(1);
    }
   full_pip(&pip,av);
   found_cmd(get_path(env),&pip);
    //if(pip.n_cmd1 > 1)
      //  check_option(pip);
        int i;
        i =0 ;
    // while(pip.path[i])
    // {
    //     printf("---%s\n",pip.path[i]);
    //     i++;
    // }
    ft_free(pip.cmd1,pip.n_cmd1);
    
    
    
    
}