/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 16:56:58 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/24 22:34:31 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		dispatcher(va_list ap, t_data *data)
{
	if (data->type->d || data->type->i|| data->type->o || data->type->x
		|| data->type->big_x)
		data->spec->integer = 1;
	if (data->type->d || data->type->i)
		typeis_int(ap, data);
	else if (data->type->c)
		typeis_char(ap, data);
	else if (data->type->s)
		typeis_str(ap, data);
	else if (data->type->o)
		typeis_octal(ap, data);
	else if (data->type->x)
		typeis_hexl(ap, data);
	else if (data->type->big_x)
		typeis_hexu(ap, data);
	else if (data->type->p)
		typeis_ptr(ap, data);
	else if (data->type->u)
		typeis_unsign(ap, data);
	else if (data->tool->perc)
		typeis_perc(ap, data);

	/*_____________________ BORDEL A TRIER _____________________*/

	/*if (data->flag->space && (data->type->d || data->type->i))
		ft_putchar(' '); // je  pense qu'il faudra enlever cette condition et ligne
	if (data->flag->plus && !data->tool->unsign)
		Je suis en train de tester le fait d'enlever la ligne en dessous et je pense que ca va aussi etre necessaire->->-> :) 
		ft_putchar('+');
	if (data->flag->zero)
		ft_putnbr('0'); --> ML : je pense qu'il faut supprimer ces lignes
	if (data->flag->minus && data->lngt->width) // j'ai mis la ligne en sourdine car je pense quelle est pas finie ^^ 
	data->spec->car = (data->spec->car && data->type->c); // est ce qu'on peut reduire cette ligne ? data->car = data->c ?
	data->spec->str = (data->spec->str && (data->type->s || data->type->p)); je met en sourdine en attendant (voir ligne ci dessus)

	data->spec->unint = (data->spec->unint && data->type->u);

	if (data->spec->car)
		typeis_char(ap, data);
	if (data->type->d || data->type->i)
	{
		// data->spec->signcar = (data->spec->signcar && data->size->hh);
		// data->spec->sh = (data->spec->sh && data->size->h);
		// data->spec->lg = (data->spec->lg && data->size->l);
		// data->spec->lglg = (data->spec->lglg && data->size->ll);
	}
	if (data->type->o || data->type->u || data->type->x || data->type->big_x)
	{
		data->spec->unsigncar = (data->spec->unsigncar && data->size->hh);
		data->spec->unsignsh = (data->spec->unsignsh && data->size->h);
		data->spec->unsignlglg = (data->spec->unsignlglg && data->size->ll);
		data->spec->unsignlg = (data->spec->unsignlg && data->size->l);
	}
	if (data->spec->integer || data->spec->sh || data->spec->lg || data->spec->lglg)
		typeis_int(ap, data->spec);

	if (data->spec->unsigncar || data->spec->unsignsh || data->spec->unsignlg
		|| data->spec->unsignlglg || data->spec->unint)
		typeis_unsign(ap, data->tool, data->spec);*/
}