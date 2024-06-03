/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-harb <zel-harb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:47:28 by zel-harb          #+#    #+#             */
/*   Updated: 2024/06/03 13:00:05 by zel-harb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_pip
{
	char	**av;
	char	*path;
	char	**env;
	int		nbr_pip;
	int		*pfd;
	int		*pid;
	char	**path_env;
	int		index_av;
	int		index_pip;
	int		fd1;
	int		fd2;
	int		value;
	int		pfd1[2];

}			t_pip;
void		ft_putstr_fd(char *s, int fd);
void		check_first_arg(char *arg);
int			found_cmd(char **str, t_pip *pip, char *var);
int			ft_strlen(char const *s);
char		*ft_strjoin(char const *s1, char const *s2);
int			count_words(char const *s, char c);
char		*ft_strnstr(const char *s, const char *to_find, size_t len);
char		*get_path(char **env);
char		**ft_free(char **s, int j);
char		**ft_split(char const *s, char c);
int			find(char *av);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		perr(char *str, int value);
int			vide(char *av);
void		count_pipe(t_pip *pip, int ac);
int			ft_strcmp(char *s1, char *s2);
void		ft_close(int *pfd, int nbr);
void		all_cmd(t_pip *pip, int ac);
void		first_cmd(t_pip *pip, int *pid);
void		last_cmd(t_pip *pip, int *pfd, int ac);
void		mid_cmd(t_pip *pip, int *pid);
void		env_null(t_pip *pip, int *pid, int *pfd, int ac);
char		*get_next_line(int fd);
char		*ft_strjoin_line(char *s1, char *s2);
char		*ft_strchr(char *s, int c);
char		*ft_strdup(const char *s1);
void		ft_close(int *pfd, int nbr);
void		pip_pipe(t_pip pip, int *pfd);
void		full_pipe(t_pip *pip, char **av, int ac, char **env);
void		wait_pid(int *pid, int ac, t_pip *pip);
void		write_pipe(t_pip *pip);
int			ft_cmp(char *s1, char *name_moves);
void		all_here(t_pip *pip, int *pid, int *pfd, int ac);
void		here_close_wait(t_pip *pip);
void		help(t_pip *pip, char **cmd, int value);
void		status(t_pip *pip, char **cmd, int i, int value);
void		env_here_doc_null(t_pip *pip, int *pid, int *pfd, int ac);
void		env_null_exp(t_pip *pip, int *pid, int *pfd, int ac);
void		save_path(t_pip *pip, char *str, char *res);
#endif