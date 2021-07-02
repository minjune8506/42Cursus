/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjkim2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 09:51:13 by minjkim2          #+#    #+#             */
/*   Updated: 2021/07/02 09:51:14 by minjkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

typedef struct	s_cmd
{
	char		*cmd[5];
	char *const	*argv;
	char *const	*envp;
}				t_cmd;

void			exec_cmd(t_cmd *cmd, char *str);
void			here_doc(char **av);
void			multi_pipe(int cmd_count, char **av, int fd[], t_cmd *cmd);
void			redirect_in(const char *file);
void			redirect_out(const char *file, char **av);
void			pipe_connect(int fd[2], int stdio);
char			**ft_split(char const *s, char c);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strjoin(char *s1, char *s2);
int				get_next_line(int fd, char **line);
char			*ft_strdup(char *s1);
#endif
