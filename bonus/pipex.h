/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:28 by zel-harb          #+#    #+#             */
/*   Updated: 2024/05/12 11:21:45 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pip
{
	char	**cmd1;
	char	**cmd2;
	char	*path;
	int  nbr_pip;
	int		pfd[2];
	char	**path_env;
	pid_t	pid;
	pid_t	pid1;
	

}			t_pip;
void		ft_putstr_fd(char *s, int fd);
void		check_first_arg(char *arg);
void		found_cmd(char **str, t_pip *pip, char *var);
int			ft_strlen(char const *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			count_words(char const *s, char c);
char		*ft_strnstr(const char *s, const char *to_find, size_t len);
char		*get_path(char **env);
void		full_pip(t_pip *pip, char **av);
void		check_option(t_pip pip);
char		**ft_free(char **s, int j);
char		**ft_split(char const *s, char c);
int			find(char *av);

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		dup_close1(int fd, t_pip *pip, char **av);
void		dup_close2(int fd1, t_pip *pip, char **av);
;
void		perr(char *str);
void		close_wait(t_pip *pip);
void		child_cmd4(char **av, t_pip *pip, char **env);
void		null_env(char **av, t_pip *pip, char **env);
void		check_pip(t_pip *pip);
void		child_cmd3(char **av, t_pip *pip, char **env);
int vide(char *av);
void count_pipe(t_pip *pip,int ac);
#endif