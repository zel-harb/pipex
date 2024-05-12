/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:46:38 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/27 23:58:26 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	if (src == NULL && dest == NULL)
		return (NULL);
	if (dest == src)
		return ((void *)src);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
