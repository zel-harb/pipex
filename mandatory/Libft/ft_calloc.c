/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:40:02 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 01:53:28 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	tmp = malloc(size * count);
	if (tmp == 0)
		return (0);
	ft_memset(tmp, 0, size * count);
	return (tmp);
}
