/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_on_input.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: splattje <splattje@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 15:23:28 by splattje      #+#    #+#                 */
/*   Updated: 2023/12/11 12:47:47 by splattje      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	handle_actions(char *action, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(action, "pa", 2))
		push(a, b);
	else if (!ft_strncmp(action, "pb", 2))
		push(b, a);
	else if (!ft_strncmp(action, "ra", 2))
		rotate(a, NULL, "ra");
	else if (!ft_strncmp(action, "rb", 2))
		rotate(b, NULL, "rb");
	else if (!ft_strncmp(action, "rr", 2) && ft_strlen(action) == 2)
		rotate(a, b, "rr");
	else if (!ft_strncmp(action, "rra", 3))
		reverse_rotate(a, NULL, "rra");
	else if (!ft_strncmp(action, "rrb", 3))
		reverse_rotate(b, NULL, "rrb");
	else if (!ft_strncmp(action, "rrr", 3))
		reverse_rotate(a, b, "rrr");
	else if (!ft_strncmp(action, "sa", 2))
		swap(a, 0);
	else if (!ft_strncmp(action, "sb", 2))
		swap(b, 0);
}

void	check_on_input(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str || !ft_strncmp(str, "exit", 4))
			break ;
		handle_actions(str, a, b);
		free(str);
	}
	free(str);
	if (!stack_sorted(*a) || stack_len(*b) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
