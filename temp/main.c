/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:20:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/07 12:29:49 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int main(int ac, char **av, char **env)
{
	pid_t father;
	char *line;

	(void)ac;
	while(*env)
		ft_printf("%s\n", *env++);
	int i = 0;
	while (1)
	{
		i++;
		get_next_line(0, &line);
		father = fork();
		if (father > 0)
			wait(0);
		if (father == 0)
		{
			ft_printf("[%d]\n", i);
			execve(ft_strjoin("/bin/", line), av, env);
		}
	}
	ft_printf("End main\n");
}
