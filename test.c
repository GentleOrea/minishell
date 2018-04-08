/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:20:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/08 17:35:31 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
int main(int ac, char **av, char **env)
{
//	pid_t father;
	g_shell		sh;
//	char *line;

	(void)ac;
	sh.env = env;
	init(&sh);
	//ft_cd(&sh, av[1]);
	execve("ls", av, sh.env);
	/*while (1)
	{
		ft_printf("$>");
		get_next_line(0, &line);
		father = fork();
		if (father > 0)
			wait(0);
		if (father == 0)
			execve(ft_strjoin("/bin/", line), av, sh.env);
	}*/
}
