/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:52:42 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/11 11:32:21 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

char		*take_instructions(const char *format, int i)
{
	int		tmp;
	char	*instruc;
	char	*str;
	int		k;
	int		j;

	i++;
	tmp = i;
	while (format[i] != 'c' && format[i] != 's' && format[i] != 'p' &&
			format[i] != 'd' && format[i] != 'i' && format[i] != 'o' &&
			format[i] != 'u' && format[i] != 'x' && format[i] != 'X'
			&& format[i])
		i++;
	if (!format)
		return (NULL);
	if (!(str = malloc(sizeof(*format) * ((i - tmp + 1) + 1))))
		return (NULL);
	k = tmp;
	j = 0;
	while (format[k] && k < tmp + (i - tmp + 1))
		str[j++] = format[k++];
	str[j] = '\0';
	instruc = str;
	return (instruc);
}

void		put_text(va_list ap, const char *format)
{
	int		i;
	char	*instruc;
	t_data	data;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			instruc = take_instructions(format, i);
			data = parse_instructions(instruc, data);
            data = finalize_instructions(data);
            data = find_arg_type(ap, data, instruc, i);
            data = clean_data(data);
            i++;
		}
		i++;
	}
}


int			ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	put_text(ap, format);
	va_end(ap);
	return (1); // retourner la bonne valeur
}



/* il faudra mettre ce main en commentaire pour que le testeur fonctionne;
ensuite faire make, puis copier coller libftprintf.a dans le dossier du testeur,
et refaire make.*/


int			main(void)
{
	char 	*format;

	format = "j'essaie de creer un argument valide %-+0 #45.10hs est-ce que je vais bien jusque la ?";
	ft_printf(format);
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

  - il faut trouver un moyen de ne pas affichers les instruc venant juste apres le %
  (les caracteres qui sont dans la chaine de caractere instruc.

  - je vais enlever de la fonction PUT TEXT l'argument ap parce que je ne l'utilise pas encore
  et que ca empeche le Makefile de fonctionner

  - a reparer : le cas ou la width ou precision est une etoile
*/
