/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:37:32 by rorousse          #+#    #+#             */
/*   Updated: 2016/11/24 14:37:33 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "../libft/libft.h"

static void		get_rooms(char *rooms[2], char *line)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	rooms[0] = (char*)malloc(ft_strlen(line) * sizeof(char));
	rooms[1] = (char*)malloc(ft_strlen(line) * sizeof(char));
	while (line[i] && line[i] != '-')
	{
		rooms[0][y] = line[i];
		i++;
		y++;
	}
	rooms[0][y] = '\0';
	i++;
	y = 0;
	while (line[i])
	{
		rooms[1][y] = line[i];
		i++;
		y++;
	}
	rooms[1][y] = '\0';
}

static t_link	*create_elem_link(char *rooms[2], t_piece *lst)
{
	t_link	*elem;

	if (!(elem = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	while (lst && ft_strcmp(lst->id, rooms[1]) != 0)
		lst = lst->next;
	elem->room = lst;
	elem->next = NULL;
	if (lst == NULL)
	{
		free(elem);
		return (NULL);
	}
	return (elem);
}


static int		binding(t_piece *lst, char *rooms[2])
{
	t_piece *tmp;
	t_link	*tmp_lnk;
	int		ret;

	ret = 0;
	tmp = lst;
	/*
	ft_putstr("Creation du lien de ");
	ft_putstr(rooms[0]);
	ft_putstr(" vers ");
	ft_putendl(rooms[1]);
	*/
	while (tmp != NULL && ret == 0)
	{
		if (ft_strcmp(tmp->id, rooms[0]) == 0)
		{
			ret = 1;
			tmp_lnk = tmp->links;
			if (tmp_lnk == NULL)
				tmp->links = create_elem_link(rooms, lst);
			else
			{
				while (tmp_lnk->next != NULL)
					tmp_lnk = tmp_lnk->next;
				tmp_lnk->next = create_elem_link(rooms, lst);
			}
		}
		tmp = tmp->next;
	}
	return (ret);
}

int			create_link(char *line, t_piece *lst)
{
	char	*rooms[2];
	char 	*tmp;
	int		ret;

	ret = 0;
	get_rooms(rooms, line);
	ret += binding(lst, rooms);
	tmp = rooms[0];
	rooms[0] = rooms[1];
	rooms[1] = tmp;
	ret += binding(lst, rooms);
	free(rooms[0]);
	free(rooms[1]);
	return ((ret == 2)? 1 : 0);
}