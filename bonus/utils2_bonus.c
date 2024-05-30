/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:13:26 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/30 20:36:31 by zel-harb         ###   ########.fr       */
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

void	count_pipe(t_pip *pip, int ac)
{
	int	nbr;

	nbr = ac - 3;
	if (nbr / 2 == 0)
		pip->nbr_pip = nbr / 2;
	else
		pip->nbr_pip = (nbr / 2) + 1;
}

void	write_pipe(t_pip *pip)
{
	char	*len;

	write(1, ">", 2);
	len = get_next_line(0);
	while (len && ft_cmp(pip->av[2], len) != 0)
	{
		write(pip->pfd1[1], len, ft_strlen(len));
		free(len);
		write(1, ">", 2);
		len = get_next_line(0);
	}
	free(len);
	get_next_line(-1);
}

void	here_close_wait(t_pip *pip)
{
	close(pip->pfd1[0]);
	close(pip->pfd1[1]);
	waitpid(pip->pfd1[0], &pip->value, 0);
	waitpid(pip->pfd1[1], &pip->value, 0);
}
