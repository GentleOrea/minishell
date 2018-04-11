/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:40:06 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/11 10:59:54 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		search_exec(g_shell *sh, char *comm, char *argv[])
{
	int		index;
	char	*temp;
	char	**paths;
	t_env	*path;

	fill_env(sh);
	if ((index = ft_strisin_tab(comm, sh->my_built, 0)) >= 0)
	{
		sh->f_built[index](sh, &argv[1]);
		return (1);
	}
	if (!(path = search_var(sh->t_env, "PATH"))->value)
		return (printf("command not found\n"));
	mallcheck(paths = ft_strsplit(&path->value[5], ':'));
	index = -1;
	!access(comm, F_OK | X_OK) ? execve(comm, argv, sh->env) : 0;
	while (paths[++index])
	{
		temp = ft_implode('/', paths[index], comm);
		!access(temp, F_OK | X_OK) ? execve(temp, argv, sh->env) : 0;
	}
	return (ft_printf("command not found : %s\n", comm));
}
