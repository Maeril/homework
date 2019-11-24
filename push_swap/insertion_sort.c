/*   By: myener <myener@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:13:23 by myener            #+#    #+#             */
/*   Updated: 2019/08/19 14:15:55 by myener           ###   ########.fr       */
/*   Updated: 2019/10/01 15:44:36 by myener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pile_print(t_pslist *curr)
{
	while (curr && curr->next)
	{
		printf("%d, ", curr->data);
		curr = curr->next;
	}
	printf("%d.\n", curr->data);
}

t_pslist *insertion_sort(t_pslist **h_a, int size, t_psflag *flag)
{
	int			min;
	int			pos;
	int			stk;
	t_pslist	*curr;
	t_pslist	*head_b;

	stk = 0;
	head_b = NULL;
	while (size > 2)
	{
		curr = (*h_a);
		min = (*h_a)->data;
		pos = 1;
		stk = 1;
		while (curr)
		{
			if (curr->data < min)
			{
				min = curr->data;
				stk = pos;
			}
			curr = curr->next;
			pos++;
		}
		if (stk <= ((size + 1) / 2))
			rot(h_a, stk - 1, flag);
		else
			rrot(h_a, (((size + 1) - stk)), flag);
		push(h_a, &head_b, flag);
		size--;
	}
	if ((*h_a)->data > (*h_a)->next->data)
		swap((*h_a), (*h_a)->next, flag);
	while (head_b)
		push(&head_b, h_a, flag);
	return ((*h_a));
}
