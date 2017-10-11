/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:24:58 by rorousse          #+#    #+#             */
/*   Updated: 2016/11/04 12:25:00 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/libft.h"

typedef struct s_link	t_link;
typedef struct s_piece	t_piece;
typedef struct s_ants	t_ants;
typedef struct s_problem t_problem;
typedef enum e_state		e_state;

enum e_state {ANTS, PIECE, START, END};

struct					s_link
{
	t_piece			*room;
	struct s_link	*next;
};

struct					s_piece
{
	char			*id;
	int				abs;
	int				ord;
	e_state			delim;
	int 			weight;
	int				weight_set;
	int				full;
	t_link			*links;
	struct s_piece	*next;
};

struct s_ants
{
	t_piece *room;
};

struct s_problem
{
	int		nb_ants;
	int		ret;
	t_ants	*ants;
	t_piece	*lst;
};

/*
**	ANTS_C
*/

void					create_ants(t_problem *pb);

/*
**	CHECKING_C
*/

int					 	check_errors(t_piece *lst);
int						check_valid_path(t_piece *lst);

/*
**	END_C
*/

void					free_pieces(t_piece *lst);

/*
** INIT_ALGO
*/

void					set_weight(t_piece *lst);

/*
** LINKS_C
*/

int						create_link(char *line, t_piece *lst);

/*
**	PATHFINDING_C
*/

void					ft_resolve(t_problem pb);

/*
** PIECE_C
*/

int						create_piece(char *line, t_piece **lst, int lim);

/*
** READING_C
*/

t_problem				get_setup(int fd);

/*
** TESTING_C
*/

void						aff_lst(t_piece *lst);

#endif
