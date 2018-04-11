/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:20:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/11 11:32:40 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int main(int ac, char **av, char **env)
{
	pid_t father;
	g_shell		sh;
	char	*line;
	char	**comma;
	char	**space;

	char buff[256];

	(void)ac;(void) av;
	init(&sh, env);
	while (1)
	{
		ft_printf("{boldblue}%s{reset} ☯ " , sh.pwd);
		sig_run();
		get_next_line(0, &line);
		if(!(comma = ft_strsplit(line, ';')))
			exit (1);
		int i = -1;
		while(comma[++i])
		{
			mallcheck(space = ft_strsplit(comma[i], ' '));
			father = fork();
			if (father > 0)
				wait(0);
			if (father == 0)
				search_exec(&sh, space[0], space);
		}
	}
}
