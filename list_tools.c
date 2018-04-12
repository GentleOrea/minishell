/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 18:52:17 by ygarrot           #+#    #+#             */
/*   Updated: 2018/04/11 19:18:46 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pop(t_env *env)
{
	env->prev->next = env->next;
	env->next->prev = env->prev;
}

t_env	*search_var(t_env *list, char *to_find)
{
	if (!list || !to_find)
		return (NULL);
	if (ft_strnstr(list->value, to_find, ft_strlen(list->value)))
		return (list);
	if (list->next && !ft_strnstr(list->value, to_find, ft_strlen(list->value)))
		return (search_var(list->next, to_find));
	mallcheck(list->next = (t_env*)ft_memalloc(sizeof(t_env)));
	list->next->prev = list;
	return (list->next);
}
