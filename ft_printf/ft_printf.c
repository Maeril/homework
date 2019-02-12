/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:52:42 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/12 15:05:39 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
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

int			put_text(va_list ap, const char *format)
{
	int		i;
	char	*instruc;
	t_data	data;
	int		nb;

	i = 0;
	nb = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			nb++;
		}
		else if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				ft_putchar('%');
				nb++;
			}
			else
			{
				instruc = take_instructions(format, i);
				data = parse_instructions(instruc, data);
				data = finalize_instructions(data);
				data = find_arg_type(ap, data);
				data = clean_data(data);
				i++;
			}
			i++;
		}
		i++;
	}
	return (nb);
}


int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		nb;

	va_start(ap, format);
	nb = put_text(ap, format);
	va_end(ap);
	return (nb);
}



int			main(void)
{
	ft_printf("un, deux,%d", 3);
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

  - je vais enlever de la fonction PUT TEXT l'argent ap parce que je ne l'utilise pas encore
  et que ca empeche le Makefile de fonctionner

  - a reparer : le cas ou la width ou precision est une etoile
*/
