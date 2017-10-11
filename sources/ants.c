/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:30:29 by rorousse          #+#    #+#             */
/*   Updated: 2016/11/24 15:30:30 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	create_ants(t_problem *pb)
{
	int	i;
	t_piece *start;

	i = 0;
	pb->ants = (t_ants*)malloc(pb->nb_ants * sizeof(t_ants));
	start = pb->lst;
	while (start && start->delim != START)
		start = start->next;
	while (pb->ants && i < pb->nb_ants)
	{
		pb->ants[i].room = start;
		(start->full)++;
		i++;
	}
}