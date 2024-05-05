/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:04:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/05 15:03:05 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void full_pip(t_pip *pip,char **av)
{
    pip->cmd1 = ft_split(av[2],' ');
    pip->n_cmd1 = count_words(av[2],' ');
    pip->n_cmd2 = count_words(av[3],' ');
    pip->cmd2 = ft_split(av[3],' ');
    
}
char  *get_path(char **env)
{
    char *str;
    int i;

    i = 0;
    while(env[i])
    {
        if(ft_strnstr(env[i],"PATH",4) !=0)
        {
            str = ft_strnstr(env[i],"PATH",4);
            return str + 5;
        }
        i++;
    }
    return NULL;
}
int find(char *av)
{
    int i;

    i = 0;
    if(access(av,F_OK) == 0)
    {
        return 0;
    }
    else 
    return 1;
}