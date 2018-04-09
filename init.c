/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:13:21 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/09 18:02:18 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_env(g_shell *sh)
{
	t_env *env;
	int		i;

	i = 0;
	env = sh->t_env;
//	if (sh->env_size == sh->new_env_size)
//		return ;
	ft_memdel((void**)&sh->env);
	sh->env_size = sh->new_env_size;
	sh->env = (char**)ft_memalloc((sh->env_size + 1) * sizeof(char*));
	while (env)
	{
		sh->env[i++] = env->value;
		env = env->next;
	}
}

void	init_built(g_shell *sh)
{

	sh->f_built[0] = &ft_echo;
	sh->f_built[1] = &ft_exit;
	sh->f_built[2] = &ft_cd;
	sh->f_built[3] = &ft_env;
	sh->f_built[4] = &ft_setenv;
	sh->f_built[5] = &ft_unsetenv;
}

void	init(g_shell *sh, char **env)
{
	t_env	*begin;
	int		del;
	char	**mybuilt;
	int		i;

	init_built(sh);
	mybuilt = (char *[6]){"echo", "exit", "cd", "env", "setenv", "unsetenv"};
	mallcheck(sh->my_built = ft_memalloc(i = ft_sizeof_tab(mybuilt)));
	ft_memcpy(sh->my_built, mybuilt, i);
	begin = (t_env *)ft_memalloc(sizeof(t_env));
	sh->t_env = begin;
	del = ft_charchr('=', env[0]);
	begin->value = ft_strdup(env[0]);
	i = 0;
	while (env[++i])
	{
		begin->next = (t_env *)ft_memalloc(sizeof(t_env));
		begin->next->prev = begin;
		begin = begin->next;
		del = ft_charchr('=', env[i]);
		begin->value = ft_strdup(env[i]);
	}
	sh->new_env_size = i;
	fill_env(sh);

	t_env	*pwd;
	t_env	*oldpwd;

	pwd = search_var(sh->t_env, "PWD");
	oldpwd = search_var(sh->t_env, "OLDPWD"); 
	sh->oldpwd = &pwd->value[4];
	sh->pwd = sh->oldpwd;

}
