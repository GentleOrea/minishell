/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:20:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/10 19:13:04 by ygarrot          ###   ########.fr       */
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

	(void)ac;(void) av;
	init(&sh, env);
	while (1)
	{
		ft_printf("{boldblue}%s{reset}☯ ", sh.pwd);
		get_next_line(0, &line);
		mallcheck(comma = ft_strsplit(line, ';'));
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
