/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:28 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/05 15:01:31 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pip
{
    char **cmd1;
    char **cmd2;
    char *path;
    int   n_cmd1;
    int    n_cmd2;
    int    n_path_1;
} t_pip;
void	ft_putstr_fd(char *s, int fd);
void    check_first_arg(char *arg);
void    found_cmd(char **str,t_pip *pip,char *var);
int	    ft_strlen(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
int     count_words(char const *s, char c);
char	*ft_strnstr(const char *s, const char *to_find, size_t len);
char     *get_path(char **env);
void     full_pip(t_pip *pip,char **av);
void check_option(t_pip pip);
char	**ft_free(char **s, int j);
char	**ft_split(char const *s, char c);
int find(char *av);
#endif