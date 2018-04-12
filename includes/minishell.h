/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:22:10 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/12 17:14:27 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <signal.h>

# define UNESC "abfnrtvc0x"
# define ESC "\a\b\f\n\r\t\v"

typedef struct	s_env
{
	char			*value;
	char			*oldvalue;
	char			temp;
	struct s_env	*next;
	struct s_env	*prev;
}				t_env;

typedef struct	s_shell
{
	void	(*f_built[5])(struct s_shell *sh, char *argv[]);
	char	**my_built;
	char	**env;
	t_env	*env_t;
	int		env_size;
	char	free;
	char	*oldpwd;
	pid_t	father;
	char	*pwd;
	char	*line;
	char	**comma;
	char	**space;
}				t_shell;

void			init(t_shell *sh, char **env);
void			mallcheck(void *to_check);
t_env			*search_var(t_env *list, char *to_find);
int				search_exec(t_shell *sh, char *comm, char *argv[]);
void			fill_env(t_shell *sh);
void			xe(t_shell *sh, char *comm, char **argv);
void			comm(t_shell *sh, char **comma);
void			signin_handler(int sig);
void			sigquit_handler(int sig);
void			pop(t_env *env);
void			tabchr(t_shell *sh, char *str, char is_old);
void			ft_echo(t_shell *sh, char *argv[]);
void			ft_cd(t_shell *sh, char *argv[]);
void			ft_env(t_shell *sh, char *argv[]);
void			ft_setenv(t_shell *sh, char *argv[]);
void			ft_unsetenv(t_shell *sh, char *argv[]);
void			sig_handler(int sign);
void			sig_run(t_shell *sh);
void			erase_shell(t_shell *sh);
void			wait_exec(t_shell *sh, char **ta);
void			exe(t_shell *sh, char *comm, char **argv);
#endif
