/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:13:21 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/12 14:36:49 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_env(g_shell *sh)
{
	t_env *env;
	t_env *to_del;
	int		i;

	i = 0;
	env = sh->t_env;
	ft_memdel((void**)&sh->env);
	sh->env_size = sh->new_env_size;
	sh->env = (char**)ft_memalloc((sh->env_size + 1) * sizeof(char*));
	while (env)
	{
		env->value ? sh->env[i++] = env->value : 0;
		to_del = env;
		env = env->next;
		if (to_del && !to_del->value)
		{
			pop(to_del);
			ft_memdel((void**)&to_del);
		}
	}
}

void	init_built(g_shell *sh)
{
	char	**mybuilt;
	t_env	*pwd;
	t_env	*oldpwd;
	int		i;

	i = -1;
	mybuilt = (char *[6]){"echo", "cd", "env", "setenv", "unsetenv"};
	mallcheck(sh->my_built = (char**)ft_memalloc(6 * sizeof(char*)));
	while (mybuilt[++i])
		mallcheck(sh->my_built[i] = ft_strdup(mybuilt[i]));
	sh->f_built[0] = &ft_echo;
	sh->f_built[1] = &ft_cd;
	sh->f_built[2] = &ft_env;
	sh->f_built[3] = &ft_setenv;
	sh->f_built[4] = &ft_unsetenv;
	pwd = search_var(sh->t_env, "PWD");
	oldpwd = search_var(sh->t_env, "OLDPWD"); 
	sh->oldpwd = ft_strdup(&pwd->value[4]);
	sh->pwd = ft_strdup(sh->oldpwd);
	sh->env = NULL;
}


void	init(g_shell *sh, char **env)
{
	t_env	*begin;
	int		del;
	int		i;

	mallcheck(begin = (t_env *)ft_memalloc(sizeof(t_env)));
	sh->t_env = begin;
	del = ft_charchr('=', env[0]);
	begin->value = ft_strdup(env[0]);
	i = 0;
	while (env[++i])
	{
		mallcheck(begin->next = (t_env *)ft_memalloc(sizeof(t_env)));
		begin->next->prev = begin;
		begin = begin->next;
		del = ft_charchr('=', env[i]);
		begin->value = ft_strdup(env[i]);
	}
	init_built(sh);
	fill_env(sh);
}

void	erase_shell(g_shell *sh)
{
	t_env	*to_del;

	ft_memdel((void**)&sh->env);
	ft_free_dblechar_tab(sh->my_built);
	while (sh->t_env)
	{
		to_del = sh->t_env;
		sh->t_env = sh->t_env->next;
		ft_memdel((void**)&to_del->value);
		ft_memdel((void**)&to_del);
	}
	ft_memdel((void**)&sh->oldpwd);
	ft_memdel((void**)&sh->pwd);
	ft_printf("exit\n");
	exit(1);
}
