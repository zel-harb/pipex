/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:34:52 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/27 22:10:39 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*a;
	unsigned char	ic;
	size_t			i;

	a = (unsigned char *)b;
	ic = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		a[i] = ic;
		i++;
	}
	return (b);
}

// int	main(void)
// {
// 	int c[]={-1 ,-8 };
// 	printf("%d    %d\n",c[0],c[1]);
// 	ft_memset(c,-4,1);
// 	printf("%d   %d",c[0],c[1]);
// }
