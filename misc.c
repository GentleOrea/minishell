/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 12:31:03 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/12 15:30:12 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_esc(char *str, int mal)
{
	int		lim;
	char	*ret;
	int		index;
	int		i;

	i = -1;
	lim = -1;
	mallcheck(ret = (char*)ft_memalloc(++mal * sizeof(char)));
	while (str[++i] && index != 7)
	{
		if (str[i] == '\\' &&
				(index = ft_charchr(str[i + 1], UNESC)) > 0 && ++i)
		{
			ret[++lim] = index < 7 ? ESC[index] :
				ft_atoi_base(&str[i + 1], (index - 7) * 8);
			if (index > 7)
				i += ft_occiter(&str[i + 1], (index - 7) * 8, ft_isbase);
		}
		else
			ret[++lim] = str[i];
	}
	return (ret);
}

char	*conv_esc(char *str)
{
	int		i;
	int		index;
	int		mal;

	mal = 0;
	i = -1;
	while (str[++i] && index != 7 && ++mal)
		if (str[i] == '\\' && (index = ft_charchr(str[i + 1], UNESC)) > 0)
			if (++i && index > 7)
				i += ft_occiter(&str[i + 1], (index - 7) * 8, ft_isbase);
	return (get_esc(str, mal));
}

void	ft_echo(g_shell *sh, char **argv)
{
	int	i;
	int	op;

	if (!argv)
		return ;
	i = 0;
	op = ft_strcmp(argv[0], "-n") ? 0 : 1;
	if (!ft_strcmp(argv[op ? ++i : 0], "-e"))
		op |= 2;
	i += (op == 2);
	while (argv[i])
	{
		op & 2 ? argv[i] = conv_esc(argv[i]) : 0;
		ft_printf(argv[i + 1] ? "%s " : "%s", argv[i]);
		op & 2 ? ft_memdel((void**)&argv[i]) : 0;
		i++;
	}
	!(op & 1) ? ft_putchar('\n') : 0;
	(void)sh;
}
