#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

typedef struct	s_cmd
{
	char *cmd[5];
	char *const *argv;
	char *const *envp;
}				t_cmd;

/*
** cmd_bonus.c
*/
void			exec_cmd(t_cmd *cmd, char *str);
/*
** ft_split_bonus.c
*/
char			**ft_split(char const *s, char c);
/*
** ft_strjoin_bonus.c
*/
char			*ft_strjoin(char *s1, char *s2);
/*
** utils.c
*/
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
/*
** get_next_line
*/
char			*ft_strdup(char *s1);
int				get_next_line(int fd, char **line);
/*
** here_doc
*/
void			here_doc(char **av);
/*
** redirect functions
*/
void			redirect_in(const char *file);
void			redirect_out(const char *file, char **av);
void			pipe_connect(int fd[2], int stdio);
#endif