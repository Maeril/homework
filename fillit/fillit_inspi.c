/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_inspi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:16:32 by mpicard           #+#    #+#             */
/*   Updated: 2019/01/23 15:54:10 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = fillit

SRC = fillit.c list.c solve.c get_next_line.c check_link.c solve_bis.c \
		fillit_bis.c

OBJ = fillit.o list.o solve.o get_next_line.o check_link.o solve_bis.o \
		fillit_bis.o

FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -c $(SRC)
	gcc $(OBJ) libft/libft.a -o $(NAME)

clean:
	/bin/rm -rf $(OBJ)
	make clean -C libft/

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:42:13 by mpicard           #+#    #+#             */
/*   Updated: 2019/01/19 15:41:51 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		add_y(t_coord *coord_tab, int k, int j)
{
	int res;

	res = coord_tab[k].y - coord_tab[j].y;
	if (res < 0)
		res = -res;
	return (res);
}

int		add_x(t_coord *coord_tab, int k, int j)
{
	int res;

	res = coord_tab[k].x - coord_tab[j].x;
	if (res < 0)
		res = -res;
	return (res);
}

int		check_connection(t_coord *coord_tab, t_liste *liste)
{
	int tmp;

	tmp = 0;
	if (add_x(coord_tab, 0, 1) + (add_y(coord_tab, 0, 1)) == 1)
		tmp++;
	if (add_x(coord_tab, 0, 2) + (add_y(coord_tab, 0, 2)) == 1)
		tmp++;
	if (add_x(coord_tab, 0, 3) + (add_y(coord_tab, 0, 3)) == 1)
		tmp++;
	if (add_x(coord_tab, 1, 2) + (add_y(coord_tab, 1, 2)) == 1)
		tmp++;
	if (add_x(coord_tab, 1, 3) + (add_y(coord_tab, 1, 3)) == 1)
		tmp++;
	if (add_x(coord_tab, 2, 3) + (add_y(coord_tab, 2, 3)) == 1)
		tmp++;
	if (tmp >= 3)
		return (2);
	else
		return (0);
}

int		check_dot(char tab[5][5])
{
	int i;
	int j;
	int dot;

	i = 0;
	dot = 0;
	while (*tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '.')
				dot++;
			j++;
		}
		i++;
	}
	return (dot);
}

int		check_sharp(char tab[5][5])
{
	int i;
	int j;
	int sharp;

	i = 0;
	sharp = 0;
	while (*tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
				sharp++;
			j++;
		}
		i++;
	}
	return (sharp);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:49:21 by mpicard           #+#    #+#             */
/*   Updated: 2019/01/19 15:43:51 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "fillit.h"

int			line_read(char tetri[5][5], char *line, int line_tetri,
		t_liste *liste)
{
	int		nb_tetri;

	if (check_line(line) == -1)
	{
		free_list(liste);
		write_error_message(1);
	}
	ft_strcpy(tetri[line_tetri], line);
	if (line_tetri == 3)
	{
		nb_tetri++;
		if (check_dot(tetri) != 12 || check_sharp(tetri) != 4)
		{
			free_list(liste);
			write_error_message(1);
		}
		list_add_last(liste, parse_tetri(tetri, liste));
		if (nb_tetri == 1)
		{
			liste->first = liste->last;
			liste->first->letter = 'A';
		}
	}
	line_tetri++;
	return (line_tetri);
}

int			read_file(int fd, t_liste *liste)
{
	char		*line;
	char		tetri[5][5];
	int			line_tetri;

	line_tetri = 0;
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
			line_tetri = line_read(tetri, line, line_tetri, liste);
		if (line[0] == '\0')
		{
			line_break(line_tetri, tetri, liste);
			line_tetri = 0;
		}
	}
	if (line_tetri != 4 || check_dot(tetri) != 12 || check_sharp(tetri) != 4)
	{
		free_list(liste);
		write_error_message(1);
	}
	free(line);
	return (1);
}

int			open_file(char *filename)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("erreur fichier\n");
		return (-1);
	}
	return (fd);
}

int			main(int argc, char *argv[])
{
	int		fd;
	t_liste	*liste;

	if (argc != 2)
	{
		ft_putstr("usage : ./fillit [filename]\n");
		exit(EXIT_FAILURE);
	}
	fd = open_file(argv[1]);
	liste = list_init();
	read_file(fd, liste);
	solve_fillit(liste);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:52:17 by mpicard           #+#    #+#             */
