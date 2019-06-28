/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 21:54:55 by myener            #+#    #+#             */
/*   Updated: 2019/06/28 22:16:20 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *Commandes;

typedef	struct
{
	int *Data;
	int nTaille;
	char Type;
}		Pile;


void rotate(Pile *A, int nStep)
{
	int i;
	int	j;
	int n0;
	char C[20];

	i = 0;
	while (i < nStep)
	{
		n0 = A->Data[0];
		j = 0;
		while (j < A->nTaille - 1)
		{
			A->Data[j] = A->Data[j + 1];
			j++;
		}
		A->Data[A->nTaille - 1] = n0;
		ft_printf("r%c\n", A->Type);
		ft_strcat(Commandes, (A->Type == 'a' ? "ra " : "rb "));
		i++;
	}
}

void rrotate(Pile *A, int nStep)
{
	int	i;
	int	j;
	int n0;
	char C[20];

	i = 0;
	while (i < nStep)
	{
		n0 = A->Data[A->nTaille - 1];
		j = A->nTaille - 1;
		while (j > 0)
		{
			A->Data[j] = A->Data[j-1];
			j--;
		}
		A->Data[0] = n0;
		ft_printf("rr%c\n", A->Type);
		ft_strcat(Commandes, (A->Type == 'a' ? "tta " : "ttb "));
		i++;
	}
}

void push(Pile *A, Pile *B)
{
	int		i;
	char	C[20];

	if (A->nTaille == 0)
		return ;
	i = B->nTaille;
	while (i > 0)
	{
		B->Data[i] = B->Data[i - 1];
		i--;
	}
	B->Data[0] = A->Data[0];
	B->nTaille++;
	i = 0;
	while (i < A->nTaille - 1)
	{
		A->Data[i] = A->Data[i + 1];
		i++;
	}
	A->Data[A->nTaille-1] = -1;
	A->nTaille--;
	ft_printf("p%c\n", B->Type);
	ft_strcat(Commandes, (B->Type == 'b' ? "pb " : "pa "));
}

void swap(Pile * A)
{
	int n0;
	char C[20];
	n0 = A->Data[0];
	A->Data[0] = A->Data[1];
	A->Data[1] = n0;
	ft_printf("s%c\n", A->Type);
	ft_strcat(Commandes, (A->Type == 'a' ? "sa " : "sb "));
}

void Quick(Pile *A, Pile *B, int nLen, int Debut, int Fin)
{
	int	i;
	int	nR;
	int nPivot;

	if (Debut == Fin)
		return;
	rotate(A, Debut);
	if (Debut + 1 == Fin)
	{
		if (A->Data[0] > A->Data[1])
			swap(A);
		rrotate(A, Debut);
		return;
	}
	nPivot = 0;
	i = 0;
	while (i <= Fin - Debut)
	{
		nPivot += A->Data[i];
		i++;
	}
	nPivot = (int)(nPivot / (Fin - Debut + 1));
	nR = 0;
	i = 0;
	while (i <= Fin - Debut)
	{
		if (A->Data[0] < nPivot)
			push(A, B);
		else
		{
			rotate(A, 1);
			nR++;
		}
		i++;
	}
	rrotate(A, nR);
	nR = B->nTaille;
	while (B->nTaille > 0)
		push(B, A);
	rrotate(A, Debut);
	Quick(A, B, nLen, Debut, Debut + nR-1);
	Quick(A, B, nLen, Debut + nR, Fin);
}

void Bubble(Pile *A, Pile *B, int nLen)
{
	int i;
	int Nb;

	Nb = 1;
	while (Nb > 0)
	{
		Nb = 0;
		i = 0;
		while (i < nLen - 1)
		{
			if (A->Data[0] > A->Data[1])
			{
				swap(A);
				Nb++;
			}
			push(A, B);
			i++;
		}
		i = 0;
		while (i < nLen - 1)
		{
			if (B->Data[0] < B->Data[1])
			{
				swap(B);
				Nb++;
			}
			push(B, A);
			i++;
		}
		push(B, A);
	}
}

int ps_cleaner(char *src, const char *rem)
{
	char *cur;
	int r = 0;
	while ((cur = ft_strstr(src, rem)))
	{
		ft_strcpy(cur, (cur + ft_strlen(rem)));
		r++;
	}
	return (r);
}

void replace(char *c)
{
	while (*c)
	{
		if (*c == 't')
			*c = 'r';
		c++;
	}
}
int main(int argc, char** argv)
{
	int	i;
	int nLong, nSeed, Nb;
	Pile Pile_A, Pile_B;
	char code;

	char Type[20];
	if (argc == 4)
	{
		nLong = atoi(argv[1]);
		nSeed = atoi(argv[2]);
		code = *argv[3];
	}
	else
	{
	//	return 0;
		nLong = 7;
		nSeed = 5;
		code = 'q';
	}
	if (code == 'q')
		ft_strcpy(Type, "Quick");
	else
		ft_strcpy(Type, "Bubble");

	Commandes = (char *)malloc(1000 * 15);
	Commandes[0] = '\0';
	printf("\n%d\n", nLong);
	Pile_A.Data = (int *)malloc(nLong * sizeof(int));
	Pile_A.nTaille = nLong;
	Pile_A.Type = 'a';
	Pile_B.Data = (int *)malloc(nLong * sizeof(int));
	Pile_B.nTaille = 0;
	Pile_B.Type = 'b';
	srand(nSeed);
	i = 0;
	while (i < nLong)
	{
		Pile_A.Data[i] = (int)(rand() % 1000);
		i++;
	}
	i = 0;
	while (i < nLong)
	{
		printf("%d, ", Pile_A.Data[i]);
		i++;
	}
	printf("\n");
	if(code == 'q')
		Quick(&Pile_A, &Pile_B, nLong, 0, nLong - 1);
	else
		Bubble(&Pile_A, &Pile_B, nLong);
	printf("Type = %s\n", Type);
	i = 0;
	while (i < nLong)
	{
		printf("%d, ", Pile_A.Data[i]);
		i++;
	}
	printf("\n%s\n", Commandes);
	Nb = 1;
	while (Nb > 0)
	{
		Nb = ps_cleaner(Commandes, "pa pb ");
		Nb += ps_cleaner(Commandes, "ra tta ");
		Nb += ps_cleaner(Commandes, "tta ra ");
		Nb += ps_cleaner(Commandes, "pb pa ");
		Nb += ps_cleaner(Commandes, "sa sa ");
		Nb += ps_cleaner(Commandes, "sb sb ");
		printf("Nb = %d\n", Nb);
	}
	replace(Commandes);
	printf("\n%s", Commandes);
	free(Commandes);
	return (0);
}