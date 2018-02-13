/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:59:46 by rorousse          #+#    #+#             */
/*   Updated: 2018/02/13 19:41:00 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

int		check_valid_path(t_piece *lst)
{
	while (lst)
	{
		if (lst->delim == START && lst->weight >= 0)
			return (1);
		lst = lst->next;
	}
	ft_putendl("INVALID PATH");
	return (0);
}

