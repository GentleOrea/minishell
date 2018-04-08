/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:22:10 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/08 18:50:32 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/includes/libft.h"
# include "stdio.h"

typedef struct	s_env
{
	char		*key;
	char		*value;
	char		*join;
	struct s_env *next;
}				t_env;

typedef struct s_shell
{
	char	**env;
	char	**p_env;
	size_t	env_size;
	size_t	new_env_size;
	t_env	*t_env;
	bool	is_old;
	int		signal;
}				g_shell;

void ft_env(g_shell *sh);
void	tabchr(g_shell *sh);
void	ft_cd(g_shell *sh, const char *path);
void	init(g_shell *sh);
#endif