/*   Updated: 2019/01/19 15:43:29 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef	struct			s_tetris
{
	t_coord				*coord_tab;
	char				letter;
	struct s_tetris		*next;
}						t_tetris;

typedef	struct			s_liste
{
	t_tetris			*first;
	t_tetris			*last;
	int					size_liste;
}						t_liste;

char					**init_grid(int size);
char					**solve_fillit(t_liste *liste);
int						add_y(t_coord *coord_tab, int k, int j);
int						add_x(t_coord *coord_tab, int k, int j);
int						check_connection(t_coord *coord_tab, t_liste *liste);
int						check_dot(char tab[5][5]);
int						check_line(char *line);
int						check_sharp(char tab[5][5]);
int						find_size(int n);
int						get_next_line(const int fd, char **line);
int						main(int argc, char *argv[]);
int						open_file(char *filename);
int						put_tetri(char ***grid, t_tetris *tetri, int size,
		int i_grid);
int						read_file(int fd, t_liste *liste);
int						space_for_tetri(t_tetris *tetri, char ***grid,
		int i_grid,
		int j_grid);
t_coord					*parse_tetri(char tab[5][5], t_liste *liste);
t_liste					*list_init(void);
void					write_error_message(int i);
void					line_break(int line_tetri, char tetri[5][5], t_liste *liste);
void					erase_tetri(t_tetris *tetri, char ***grid,
		int i_grid, int j_grid);
void					free_grid(char ***grid);
void   					 free_list(t_liste *liste);
void					ft_putchar(char c);
void					list_add_last(t_liste *liste, t_coord *coord_tab);
void					list_print(t_liste *liste);
void					print_grid(char **grid);
void					write_tetri(t_tetris *tetri, char ***grid,
		int i_grid, int j_grid);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 16:43:45 by mpicard           #+#    #+#             */
/*   Updated: 2019/01/19 15:41:14 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "fillit.h"

int			check_line(char *line)
{
	int len;
	int i;

	len = ft_strlen(line);
	if (len != 4)
	{
		ft_putstr("error");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (line[i])
	{
		if (line[i] != '.' && line[i] != '#')
		{
			ft_putstr("error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (1);
}

void		write_error_message(int i)
{
	ft_putstr("error");
	exit(EXIT_FAILURE);
}

void		end_pars(t_coord *coord_tab, t_liste *liste)
{
	int k;
	int mini;
	int minj;

	k = 0;
	mini = 6;
	minj = 6;
	while (k < 3)
	{
		if (coord_tab[k].x < mini)
			mini = coord_tab[k].x;
		if (coord_tab[k].y < minj)
			minj = coord_tab[k].y;
		k++;
	}
	k = 0;
	while (k < 4)
	{
		coord_tab[k].x -= mini;
		coord_tab[k].y -= minj;
		k++;
	}
	if (check_connection(coord_tab, liste) == 0)
	{
		free_list(liste);
		write_error_message(1);
	}
}

t_coord		*parse_tetri(char tab[5][5], t_liste *liste)
{
	t_coord		*coord_tab;
	int			i;
	int			j;
	int			k;

	coord_tab = (t_coord*)malloc(sizeof(t_coord) * 4);
	i = 0;
	k = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				coord_tab[k].x = i;
				coord_tab[k].y = j;
				k++;
			}
			j++;
		}
		i++;
	}
	end_pars(coord_tab, liste);
	return (coord_tab);
}

void		line_break(int line_tetri, char tetri[5][5], t_liste *liste)
{
	if (line_tetri != 4)
	{
		free_list(liste);
		write_error_message(1);
	}
	else
	{
		tetri[line_tetri][0] = '\0';
		if (check_dot(tetri) != 12 || check_sharp(tetri) != 4)
			write_error_message(1);
		line_tetri = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:51:20 by mpicard           #+#    #+#             */
