/* operations3.c
 *
 * Contains the reverse rotate both operation.
 */

#include "push_swap.h"

/* op_rrr: Reverse rotate both stacks downwards simultaneously */
void op_rrr(t_node **stack_a, t_node **stack_b)
{
	op_rra(stack_a);
	op_rrb(stack_b);
	write(1, "rrr\n", 4);
}
