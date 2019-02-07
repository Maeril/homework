/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specific_cases_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:14:03 by mpicard           #+#    #+#             */
/*   Updated: 2019/02/07 15:29:30 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			main(void)
{

// test du flag '+' avec des types non signes.	
	printf("+d = %+d\n", 5);
	printf("+u = %+u\n", 5);

	// avec o
	printf("+ho = %+ho\n", 5);
	printf("+hho = %+hho\n", 5);
	printf("+lo = %+lo\n", 5);
	printf("+llo = %+llo\n", 5);

	// avec u
	printf("+hu = %+hu\n", 5);
	printf("+hhu = %+hhu\n", 5);
	printf("+lu = %+lu\n", 5);
	printf("+llu = %+llu\n", 5);

	// avec x
	printf("+hx = %+hx\n", 5);
	printf("+hhx = %+hhx\n", 5);
	printf("+lx = %+lx\n", 5);
	printf("+llx = %+llx\n", 5);

	// avec X
	printf("+hX = %+hX\n", 5);
	printf("+hhX = %+hhX\n", 5);
	printf("+lX = %+lX\n", 5);
	printf("+llX = %+llX\n\n\n", 5);

// test du flag '0' mis avant un autre flag
	printf("05d = %05d\n", 5);
	printf("0-d = %0-5d\n", 5);
	printf("-0d = %-05d\n", 5);
	printf("0-d = %0-5d\n", 5);
	printf("0-+ # = %0-+ #5d\n", 5);

	// cas simple 
	printf("cas simple = ->%5d<-\n", 5);
	printf("avec un 0 avant 5 = ->%05d<-\n", 5);
	printf("avec un 0espace avant 5 = ->%0 5d<-\n", 5);
	printf(" 0espace- = ->%0 -5d<-\n", 5);


// avec diese
	printf("\n\n\ndiese simple : ->%#d<-\n", 5);
	printf("\n\n\ndiese simple : ->%#o<-\n", 5);
	printf("\n\n\ndiese simple : ->%#x<-\n", 5);
	printf("\n\n\ndiese simple : ->%#X<-\n", 5);
	printf("\n\n\ndiese simple : ->%#s<-\n", "aa");
	printf("\n\n\ndiese simple : ->%#c<-\n", 'a');
	printf("\n\n\ndiese simple : ->%#i<-\n", 5);
	printf("\n\n\ndiese simple : ->%#u<-\n", 5);

// precision
	printf("\n precision 0 et nb 0 = %.0d\n", 0);
	return (0);
}


/*

 - si le flag '+' est utilise avec un unsigned, on a un warning et le resultat 
 n'affiche pas le signe.
	unsigned = u, et hh, ll, l, h avec o,u,x,X

 - s'il y a a la fois les flags 0 et -, alors le flag - est totalement ignore. 

 - s'il y a un flag 0 ET une precision ET un type ENTIER (diouxX), alors le 0 est ignore. 
 
 - s'il y a un flag Espace ET un flag + ou -, alors l'espace est ignore. 

 - les DIESES # : 
 	- le diese est ignore quand il est utilise avec d, c et s, u et i. 
	- avec un o => le # met un 0 devant le resultat
	- avec un x => le # met un 0x devant le resultat
	- avec un X => le # met un 0X devant le resultat 
	
- WIDTH ne provoque JAMAIS de troncature du resultat. 
- la PRECISION provoque une troncature du resultat 

(continuer la precision);







 
 
 
 
 
 
*/



Ré