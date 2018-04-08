/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:13:21 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/08 18:51:54 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	fill_env(g_shell *sh)
{
	t_env *env;
	int		i;

	i = 0;
	if (sh->env_size == sh->new_env_size)
		return ;
	ft_memdel((void**)&sh->p_env);
	sh->env_size = sh->new_env_size;
	sh->p_env = ft_memalloc(sh->env_size * sizeof(char));
	while (env)
	{
		sh->p_env[i] = env->join;
		env = env->next;
	}
}

void	init(g_shell *sh)
{
	t_env	*begin;
	int		del;
	int	i;

	i = 0;
	sh->env_size = 1;
	
	begin = (t_env *)ft_memalloc(sizeof(t_env));
	sh->t_env = begin;
	del = ft_charchr('=', sh->env[0]);
	begin->join = ft_strdup(sh->env[0]);
	begin->key = ft_strndup(sh->env[0], del);
	begin->value = ft_strdup((char*)&sh->env[0][del + 1]);
	
	while (sh->env[++i])
	{
	
		begin->next = (t_env *)ft_memalloc(sizeof(t_env));
		begin = begin->next;
		del = ft_charchr('=', sh->env[i]);
		begin->join = ft_strdup(sh->env[i]);
		begin->key = ft_strndup(sh->env[i], del);
		begin->value = ft_strdup((char*)&sh->env[i][del + 1]);
		//ft_printf("[%s][%s][%s]\n", begin->key, begin->value, begin->join);
		sh->env_size++;
	}
}
