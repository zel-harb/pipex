/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:22 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/16 20:51:25 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <string.h>

void	ft_close(int *pfd, int nbr)
{
	int i = 0;
	while(i < nbr * 2)
	{
		close(pfd[i]);
		i++;
	}
}

void pip_pipe(t_pip pip,int *pfd)
{
	int i;
	
	i = 0;
	while(i < pip.nbr_pip)
	{
		pipe(pfd + i * 2);
		i ++;
	}
}

// void first_cmd(t_pip )
// {
	
// }
void full_pipe(t_pip *pip,char **av,int ac,char **env)
{
	pip->av = av;
	pip->env = env;
	pip->path_env =  ft_split(get_path(env), ':');	
	pip->nbr_pip = ac - 4;
	pip->index_av = 2; //k
	pip->index_pip = 0; // j
	
}

void wait_pid(int *pid,int ac)
{
	int i;

	i = 0;
	while(i < ac -3)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}
}
int main (int ac, char **av,char **env)
{
	t_pip pip;
	int pfd[(ac - 4)*2];
	int pid[ac - 3];
	
	full_pipe(&pip,av,ac,env);
	pip_pipe(pip,pfd);
	if(pip.path_env == NULL || !pip.path_env[0])
		env_null(&pip,pid,pfd,ac);
	else
		all_cmd(&pip,pid,pfd,ac);
	ft_close(pfd, pip.nbr_pip);
	wait_pid(pid,ac);
	
}
