/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:20:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/12 17:33:15 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_exec(t_shell *sh, char **space)
{
	int index;

	if ((index = ft_strisin_tab(space[0], sh->my_built, 0)) >= 0)
		sh->f_built[index](sh, &space[1]);
	else
	{
		fill_env(sh);
		if (!access(space[0], F_OK | X_OK))
			exe(sh, space[0], space);
		else
			search_exec(sh, space[0], space);
	}
	!sh->free ? ft_free_dblechar_tab(space) : 0;
}

void	exe(t_shell *sh, char *comm, char **argv)
{
	pid_t father;

	father = fork();
	(father != 0) ? wait(0) : execve(comm, argv, sh->env);
}

int		search_exec(t_shell *sh, char *comm, char *argv[])
{
	int		index;
	char	*temp;
	char	**paths;
	t_env	*path;

	temp = NULL;
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

void	comm(t_shell *sh, char **comma)
{
	int		i;

	i = -1;
	while (comma[++i])
	{
		mallcheck(sh->space = ft_strsplit(comma[i], ' '));
		if (!ft_strcmp(comma[i], "exit"))
		{
			ft_free_dblechar_tab(sh->space);
			erase_shell(sh);
		}
		wait_exec(sh, sh->space);
	}
}

int		main(int ac, char **av, char **env)
{
	t_shell		sh;
	char		*line;

	(void)ac;
	(void)av;
	init(&sh, env);
	while (1)
	{
		ft_printf("{boldblue}%s{reset} ☯ ", sh.pwd);
		signal(SIGINT, sig_handler);
		if (get_next_line(0, &line) <= 0)
			erase_shell(&sh);
		mallcheck(sh.comma = ft_strsplit(line, ';'));
		ft_memdel((void**)&line);
		comm(&sh, sh.comma);
		ft_free_dblechar_tab(sh.comma);
	}
}