/*   Updated: 2019/01/19 15:20:12 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

t_liste		*list_init(void)
{
	t_liste		*liste;
	t_tetris	*element;

	liste = malloc(sizeof(*liste));
	element = malloc(sizeof(*element));
	if (liste == NULL || element == NULL)
		exit(EXIT_FAILURE);
	element->letter = 'A';
	element->next = NULL;
	element->coord_tab = NULL;
	liste->first = element;
	liste->last = element;
	liste->size_liste = 0;
	return (liste);
}

void		list_add_last(t_liste *liste, t_coord *coord_tab)
{
	t_tetris	*new;

	new = malloc(sizeof(*new));
	if (liste == NULL || new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->coord_tab = coord_tab;
	liste->last->next = new;
	new->letter = (liste->last->letter) + 1;
	new->next = NULL;
	liste->last = new;
	liste->size_liste = (liste->size_liste) + 1;
}


void	free_list(t_liste *liste)
{
	t_tetris *actuel;
	t_tetris *tmp;

	actuel = liste->first;
	while (actuel != NULL)
	{
		free(actuel->coord_tab);
		tmp = actuel->next;
		free(actuel);
		actuel = tmp;
	}
	actuel = NULL;
	liste = NULL;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 11:51:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/01/19 15:31:11 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		put_tetri(char ***grid, t_tetris *tetri, int size, int i_grid)
{
	int j_grid;

	while (i_grid < size)
	{
		j_grid = 0;
		while (j_grid < size)
		{
			while (space_for_tetri(tetri, grid, i_grid, j_grid))
			{
				if (tetri->next != NULL)
				{
					if (put_tetri(grid, tetri->next, size, 0))
						return (1);
					else
						erase_tetri(tetri, grid, i_grid, j_grid);
					j_grid++;
				}
				else
					return (1);
			}
			j_grid++;
		}
		i_grid++;
	}
	return (0);
}

char	**init_grid(int size)
{
	char	**grid;
	int		i;
	int		j;

	if (!(grid = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(grid[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		while (j < size)
		{
			grid[i][j] = '.';
			j++;
		}
		grid[i][j] = '\0';
		i++;
	}
	return (grid);
}

void	print_grid(char **grid)
{
	int i;

	i = 0;
	while (grid[i])
	{
		ft_putstr(grid[i]);
		ft_putchar('\n');
		i++;
	}
}

char	**solve_fillit(t_liste *liste)
{
	char		**grid;
	int			size;
	int			i_grid;
	t_tetris	*tetri;

	tetri = liste->first;
	i_grid = 0;
	size = find_size(liste->size_liste);
	grid = init_grid(size);
	while (put_tetri(&grid, tetri, size, i_grid) == 0)
	{
		free_grid(&grid);
		size++;
		grid = init_grid(size);
	}
	print_grid(grid);
	free_list(liste);
	return (grid);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 11:48:35 by mpicard           #+#    #+#             */
/*   Updated: 2019/01/19 15:04:13 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_grid(char ***grid)
{
	int i;

	i = 0;
	while ((*grid)[i])
	{
		free((*grid)[i]);
		i++;
	}
	free(*grid);
}

int		find_size(int n)
{
	int i;
	int j;

	i = n * 4;
	j = 0;
	while (j * j < i)
		j++;
	return (j);
}

void	erase_tetri(t_tetris *tetri, char ***grid, int i_grid, int j_grid)
{
	int k;
	int x;
	int y;

	k = 0;
	while (k < 4)
	{
		x = tetri->coord_tab[k].x + i_grid;
		y = tetri->coord_tab[k].y + j_grid;
		(*grid)[x][y] = '.';
		k++;
	}
}

void	write_tetri(t_tetris *tetri, char ***grid, int i_grid, int j_grid)
{
	int k;
	int x;
	int y;

	k = 0;
	while (k < 4)
	{
		x = tetri->coord_tab[k].x + i_grid;
		y = tetri->coord_tab[k].y + j_grid;
		(*grid)[x][y] = tetri->letter;
		k++;
	}
}

int		space_for_tetri(t_tetris *tetri, char ***grid, int i_grid, int j_grid)
{
	int k;
	int x;
	int y;
	int size;

	size = 0;
	while ((*grid)[size])
		size++;
	k = 0;
	while (k < 4)
	{
		x = tetri->coord_tab[k].x + i_grid;
		y = tetri->coord_tab[k].y + j_grid;
		if (x >= size || y >= size)
			return (0);
		else if ((*grid)[x][y] != '.')
			return (0);
		k++;
	}
	write_tetri(tetri, grid, i_grid, j_grid);
	return (1);
}