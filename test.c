/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 18:20:32 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/07 19:23:30 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_env(g_shell *sh);

void	tabchr(g_shell *sh, char *tofind, char *replace)
{
	int i;

	i = 0;
	(void)replace;
	while (sh->env[i] && !ft_strnstr(sh->env[i], tofind, ft_strlen(tofind)))
		i++;

	ft_printf("%d\n", sizeof(sh->env));
	//ft_realloc(sh->env, sizeof(sh->e))
		//	while (tab[i] && ft_strcmp(temp[0], tofind))
//		temp = ft_strnsplit(tab[i++], '=', 2);
}

void	ft_cd(g_shell *sh, const char *path)
{
	int		i;
	char	buf[256];
	i = 0;
(void)path;
(void)buf;
	int t = ft_sizeof_tab(sh->env);
	char **temp = ft_memalloc(t);
	ft_memcpy(temp, sh->env, t);
	//sh->env = ft_realloc(sh->env, t);
	
	ft_printf("{red}%d{reset}\n", t);
	tabchr(sh, "PWD", "titi");
	tabchr(sh, "OLDPWD", "toto");
	
	//chdir (path);
	sh->env = temp;
	ft_env(sh);
}

void ft_env(g_shell *sh)
{
	int i = -1;

	while(sh->env[++i])
		ft_printf("%s\n", sh->env[i]);
	ft_memdel((void**)&sh->env);
}

int main(int ac, char **av, char **env)
{
//	pid_t father;
	g_shell		sh;
//	char *line;

	(void)ac;
	sh.env = env;
	ft_cd(&sh, av[1]);
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
