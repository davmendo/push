#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stddef.h>
# include "libft/libft.h"

/* Structure for stack nodes */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* Functions from push_swap_main.c */
void	error_exit(void);
t_node	*create_node(int value);
void	add_back(t_node **stack, t_node *new_node);
t_node	*parse_arguments(int argc, char **argv);

/* Functions from utils.c */
int		list_length(t_node *stack);
void	free_stack(t_node *stack);
int		has_duplicates(t_node *stack);
int		is_valid_number(char *str);

/* Functions from sorting.c */
void	assign_index(t_node *stack);
void	sort_radix(t_node **stack_a, t_node **stack_b);
void	sort_small(t_node **stack_a, t_node **stack_b);

/* Functions from sorting_small.c */
void	sort_three(t_node **stack_a);
void	sort_five(t_node **stack_a, t_node **stack_b);

/* Operation functions (implemented in operations1,2,3.c) */
void	op_sa(t_node **stack_a);
void	op_sb(t_node **stack_b);
void	op_ss(t_node **stack_a, t_node **stack_b);
void	op_pa(t_node **stack_a, t_node **stack_b);
void	op_pb(t_node **stack_a, t_node **stack_b);
void	op_ra(t_node **stack_a);
void	op_rb(t_node **stack_b);
void	op_rr(t_node **stack_a, t_node **stack_b);
void	op_rra(t_node **stack_a);
void	op_rrb(t_node **stack_b);
void	op_rrr(t_node **stack_a, t_node **stack_b);
#endif
