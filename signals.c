/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:55:15 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/12 15:55:22 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mallcheck(void *str)
{
	if (str)
		return ;
	ft_printf("Erreur de malloc\n");
	exit(EXIT_FAILURE);
}

void	sig_handler(int signo)
{
	if (signo == SIGINT)
		ft_printf("\n{boldblue}$>{reset}");
}
