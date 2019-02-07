/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:52:42 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/07 15:35:30 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

/*J'ai simplifie l'ecriture ici: */
t_data		parse_size(char *instructions, t_data data, unsigned int i)
{
	if ((data.l = (instructions[i] == 'l')))
		data.ll = (instructions[++i] == 'l');
	else if ((data.h = (instructions[i] == 'h')))
		data.hh = (instructions[++i] == 'h');
	i++;
	printf("data.ll = %d\n", data.ll);
	return (data);
}

t_data		parse_precision(char *instructions, t_data data, int i)
{
//	printf("instructions[i] == . ? %c\n", instructions[i]);
//	printf("instructions[i -1] == 5 ? %c\n", instructions[i - 1]);
	if (instructions[i - 1] && instructions[i - 1] >= '0' && instructions[i - 1] <= '9')
	{
//		printf("OUI J ENTRE ICI LIGNE 70\n\n");
		data.width = 1;
//		printf("data.width = 1 ? %d\n", data.width);
	}
	if (instructions[i + 1] >= '0' && instructions[i + 1] <= '9')
		data.precision = 1;
	while (instructions[i + 1] >= '0' && instructions[i + 1] <= '9')
		i++;
	return (data);
}

t_data		parse_width(char *instructions, t_data data, int i)
{
	while (instructions[i] >= '0' && instructions[i] <= '9')
	{
		data.width = 1;
		i++;
	}
	return (data);
}

t_data		parse_flags(char *instructions, t_data data, int i)
{
	while (instructions[i] == '-' || instructions[i] == '+' ||
			instructions[i] == '0' || instructions[i] == ' ' ||
			instructions[i] == '#')
	/*J'ai simplifie l'ecriture ici: */
	{
		data.minus = (instructions[i] == '-');
		data.plus = (instructions[i] == '+');
		data.zero = (instructions[i] == '0');
		data.space = (instructions[i] == ' ');
		data.sharp = (instructions[i] == '#');
		/*Je gere les cas ou un caractere en exclut un autre: */

		i++;
	}
	return (data);
}

t_data		parse_instructions(char *instructions, t_data data)
{
	int i;

	i = 0;
	while (instructions[i])
	{
		if (instructions[i] == '-' || instructions[i] == '+' ||
				instructions[i] == '0' || instructions[i] == ' ' ||
				instructions[i] == '#')
			data = parse_flags(instructions, data, i);// i est sur le dernier'flag'
		i++;
		if (instructions[i] >= '0' && instructions[i] <= '9')
			data = parse_width(instructions, data, i);
		i++;
		if (instructions[i] == '.')
			data = parse_precision(instructions, data, i);
		if (instructions[i] == 'h' || instructions[i] == 'l')
			data = parse_size(instructions, data, i);
	}
	return (data);
}


char		*take_instructions(const char *format, int i)
{
	int     tmp;
	char    *instructions;

	i++;
	tmp = i;
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' &&
			format[i] != 'd' && format[i] != 'i' && format[i] != 'o' &&
			format[i] != 'u' && format[i] != 'x' && format[i] != 'X'
			&& format[i])
		i++;
	instructions = ft_strsub(format, tmp, i - tmp + 1);
	return (instructions);
}

void		put_text(va_list ap, const char *format)
{
	//afficher format tant que ce n'est pas %
	int i;
	char	*instructions;
	t_data	data;

	//j'affiche data avant de modifier
	printf("avant\n");
	printf("data.minus = %d\n", data.minus);
	printf("data.plus = %d\n", data.plus);
	printf("data.zero = %d\n", data.zero);
	printf("data.space = %d\n", data.space);
	printf("data.sharp = %d\n", data.sharp);
	printf("data.width = %d\n", data.width);
	printf("data.precision = %d\n", data.precision);
	printf("data.h = %d\n", data.h);
	printf("data.ll = %d\n", data.ll);
	printf("data.l = %d\n", data.l);
	printf("data.hh = %d\n", data.hh);
	printf("fin de avant \n");

	i = 0;
	while (format[i])
	{
		//		if (format[i] != '%')
		//			ft_putchar(format[i]);
		if  (format[i] == '%')
		{
			instructions = take_instructions(format, i);
			data = parse_instructions(instructions, data);
		}
		i++;
	}
	// j'affiche data apres
	printf("apres\n");
	printf("data.minus = %d\n", data.minus);
	printf("data.plus = %d\n", data.plus);
	printf("data.zero = %d\n", data.zero);
	printf("data.space = %d\n", data.space);
	printf("data.sharp = %d\n", data.sharp);
	printf("data.width = %d\n", data.width);
	printf("data.precision = %d\n", data.precision);
	printf("data.h = %d\n", data.h);
	printf("data.ll = %d\n", data.ll);
	printf("data.l = %d\n", data.l);
	printf("data.hh = %d\n", data.hh);

	printf("instructions = %s\n", instructions);
}


int			ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	put_text(ap, format);
	va_end(ap);
	return (1); // retourner la bonne valeur
}

int			main(void)
{
	char 	*format;

	format = "j'essaie de creer un argument valide %-+0 #45.10hs est-ce que je vais bien jusque la ?";
//	printf("j'essaie de creer un argument valide %-#08.5lld\n", 42);
	ft_printf(format);
//	printf(" un %###3d\n", 2);
	return (0);
}


/*

   - c'est repare : si je donne l'instruction %.10s -> data voit
   a la fois une precision ET une width, alors qu'il n y a
   qu'une precision. je vais mettre dans parse_width le fait
   quil faut verifier quand on voit un chiffre que sil y
   a un point AVANT, alors on ne compte pas le width.

   - c'est repare : si il y a la fois width ET precision, data ne compte QUE precision.
   je vais modifier parse_precision et dire que sil y a des chiffres avant le point, alors
   on compte les deux.

  - a faire : gerer le cas ou il y a plusieurs points dans une precision, alors qu il
  n'est cense n'y en avoir qu'un.

  - il faut trouver un moyen de ne pas affichers les instructions venant juste apres le %
  (les caracteres qui sont dans la chaine de caractere instructions.

  - je vais enlever de la fonction PUT TEXT l'argent ap parce que je ne l'utilise pas encore
  et que ca empeche le Makefile de fonctionner

  - a reparer : le cas ou la width ou precision est une etoile
*/
