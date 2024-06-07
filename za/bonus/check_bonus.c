/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:16:25 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/03 17:15:47 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_first_arg(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit(1);
}

int	count(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_output(char *str, char *res, char *res_a)
{
	char	*res1;
	char	*res2;

	res1 = ft_strjoin("bash : ", str);
	res2 = ft_strjoin(res1, res);
	ft_putstr_fd(res2, 2);
	free(res1);
	free(res2);
	free(res_a);
}

char	*str_join(char *str, char *var)
{
	char	*res;
	char	*res2;

	res = ft_strjoin(str, "/");
	res2 = ft_strjoin(res, var);
	free(res);
	return (res2);
}

int	found_cmd(char **str, t_pip *pip, char *var)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (str[++i])
	{
		res = str_join(str[i], var);
		if (access(res, X_OK) != 0)
		{
			if (++j == count(str))
			{
				ft_output(var, " : command not found\n", res);
				return (1);
			}
		}
		else
		{
			save_path(pip, str[i], res);
			return (0);
		}
		free(res);
	}
	return (0);
}
