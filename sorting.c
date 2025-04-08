/* sorting.c
 *
 * Contains sorting algorithms for push_swap.
 * Implements assignment of indices and the radix sort for large inputs.
 */

#include "push_swap.h"

/* assign_index: Assigns an index to each node based on its sorted order */
void assign_index(t_node *stack)
{
	t_node	*a;
	t_node	*b;
	int		count;

	a = stack;
	while (a)
	{
		count = 0;
		b = stack;
		while (b)
		{
			if (a->value > b->value)
				count++;
			b = b->next;
		}
		a->index = count;
		a = a->next;
	}
}

/* sort_small: Sort small stacks (2 to 5 elements) using optimized routines */
void sort_small(t_node **stack_a, t_node **stack_b)
{
	int	len;

	len = list_length(*stack_a);
	if (len == 2 && (*stack_a)->value > (*stack_a)->next->value)
		op_sa(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len <= 5)
		sort_five(stack_a, stack_b);
}

/* Helper: get_max_bits returns the number of bits needed for the largest index */
static int get_max_bits(t_node *stack)
{
	int	max;
	int	bits;

	max = list_length(stack) - 1;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

/* sort_radix: Uses a binary radix sort (based on node indices) for larger inputs */
void sort_radix(t_node **stack_a, t_node **stack_b)
{
	int		len;
	int		max_bits;
	int		i;
	int		j;

	len = list_length(*stack_a);
	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < len)
		{
			if (((*stack_a)->index >> i) & 1)
				op_ra(stack_a);
			else
				op_pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			op_pa(stack_a, stack_b);
		i++;
	}
}

