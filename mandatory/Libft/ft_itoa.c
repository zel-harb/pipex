/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:41:28 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/27 23:36:09 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(long b)
{
	int	i;

	i = 0;
	if (b == 0)
		return (1);
	while (b != 0)
	{
		i++;
		b = b / 10;
	}
	return (i);
}

static char	*f_positive(long n)
{
	int		len;
	char	*p;

	len = count(n);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	while (len > 0)
	{
		p[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (p);
}

static char	*f_negative(long n)
{
	int		len;
	char	*p;

	n = -n;
	len = count(n) + 1;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	p[0] = '-';
	while (len > 1)
	{
		p[len - 1] = (n % 10) + 48;
		n = n / 10;
		len--;
	}
	return (p);
}

char	*ft_itoa(int nbr)
{
	long	n;
	char	*p;

	n = (long)nbr;
	if (n >= 0)
	{
		p = f_positive(n);
	}
	else if (n < 0)
	{
		p = f_negative(n);
	}
	else
	{
		p = malloc(2);
		if (!p)
			return (NULL);
		p[0] = '0';
		p[1] = '\0';
	}
	return (p);
}

// int	main(void)
// {
// 	printf("%d\n", count(0));
// 	printf("%s\n", ft_itoa(0));
// }
