/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marielise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:50:23 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/06 16:53:55 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpicard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:58:15 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/06 10:52:41 by mpicard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	char				c;
	char				*str;
	int					j;
	int					index;
	long				l;
	long long 			ll;
	va_list				ap;
	unsigned short		u;
	unsigned long		ul;
	unsigned long long	ull;
	unsigned char		uc;
	short				sh;
	signed char			sc;

	index = 0;
	va_start(ap, format);
	while (format[index] != '\0')
	{
		if (format[index] != '%')
			ft_putchar(format[index]);
		if (format[index] == '%' && format[index+1] == 'c')

		{
			c = va_arg(ap, int);
			ft_putchar(c);
			index++;
		}
		if (format[index] == '%' && format[index+1] == 's')
		{
			str = va_arg(ap, char *);
			ft_putstr(str);
			index++;
		}
		if (format[index] == '%' && (format[index+1] == 'o'))
		{
			j = va_arg(ap, int);
			ft_putnbr(conv_to_octal(j));
			index++;
		}
		if (format[index] == '%' && (format[index+1] == 'd' ||
					format[index+1] == 'i' || format[index+1] == 'u'))
		{
			j = va_arg(ap, int);
			ft_putnbr(j);
			index++;
		}
		if (format[index] == '%' && format[index+1] == 'p')
		{
			j = va_arg(ap, long int);
			conv_adress(j);
			index++;
		}
		if (format[index] == '%' && format[index+1] == 'x')
		{
			j = va_arg(ap, int);
			conv_to_hexa(j);
			index++;
		}
		if (format[index] == '%' && format[index+1] == 'X')
		{
			j = va_arg(ap, int);
			conv_to_maj_hexa(j);
			index++;
		}
		if (format[index] == '%' && format[index+1] == 'l' &&
				(format[index+2] == 'd' || format[index+2] == 'i'))
		{
			l = va_arg(ap, long);
			ft_putnbr((int)l);
			index = index + 2;
		}
		if (format[index] == '%' && format[index+1] == 'l' &&
				(format[index+2] == 'l') && (format[index+3] == 'd' ||
					format[index+3] == 'i'))
		{
			ll = va_arg(ap, long long);
			ft_putnbr((int)ll);
			index = index + 3;
		}
		if (format[index] == '%' && format[index+1] == 'h' &&
				(format[index+2] == 'o' || format[index+2] == 'u' ||
				 format[index+2] == 'x' || format[index+2] =='X'))
		{
			u = va_arg(ap, unsigned short);
			ft_putnbr((int)u);
			index = index + 2;
		}
		if (format[index] == '%' && format[index+1] == 'l' &&
				(format[index+2] == 'o' || format[index+2] == 'u' ||
				 format[index+2] == 'x' || format[index+2] =='X'))
		{
			ul = va_arg(ap, unsigned long);
			ft_putnbr((int)ul);
			index = index+2;
		}
		if (format[index] == '%' && format[index+1] == 'l' &&
				format[index+2] == 'l' && (format[index+3] == 'o'
					|| format[index+2] == 'u' || format[index+2] == 'x' ||
					format[index+2] =='X'))
		{
			ull = va_arg(ap, unsigned long long);
			ft_putnbr((int)ull);
			index = index + 3;
		}
		if (format[index] == '%' && format[index+1] == 'h' &&
				format[index+2] == 'h' && (format[index+3] == 'o' ||
					format[index+3] == 'u' || format[index+3] == 'x' ||
					format[index+3] == 'X'))
		{
			uc = va_arg(ap, unsigned char);
			ft_putnbr((int)uc);
			index = index + 3;
		}
		if (format[index] == '%' && format[index+1] == 'h' && (format[index+2]
					== 'd' || format[index+2] == 'i'))
		{
			sh = va_arg(ap, short);
			ft_putnbr((int)sh);
			index = index + 3;
		}
		if (format[index] == '%' && format[index+1] == 'h' && format[index+2]
			   == 'h' && (format[index+3] == 'd' || format[index+3] == 'i'))
		{
			sc = va_arg(ap, unsigned char);
			ft_putnbr((int)sc);
			index = index + 3;
		}
		if (format[index] == '%' && format[index+1] == '%')
		{
			ft_putchar('%');
			index++;
		}
		index++;
	}
	va_end(ap);
	return (1);
}

int		main(void)
{
	char				caractere;
	char 				*string;
	char 				*pointeur;
	int					i;
	long				l;
	long long			ll;
	unsigned short	 	us;
	unsigned long		ul;
	unsigned long long 	ull;
	short				sh;
	signed char			sich;
	unsigned char		unch;

	caractere = 'a';
	string = "salut";
	pointeur = &caractere;

	printf("caractere = %c\n", caractere);
	ft_printf("caractere = %c\n", caractere);

	printf("string = %s\n", string);
	ft_printf("string = %s\n", string);

	printf("pointeur = %p\n", pointeur);
	ft_printf("pointeur = %p\n", pointeur);

	i = 42;
	printf("i = %x\n", i);
	ft_printf("i = %x\n", i);

	printf("i = %X\n", i);
	ft_printf("i = %X\n", i);

//1 l di
	l = 10;
	printf("l = %ld\n", l);
	ft_printf("l = %ld\n", l);

//2 ll di
	ll = 450;
	printf("ll = %lld\n", ll);
	ft_printf("ll = %lld\n", ll);

//3 h ouxX
	us = 22;
	printf("us = %hu\n", us);
	ft_printf("us = %hu\n", us);
//4 l ouxX
	ul = 31;
	printf("ul = %lu\n", ul);
	ft_printf("ul = %lu\n", ul);

//5 ll ouxX
	ull = 41;
	printf("ull = %llu\n", ull);
	ft_printf("ull = %llu\n", ull);

//6 h di
	sh = 13;
	printf("sh = %hd\n", sh);
	ft_printf("sh = %hd\n", sh);

//7 hh di
	sich = 68;
	printf("sich = %hhd\n", sich);
	ft_printf("sich = %hhd\n", sich);

//8 hh ouxX
	unch = 61;
	printf("unch = %hhu\n", unch);
	ft_printf("unch = %hhu\n", unch);

	caractere = '%';
	printf("caractere  = %%\n");
	ft_printf("caractere  = %%\n");

	return (0);
}