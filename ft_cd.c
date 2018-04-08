/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 11:10:57 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/08 19:00:36 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	tabchr(g_shell *sh)
{
	int		i;
	int		i2;
	char	path[256];

	i = 0;
	i2 = 0;
	while (sh->env[i] && !ft_strnstr(sh->env[i], "PWD", 3))
		i++;
	while (sh->env[i2] && !ft_strnstr(sh->env[i2], "OLDPWD", 5))
		i2++;
//	!sh->oldpw || sh->is_old ? getcwd(path, 256) : 0;
//	!sh->oldpw ? sh->oldpw = path : 0;
//	chdir (sh->is_old ? sh->oldpw : path);
	getcwd(path, 256);
	//sh->env[i] = ft_strjoin("PWD=", path);
	sh->env[1] = ft_strjoin("OLDPWD=", sh->oldpw);
//	sh->oldpw = path;
}

void	ft_cd(g_shell *sh, const char *path)
{
	if (!ft_strcmp(path, "-"))
		sh->is_old = 1;

	tabchr(sh);
	ft_env(sh);
}
