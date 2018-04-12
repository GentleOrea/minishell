/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:22:10 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/12 15:54:03 by ygarrot          ###   ########.fr       */
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
}				g_shell;

void			init(g_shell *sh, char **env);
void			mallcheck(void *to_check);
t_env			*search_var(t_env *list, char *to_find);
int				search_exec(g_shell *sh, char *comm, char *argv[]);
void			fill_env(g_shell *sh);
void			xe(g_shell *sh, char *comm, char **argv);
void			comm(g_shell *sh, char **comma);
void			signin_handler(int sig);
void			sigquit_handler(int sig);
void			pop(t_env *env);
void			tabchr(g_shell *sh, char *str, char is_old);
void			ft_echo(g_shell *sh, char *argv[]);
void			ft_cd(g_shell *sh, char *argv[]);
void			ft_env(g_shell *sh, char *argv[]);
void			ft_setenv(g_shell *sh, char *argv[]);
void			ft_unsetenv(g_shell *sh, char *argv[]);
void			sig_handler(int sign);
void			sig_run(g_shell *sh);
void			erase_shell(g_shell *sh);
void			wait_exec(g_shell *sh, char **ta);
#endif
