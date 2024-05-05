/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/05 14:49:09 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void check_first_arg(char *arg)
{
    int fd ;
    
    fd = open(arg,O_RDONLY);
    if(fd == -1)
    {
        ft_putstr_fd("Error\n",2);
        exit(1);
    }
}
int count(char **s)
{
    int i;
    i = 0;

    while(s[i])
        i++;
    return i;
}

void found_cmd(char **str,t_pip *pip,char *var)
{
     char *res;
     int i;
     int j;
     int k;
     
     i = 0;
     j = 0;
     k = 0;
     
     while(str[i])
     {
      
        res = ft_strjoin(str[i],"/");
        if(access(ft_strjoin(res,var),F_OK) !=0)
        {
            j++;
            if(j  == count(str))
            {
                ft_putstr_fd("Error\n",2);
                free(res);
                exit(1);
            }
        }
        else
        {
           pip->path = str[i];
            return;
        }
        free(res);
        i++;
     }
}

