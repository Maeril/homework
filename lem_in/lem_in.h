/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 19:33:20 by myener            #+#    #+#             */
/*   Updated: 2019/11/26 16:33:12 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648
# include <errno.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct			s_room  // for start room, end room, and classic in-between rooms.
{
		int				id;				// integer identifying the room.
        char            *name;          // name of the room.
		int				x;				// position of the room (easting).
		int				y;				// position of the room (northing).
        char            type;           // 's' if start room, 'e' if end room, 'c' if classic room.
        int             ant_nb_base;    // nb of ants present from the start.
        int             ant_nb_curr;    // nb of ants currently present. can only be <= 1 if type is 'c'.
                                        // when equal to base nb, current iteration is the first.
    	// struct s_room	**paths;        // directory containing all the connections this room possesses with other rooms.
    	int				**matrix;
		struct s_room	*next;			// may be unnecessary.
}			        t_room;

typedef struct 			s_link			// structure containing a connection between two rooms.
{
		t_room			a;				// first of the two connected rooms
		t_room			b;				// second of the two connected rooms
}						t_link;

typedef struct			s_ant   // a means of registrating each ant, and their progress through the maze.
{
	int             ant_nb;         // registration number for each ant, going from 1 to the max number of ants.
	char	        *position;      // room they are located in currently. can be equal to any *name in t_gate or t_room.
	struct s_pslist	*next;
	struct s_pslist	*prev;          // may be unnecessary.

}						t_ant;

#endif
