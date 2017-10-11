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

static int	check_delim(t_piece *lst)
{
	int lim_start;
	int lim_end;

	while (lst != NULL)
	{
		if (lst->delim == END || lst->delim == START)
		{
			if ((lst->delim == END && lim_end == 1) || (lst->delim == START && lim_start == 1))
				return (0);
			else if (lst->delim == START)
				lim_start = 1;
			else if (lst->delim == END)
				lim_end = 1;
		}
		lst = lst->next;
	}
	return ((lim_start + lim_end) == 2) ? 1 : 0;
}

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

int 	check_errors(t_piece *lst)
{
	return (check_delim(lst)) ? 1 : 0; 
}
