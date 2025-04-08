/* sorting_small.c
 *
 * Contains helper functions for sorting small stacks (3 to 5 elements)
 * with minimal moves.
 */

#include "push_swap.h"

/* sort_three: Sorts a stack of three elements optimally */
void sort_three(t_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->value;
	b = (*stack_a)->next->value;
	c = (*stack_a)->next->next->value;
	if (a > b && b < c && a < c)
		op_sa(stack_a);
	else if (a > b && b > c)
	{
		op_sa(stack_a);
		op_rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		op_ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		op_sa(stack_a);
		op_ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		op_rra(stack_a);
}

/* get_min_node: Returns the node with the smallest value in the stack */
static t_node *get_min_node(t_node *stack)
{
	t_node	*min;

	min = stack;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

/* sort_five: Sorts a stack of 4 or 5 elements by moving minimums to stack_b */
void sort_five(t_node **stack_a, t_node **stack_b)
{
	int		len;
	t_node	*min;

	len = list_length(*stack_a);
	while (len > 3)
	{
		min = get_min_node(*stack_a);
		while ((*stack_a)->value != min->value)
			op_ra(stack_a);
		op_pb(stack_a, stack_b);
		len--;
	}
	sort_three(stack_a);
	while (*stack_b)
		op_pa(stack_a, stack_b);
}
