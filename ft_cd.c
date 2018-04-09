/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:10:57 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/09 18:06:46 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tabchr(g_shell *sh, char *arg)
{
	t_env	*pwd;
	t_env	*oldpwd;
	char	path[256];

	pwd = search_var(sh->t_env, "PWD");
	oldpwd = search_var(sh->t_env, "OLDPWD"); 

	if (chdir(sh->is_old ? sh->oldpwd : arg))
		ft_printf("{red}%d->%s{reset}\n",sh->is_old, sh->oldpwd);
	getcwd(path, 256);
	sh->oldpwd = &pwd->value[4];
	sh->pwd = ft_strdup(path);
	pwd->value = ft_strjoin("PWD=", path);
	oldpwd->value = ft_strjoin("OLDPWD=", sh->oldpwd);
}

void	ft_cd(g_shell *sh, char *argv[])
{
	t_env	*temp;

	sh->is_old = !ft_strcmp(argv[0], "-");
	if(!ft_strcmp(argv[0], "~"))
	{
		temp = search_var(sh->t_env, "HOME");
		if (!temp)
			ft_printf("pas de home\n");
		argv[0] = &temp->value[5];
	}
	tabchr(sh, argv[0]);
}