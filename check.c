/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/29 18:49:00 by zel-harb         ###   ########.fr       */
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

void check_cmd1(char *env,char *av)
{
     char **str;
     char *res;
     int i;
     int j;
     
     i = 0;
     j = 0;
     str =ft_split(env,':');
     while(str[i])
     {
        res = ft_strjoin(str[i],"/");
        if(access(ft_strjoin(res,av),R_OK) !=0)
        {
            j++;
            if(j  == count_words(env,':'))
            {
                ft_putstr_fd("Error\n",2);
                exit(1);
            }
        }

        i++;
     }
}
