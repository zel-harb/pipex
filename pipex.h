/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:28 by zel-harb          #+#    #+#             */
/*   Updated: 2024/04/30 11:59:53 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
void	ft_putstr_fd(char *s, int fd);
void    check_first_arg(char *arg);
void    check_cmd1(char *env,char *av);
char	**ft_split(char const *s, char c);
int	    ft_strlen(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
int     count_words(char const *s, char c);
#endif