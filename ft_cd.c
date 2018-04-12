/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:10:57 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/12 14:37:15 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tabchr(g_shell *sh, char *arg, char is_old)
{
	t_env	*pwd;
	t_env	*oldpwd;
	char	path[256];

	pwd = search_var(sh->t_env, "PWD");
	oldpwd = search_var(sh->t_env, "OLDPWD"); 
	getcwd(path, 256);
	!is_old ? ft_memdel((void**)&sh->oldpwd) : 0;
	!is_old || !sh->oldpwd ? mallcheck(sh->oldpwd = ft_strdup(path)) : 0;
	if (chdir(is_old ? sh->oldpwd : arg) && arg)
	{
		ft_printf("cd : no such file or directory : %s\n", arg);
		return ;
	}
	getcwd(path, 256);
	ft_memdel((void**)&sh->pwd);
	mallcheck(sh->pwd = ft_strdup(path));
	ft_memdel((void**)&pwd->value);
	ft_memdel((void**)&oldpwd->value);
	mallcheck(pwd->value = ft_strjoin("PWD=", path));
	mallcheck(oldpwd->value = ft_strjoin("OLDPWD=", sh->oldpwd));
}

void	ft_cd(g_shell *sh, char *argv[])
{
	t_env	*temp;
	char	is_old;
	char	i;

	is_old = !ft_strcmp(argv[0], "-");
	if (!(i = ft_strcmp(argv[0], "~")))
	{
		temp = search_var(sh->t_env, "HOME");
		if (temp && temp->value)
			mallcheck(argv[0] = ft_strdup(&temp->value[5]));
	}
	tabchr(sh, argv[0], is_old);
	!i ? ft_memdel((void**)&argv[0]) : 0;
}
