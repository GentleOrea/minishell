/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:41:02 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/10 19:09:51 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void ft_unsetenv(g_shell *sh, char *argv[])
{
	t_env *env;

	env = search_var(sh->t_env, argv[0]);
	pop(env);
	ft_memdel((void**)&env);
	sh->new_env_size--;
}


void ft_setenv(g_shell *sh, char *argv[])
{
	t_env *env;

	env = search_var(sh->t_env, argv[0]);
	env->value = ft_implode('=', argv[0], argv[1]);
	sh->new_env_size++;
}

void ft_env(g_shell *sh, char *argv[])
{
	t_env *end;
	int i;
	char	*temp;

	i = -1;
	while (ft_isin('=', argv[++i]))
	{
		temp = ft_strndup(argv[i], ft_charchr('=', argv[i]));
		end = search_var(sh->t_env, temp);
		end->value = argv[i];
		sh->new_env_size++;
	}
	if (argv[i])
	{
		search_exec(sh, argv[i], &argv[i]);
		exit(EXIT_SUCCESS);
	}
	fill_env(sh);
	i = -1;
	while(sh->env[++i])
		ft_printf("%s\n", sh->env[i]);
	exit(EXIT_SUCCESS);
}
