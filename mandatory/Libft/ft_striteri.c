/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:58:50 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/26 13:06:59 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void	f(unsigned int i, char *c)
{
	i = 1;
	*c = *c - 32;
	return ;
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char str1[] = "abc";
	ft_striteri(str1, f);
	printf("%s\n", str1);
	return (0);
}
*/
