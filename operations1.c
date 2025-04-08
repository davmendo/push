/* operations1.c
 *
 * Contains swap and push operations.
 */

#include "push_swap.h"

/* op_sa: Swap the first two elements of stack_a */
void op_sa(t_node **stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || !*stack_a || !((*stack_a)->next))
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write(1, "sa\n", 3);
}

/* op_sb: Swap the first two elements of stack_b */
void op_sb(t_node **stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || !*stack_b || !((*stack_b)->next))
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write(1, "sb\n", 3);
}

/* op_ss: Swap both stacks simultaneously */
void op_ss(t_node **stack_a, t_node **stack_b)
{
	op_sa(stack_a);
	op_sb(stack_b);
	write(1, "ss\n", 3);
}

/* op_pa: Push the top element of stack_b onto stack_a */
void op_pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_b || !*stack_b)
		return ;
	temp = *stack_b;
	*stack_b = temp->next;
	temp->next = *stack_a;
	*stack_a = temp;
	write(1, "pa\n", 3);
}

/* op_pb: Push the top element of stack_a onto stack_b */
void op_pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = *stack_a;
	*stack_a = temp->next;
	temp->next = *stack_b;
	*stack_b = temp;
	write(1, "pb\n", 3);
}
