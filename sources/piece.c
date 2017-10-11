/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 13:02:05 by rorousse          #+#    #+#             */
/*   Updated: 2016/11/04 13:02:06 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "lem_in.h"
#include "../libft/libft.h"

static int		check_double(t_piece *lst, char *id)
{
	while (lst)
	{
		if (ft_strcmp(lst->id, id) == 0)
			return (1);
		lst = lst->next;
	}
	return (0);
}

static t_piece	*create_elem_piece(char *line, int lim, t_piece *lst)
{
	t_piece *elem;
	char 	**tmp;

	elem = NULL;
	if ((tmp = ft_strsplit(line, ' ')) == NULL)
		return (NULL);
	if (!check_double(lst, tmp[0]))
	{
		if ((elem = (t_piece*)malloc(sizeof(t_piece))) == NULL)
			return (NULL);
		elem->id = ft_strdup(tmp[0]);
		elem->abs = ft_atoi(tmp[1]);
		elem->ord = ft_atoi(tmp[2]);
		elem->delim = lim;
		elem->weight = -1;
		elem->weight_set = 0;
		elem->full = 0;
		elem->next = NULL;
		elem->links = NULL;
	}
	ft_free_double_str(tmp);
	return (elem);
}

int			create_piece(char *line, t_piece **lst, int lim)
{
	t_piece *tmp;
	t_piece *elem;

	tmp = *lst;
	if (*lst == NULL)
	{
		elem = create_elem_piece(line, lim, *lst);
		*lst = elem;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		elem = create_elem_piece(line, lim, *lst);
		tmp->next = elem;
	}
	return (elem == NULL)? 0 : 1;
}
