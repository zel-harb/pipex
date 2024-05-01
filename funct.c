/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:04:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/01 17:54:08 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void full_pip(t_pip *pip,char **av)
{
    pip->cmd1 = ft_split(av[2],' ');
    pip->n_cmd1 = count_words(av[2],' ');
    pip->n_cmd2 = count_words(av[3],' ');
    // pip->cmd2 = ft_split(av[3],' ');
    
}
void check_option(t_pip pip)
{
   execve(ft_strjoin(pip.path[0],pip.cmd1[0]),pip.cmd1,NULL);
   printf("This line will not be executed.\n"); 
}