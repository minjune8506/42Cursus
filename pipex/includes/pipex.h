#ifndef PIPEX_H
# define PIPEX_H

typedef struct	s_cmd
{
	char *cmd[5];
	char *const *argv;
	char *const *envp;
}				t_cmd;

/*
** parsing && execute
*/
void			exec_cmd(t_cmd *cmd, char *str);
/*
** redirect functions
*/
void			redirect_in(const char *file);
void			redirect_out(const char *file);
void			pipe_connect(int fd[2], int stdio);
/*
** libft functions
*/
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
#endif