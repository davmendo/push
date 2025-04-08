/* push_swap_main.c
 *
 * Contains the main entry point for push_swap and helper functions
 * for parsing arguments and building the initial stack.
 */

#include "push_swap.h"

/* Print error message and exit */
void error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

/* Create a new node with given value */
t_node *create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		error_exit();
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

/* Append a node to the end of the stack */
void add_back(t_node **stack, t_node *new_node)
{
	t_node	*tmp;

	if (!stack || !new_node)
		return ;
	if (!*stack)
		*stack = new_node;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

/* Parse command-line arguments (supports multiple arguments and space‐separated numbers) */
t_node *parse_arguments(int argc, char **argv)
{
	t_node	*stack;
	int		i;
	char	**nums;
	int		j;
	int		num;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		nums = ft_split(argv[i], ' ');
		if (!nums[0])
			error_exit();
		j = 0;
		while (nums[j])
		{
			if (!is_valid_number(nums[j]))
			{
				/* free_split is assumed to free the array */
				error_exit();
			}
			num = ft_atoi(nums[j]);
			add_back(&stack, create_node(num));
			j++;
		}
		/* free_split(nums) should free the split result */
		i++;
	}
	if (has_duplicates(stack))
		error_exit();
	return (stack);
}

/* Main entry point for push_swap */
int main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = parse_arguments(argc, argv);
	stack_b = NULL;
	/* Assign indices to nodes based on their order (used in radix sort) */
	assign_index(stack_a);
	if (list_length(stack_a) <= 5)
		sort_small(&stack_a, &stack_b);
	else
		sort_radix(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
