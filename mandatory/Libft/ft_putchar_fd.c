/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 08:52:54 by zel-harb          #+#    #+#             */
/*   Updated: 2023/11/28 00:20:20 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
// #include <fcntl.h>

// int	main(void)
// {
// 	char	c;
// 	int fd2 = open("ft_atoi.c", O_RDONLY);
// 	printf("fd2  -> %d\n", fd2);
// 	// ft_putchar_fd(c,fr);
// }