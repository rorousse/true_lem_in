/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:59:46 by rorousse          #+#    #+#             */
/*   Updated: 2016/11/09 12:00:31 by rorousse         ###   ########.fr       */
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
	return (0);
}

