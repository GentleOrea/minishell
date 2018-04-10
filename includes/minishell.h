/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:22:10 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/10 16:19:13 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include <stdio.h>
# include <signal.h>

#define UNESC "abnrftvc0x"

#define ESC "\a\b\f\n\r\t\v"

typedef struct	s_env
{
	char		*value;
	struct s_env *next;
	struct s_env *prev;
}				t_env;

typedef struct s_shell
{
	void	(*f_built[6])(struct s_shell *sh, char *argv[]);
	char	**my_built;
	char	**env;
	size_t	env_size;
	size_t	new_env_size;
	t_env	*t_env;
	bool	is_old;
	char	*oldpwd;
	char	*pwd;
	int		signal;
}				g_shell;

void	init(g_shell *sh, char **env);
void	mallcheck(void *to_check);
t_env	*search_var(t_env *list, char *to_find);
int		search_exec(g_shell *sh, char *comm, char *argv[]);
void	fill_env(g_shell *sh);

void	pop(t_env *env);
void	tabchr(g_shell *sh, char *str);
void	ft_echo(g_shell *sh, char *argv[]);
void	ft_exit(g_shell *sh, char *argv[]);
void	ft_cd(g_shell *sh, char *argv[]);
void	ft_env(g_shell *sh, char *argv[]);
void		ft_setenv(g_shell *sh, char *argv[]);
void		ft_unsetenv(g_shell *sh, char *argv[]);
#endif
