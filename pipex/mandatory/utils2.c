/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:13:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/07 16:30:56 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

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

int	vide(char *av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			j++;
		i++;
	}
	if (j == ft_strlen(av))
		return (1);
	return (0);
}

void	free_nfc(t_pip *pip)
{
	ft_free(pip->cmd1, count_words(pip->av[2], ' '));
	ft_free(pip->cmd2, count_words(pip->av[3], ' '));
	ft_free(pip->path_env, count_words(get_path(pip->env), ':'));
	exit(127);
}

void	ft_output_fnc(char *str, char *res, char *res_a, t_pip *pip)
{
	char	*res1;
	char	*res2;

	res1 = ft_strjoin("bash : ", str);
	res2 = ft_strjoin(res1, res);
	ft_putstr_fd(res2, 2);
	free(res1);
	free(res2);
	free(res_a);
	free_nfc(pip);
}

void	ft_output(char *str, char *res)
{
	char	*res1;
	char	*res2;

	res1 = ft_strjoin("bash : ", str);
	res2 = ft_strjoin(res1, res);
	ft_putstr_fd(res2, 2);
	free(res1);
	free(res2);
}
