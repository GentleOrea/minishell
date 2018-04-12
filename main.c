/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:20:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/12 15:49:57 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_exec(g_shell *sh, char **space)
{
	int index;

	if ((index = ft_strisin_tab(space[0], sh->my_built, 0)) >= 0)
		sh->f_built[index](sh, &space[1]);
	else
		search_exec(sh, space[0], space);
	!sh->free ? ft_free_dblechar_tab(space) : 0;
}

void	exe(g_shell *sh, char *comm, char **argv)
{
	pid_t father;

	father = fork();
	(father != 0) ? wait(0) : execve(comm, argv, sh->env);
}

int		search_exec(g_shell *sh, char *comm, char *argv[])
{
	int		index;
	char	*temp;
	char	**paths;
	t_env	*path;

	temp = NULL;
	fill_env(sh);
	!access(comm, F_OK | X_OK) ? exe(sh, comm, argv) : 0;
	if (!(path = search_var(sh->env_t, "PATH"))->value)
		return (ft_printf("command not found : %s \n", comm));
	mallcheck(paths = ft_strsplit(&path->value[5], ':'));
	index = -1;
	while (paths[++index] && !temp)
	{
		temp = ft_implode('/', paths[index], comm);
		!access(temp, F_OK | X_OK) ? exe(sh, temp, argv) :
			ft_memdel((void**)&temp);
	}
	temp ? ft_memdel((void**)&temp) :
		ft_printf("command not found : %s \n", comm);
	ft_free_dblechar_tab(paths);
	return (1);
}

void	comm(g_shell *sh, char **comma)
{
	char	**space;
	int		i;

	i = -1;
	while (comma[++i])
	{
		mallcheck(space = ft_strsplit(comma[i], ' '));
		if (!ft_strcmp(comma[i], "exit"))
		{
			ft_free_dblechar_tab(space);
			exit(ft_atoi(comma[i]));
		}
		wait_exec(sh, space);
	}
}

int		main(int ac, char **av, char **env)
{
	g_shell		sh;
	char		*line;
	char		**comma;

	(void)ac;
	(void)av;
	init(&sh, env);
	while (1)
	{
		ft_printf("{boldblue}%s{reset} ☯ ", sh.pwd);
		signal(SIGINT, sig_handler);
		if (get_next_line(0, &line) <= 0)
			erase_shell(&sh);
		mallcheck(comma = ft_strsplit(line, ';'));
		comm(&sh, comma);
		ft_memdel((void**)&line);
		ft_free_dblechar_tab(comma);
	}
}
