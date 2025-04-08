/* checker_main.c
 *
 * Implements the bonus checker program.
 * Reads instructions from standard input, executes them, and verifies the result.
 */

#include "push_swap.h"

/* is_sorted: Returns 1 if the stack is sorted in ascending order */
int is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* execute_instruction: Executes a single instruction on the stacks */
void execute_instruction(char *instr, t_node **stack_a, t_node **stack_b)
{
	if (!instr)
		return ;
	if (ft_strcmp(instr, "sa") == 0)
		op_sa(stack_a);
	else if (ft_strcmp(instr, "sb") == 0)
		op_sb(stack_b);
	else if (ft_strcmp(instr, "ss") == 0)
		op_ss(stack_a, stack_b);
	else if (ft_strcmp(instr, "pa") == 0)
		op_pa(stack_a, stack_b);
	else if (ft_strcmp(instr, "pb") == 0)
		op_pb(stack_a, stack_b);
	else if (ft_strcmp(instr, "ra") == 0)
		op_ra(stack_a);
	else if (ft_strcmp(instr, "rb") == 0)
		op_rb(stack_b);
	else if (ft_strcmp(instr, "rr") == 0)
		op_rr(stack_a, stack_b);
	else if (ft_strcmp(instr, "rra") == 0)
		op_rra(stack_a);
	else if (ft_strcmp(instr, "rrb") == 0)
		op_rrb(stack_b);
	else if (ft_strcmp(instr, "rrr") == 0)
		op_rrr(stack_a, stack_b);
	else
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

/* Main entry point for checker */
int main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	stack_b = NULL;
	while ((line = get_next_line(0)))
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		execute_instruction(line, &stack_a, &stack_b);
		free(line);
	}
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
