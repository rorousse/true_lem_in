/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:46:29 by rorousse          #+#    #+#             */
/*   Updated: 2018/02/13 19:35:39 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_ant(char *line)
{
	while (ft_isdigit(*line))
		line++;
	if (*line != 0)
		return (0);
	return (1);
}

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
		if (!is_ant(line))
			return (0);
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
	return (1);
}

t_problem		get_setup(int fd)
{
	t_problem	pb;
	char 		*line;
	e_state			lim;

	lim = ANTS;
	pb.nb_ants = 0;
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
		else if (ft_strcmp(line, "##start") == 0 && lim == PIECE)
			lim = START;
		else if (ft_strcmp(line, "##end") == 0 && lim == PIECE)
			lim = END;
		free(line);
	}
	if (line != NULL)
		free(line);
	return (pb);
}
