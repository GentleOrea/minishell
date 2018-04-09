/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:55:15 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/09 14:05:58 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void  signin_handler(int sig)
{
	signal(sig, SIG_IGN);
	printf("From SIGINT: just got a %d (SIGINT ^C) signal\n", sig);
	signal(sig, signin_handler);
}

void  sigquit_handler(int sig)
{
	signal(sig, SIG_IGN);
	printf("From SIGQUIT: just got a %d (SIGQUIT ^\\) signal"
			" and is about to quit\n", sig);
	exit(3);
}

