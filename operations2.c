/* operations2.c
 *
 * Contains rotate and reverse rotate operations (parte 1).
 */

#include "push_swap.h"

/* op_ra: Rotate stack_a upwards */
void op_ra(t_node **stack_a)
{
	t_node	*first;
	t_node	*last;

	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	first = *stack_a;
	*stack_a = first->next;
	first->next = NULL;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}

/* op_rb: Rotate stack_b upwards */
void op_rb(t_node **stack_b)
{
	t_node	*first;
	t_node	*last;

	if (!stack_b || !*stack_b || !((*stack_b)->next))
		return ;
	first = *stack_b;
	*stack_b = first->next;
	first->next = NULL;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "rb\n", 3);
}

/* op_rr: Rotate both stacks upwards simultaneously */
void op_rr(t_node **stack_a, t_node **stack_b)
{
	op_ra(stack_a);
	op_rb(stack_b);
	write(1, "rr\n", 3);
}

/* op_rra: Reverse rotate stack_a downwards */
void op_rra(t_node **stack_a)
{
	t_node	*prev;
	t_node	*last;

	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	prev = NULL;
	last = *stack_a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	write(1, "rra\n", 4);
}

/* op_rrb: Reverse rotate stack_b downwards */
void op_rrb(t_node **stack_b)
{
	t_node	*prev;
	t_node	*last;

	if (!stack_b || !*stack_b || !((*stack_b)->next))
		return ;
	prev = NULL;
	last = *stack_b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	write(1, "rrb\n", 4);
}
