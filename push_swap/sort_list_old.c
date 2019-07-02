/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_old.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 21:54:55 by myener            #+#    #+#             */
/*   Updated: 2019/06/28 22:57:36 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


typedef	struct
{
	int *Data;
	int nTaille;
	char Type;
}		Pile;


void rotate(char *instruc, Pile *A, int nStep)
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
		ft_strcat(instruc, (A->Type == 'a' ? "ra " : "rb "));
		i++;
	}
}

void rrotate(char *instruc, Pile *A, int nStep)
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
		ft_strcat(instruc, (A->Type == 'a' ? "tta " : "ttb "));
		i++;
	}
}

void push(char *instruc, Pile *A, Pile *B)
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
	ft_strcat(instruc, (B->Type == 'b' ? "pb " : "pa "));
}

void swap(char *instruc, Pile * A)
{
	int n0;
	char C[20];

	n0 = A->Data[0];
	A->Data[0] = A->Data[1];
	A->Data[1] = n0;
	ft_printf("s%c\n", A->Type);
	ft_strcat(instruc, (A->Type == 'a' ? "sa " : "sb "));
}

void Quick(char *instruc, Pile *A, Pile *B, int nLen, int Debut, int Fin)
{
	int	i;
	int	nR;
	int nPivot;

	if (Debut == Fin)
		return;
	rotate(instruc, A, Debut);
	if (Debut + 1 == Fin)
	{
		if (A->Data[0] > A->Data[1])
			swap(instruc, A);
		rrotate(instruc, A, Debut);
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
			push(instruc, A, B);
		else
		{
			rotate(instruc, A, 1);
			nR++;
		}
		i++;
	}
	rrotate(instruc, A, nR);
	nR = B->nTaille;
	while (B->nTaille > 0)
		push(instruc, B, A);
	rrotate(instruc, A, Debut);
	Quick(instruc, A, B, nLen, Debut, Debut + nR-1);
	Quick(instruc, A, B, nLen, Debut + nR, Fin);
}

void Bubble(char *instruc, Pile *A, Pile *B, int nLen)
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
				swap(instruc, A);
			push(instruc, A, B);
			i++;
		}
		i = 0;
		while (i < nLen - 1)
		{
			if (B->Data[0] < B->Data[1])
			{
				swap(instruc, B);
				Nb++;
			}
			push(instruc, B, A);
			i++;
		}
		push(instruc, B, A);
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
	int		i;
	int 	nLong;
	int 	nSeed;
	int		Nb;
	Pile	Pile_A;
	Pile	Pile_B;
	char	code;
	char	*instruc;
	char	Type[20];

	if (argc == 4)
	{
		nLong = atoi(argv[1]);
		nSeed = atoi(argv[2]);
		code = *argv[3];
	}
	else
	{
		nLong = 7;
		nSeed = 5;
		code = 'q';
	}
	if (code == 'q')
		ft_strcpy(Type, "Quick");
	else
		ft_strcpy(Type, "Bubble");
	instruc = (char *)malloc(1000 * 15);
	instruc[0] = '\0';
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
		Quick(instruc, &Pile_A, &Pile_B, nLong, 0, nLong - 1);
	else
		Bubble(instruc, &Pile_A, &Pile_B, nLong);
	printf("Type = %s\n", Type);
	i = 0;
	while (i < nLong)
	{
		printf("%d, ", Pile_A.Data[i]);
		i++;
	}
	printf("\n%s\n", instruc);
	Nb = 1;
	while (Nb > 0)
	{
		Nb = ps_cleaner(instruc, "pa pb ");
		Nb += ps_cleaner(instruc, "ra tta ");
		Nb += ps_cleaner(instruc, "tta ra ");
		Nb += ps_cleaner(instruc, "pb pa ");
		Nb += ps_cleaner(instruc, "sa sa ");
		Nb += ps_cleaner(instruc, "sb sb ");
		printf("Nb = %d\n", Nb);
	}
	replace(instruc);
	printf("\n%s", instruc);
	free(instruc);
	return (0);
}