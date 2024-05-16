/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:13:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/15 20:51:01 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (!s && len == 0)
		return (NULL);
	if (!(*to_find))
		return ((char *)s);
	while (s[i] && i < len)
	{
		j = 0;
		while (s[i + j] == to_find[j] && to_find[j] && s[i + j] && i + j < len)
			j++;
		if (j == (size_t)ft_strlen(to_find))
			return ((char *)s + i);
		i++;
	}
	return (0);
}

int vide(char *av)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(av[i])
	{
		if(av[i] == ' ')
			j++;
		i++;
	}
	
	if(j == ft_strlen(av))
		return (1);
	return (0);
}
void count_pipe(t_pip *pip,int ac)
{
	int nbr;

	nbr = ac - 3;
	if(nbr / 2 == 0)
		pip->nbr_pip = nbr / 2;
	else
		pip->nbr_pip = (nbr / 2) + 1;
}
void cmd_cd(int *pfd1,char **av,t_pip *pip,char **env,int *j,int d)
{
	int k;
	char **cmd;
	int *pfd;
	char *res;
	
	pfd = pfd1;
	k = (*j);
	dup2(pfd[k - 2],0);
	dup2(pfd[k + 1],1);
	close(pfd[k - 2]);
	close(pfd[ k + 1]);
	(*j) = (*j)+2;
	cmd =ft_split(av[d],' ');
	if (find(av[d]) == 0)
	{
		execve(cmd[0], cmd, env);
		perr("execve");
	}
	else if (ft_strncmp(av[d], "/", 1) == 0 || ft_strncmp(av[d], "./",
					2) == 0)
			perr(av[d]);
		found_cmd(pip->path_env, pip,cmd[0]);
		res = ft_strjoin(pip->path, "/");
		execve(ft_strjoin(res, cmd[0]), cmd, env);
		perr("execve");
	
}

