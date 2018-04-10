/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:31:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/10 19:21:03 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*conv_esc(char *str)
{
	int		i;
	char	*ret;
	int		index;
	int		mal;
	int		lim;

	mal = 0;
	i = -1;
	while (str[++i] && index != 7 && ++mal)
		if (str[i] == '\\' && (index = ft_charchr(str[i + 1], UNESC)) > 0 && ++i)
			index > 7 ? i += ft_occiter(&str[i + 1], (index - 7) * 8, ft_isbase): 0;
	mallcheck(ret = (char*)ft_memalloc(++mal * sizeof(char)));
	i = -1;
	lim = -1;
	while (str[++i] && index != 7)
	{
		if (str[i] == '\\' && (index = ft_charchr(str[i + 1], UNESC)) > 0 && ++i)
		{
			ret[++lim] = index < 7 ? ESC[index] : ft_atoi_base(&str[i + 1], (index - 7) * 8);
			index > 7 ? i += ft_occiter(&str[i + 1], (index - 7) * 8, ft_isbase) : 0;
		}
		else
			ret[++lim] = str[i];
	}
	return (ret);
}

void	ft_echo(g_shell *sh, char **argv)
{
	int	i;
	int	op;
	
	if (!argv)
		exit(EXIT_FAILURE);
	i = 0;
	op = ft_strcmp(argv[0], "-n") ? 0 : 1;
	op |= ft_strcmp(argv[op ? ++i : 0], "-e") ? 0 : 2;
	i += (op == 2);
	while (argv[i])
	{
		op & 2 ? argv[i] = conv_esc(argv[i]) : 0;
		ft_printf(argv[i + 1] ? "%s " : "%s",argv[i]);
		op & 2 ? ft_memdel((void**)&argv[i]) : 0;
		i++;
	}
	!(op & 1) ? ft_putchar('\n') : 0;
	(void)sh;
	exit(EXIT_SUCCESS);
}

void ft_exit(g_shell *sh, char *argv[])
{
	(void)sh;
	(void)argv;
	//exit(sign);
}
