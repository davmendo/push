/* utils.c
 *
 * Contains utility functions for linked list manipulation and validation.
 */

#include "push_swap.h"

/* list_length: Returns the number of nodes in the stack */
int list_length(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

/* free_stack: Frees all nodes in the stack */
void free_stack(t_node *stack)
{
	t_node	*temp;

	while (stack)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/* has_duplicates: Checks for duplicate values in the stack */
int has_duplicates(t_node *stack)
{
	t_node	*a;
	t_node	*b;

	a = stack;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->value == b->value)
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}

/* is_valid_number: Validates if the string is a proper integer representation */
int is_valid_number(char *str)
{
	int	i = 0;

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
