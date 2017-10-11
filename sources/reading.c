/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:46:29 by rorousse          #+#    #+#             */
/*   Updated: 2016/11/04 12:46:31 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_link(char *line)
{
	int	i;
	
	i = 0;
	while (line[i] && ft_isalnum(line[i]))
		i++;
	if (line[i] != '-')
		return (0);
	i++;
	while (line[i] && ft_isalnum(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}

static int	is_piece(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isalnum(line[i]))
		i++;
	if (line[i] != ' ')
		return (0);
	i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i] != ' ')
		return (0);
	i++;
	while (line[i] && ft_isdigit(line[i]))
		i++;
	if (line[i])
		return (0);
	return (1);
}

static int	read_line(char *line, t_problem *pb, e_state lim)
{
	if (lim == ANTS)
	{
		pb->nb_ants = ft_atoi(line);
		return (1);
	}
	else if (is_link(line))
	{
		return (create_link(line, pb->lst));
	}
	else if (is_piece(line))
	{
		return (create_piece(line, &(pb->lst), lim));
	}
	return (0);
}

t_problem		get_setup(int fd)
{
	t_problem	pb;
	char 		*line;
	e_state			lim;

	lim = ANTS;
	pb.ret = 1;
	pb.lst = NULL;
	pb.ants = NULL;
	line = NULL;
	while (get_next_line(fd, &line) > 0 && pb.ret)
	{
		ft_putendl(line);
		if (line[0] != '#')
		{
			pb.ret = read_line(line, &pb, lim);
			lim = PIECE;
		}
		else if (ft_strcmp(line, "##start") == 0)
			lim = START;
		else if (ft_strcmp(line, "##end") == 0)
			lim = END;
		free(line);
	}
	free(line);
	return (pb);
}