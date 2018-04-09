/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:31:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/09 12:51:31 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(g_shell *sh, char *argv[])
{
	
	if (!argv)
		return ;
	(void)sh;
	//ft_putendl(argv);
}

void ft_exit(g_shell *sh, char *argv[])
{
	(void)sh;
	(void)argv;
	//exit(sign);
}
