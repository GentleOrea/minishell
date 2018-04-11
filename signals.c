/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:55:15 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/11 11:32:47 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sig_handler(int signo)
{
	if (signo == SIGINT)
		ft_printf("\n{boldblue}$>{reset} ☯ ");
	else if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGKILL)
		exit(1);
	else if (signo == SIGSTOP)
		printf("received SIGSTOP\n");
}

void	sig_run(void)
{
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGINT\n");
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGUSR1\n");
}

/*int		term(void)
{
	char           *name_term;
	struct termios term;

	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, &name_term) == ERR)
		return (-1);
	// remplis la structure termios des possibilités du terminal.
	if (tcgetattr(0, term) == -1)
		return (-1);
	voir_touche();
	ireturn (0);
}*/
