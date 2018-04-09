/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 13:39:50 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/09 10:49:31 by ygarrot          ###   ########.fr       */
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
