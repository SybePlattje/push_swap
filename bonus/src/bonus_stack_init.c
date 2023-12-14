/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_stack_init.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: splattje <splattje@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/05 15:18:23 by splattje      #+#    #+#                 */
/*   Updated: 2023/12/11 12:58:04 by splattje      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static int	create_list(t_stack **a, long *numbers, int argc)
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{
		if (append_node(a, numbers[index]))
			return (1);
		index++;
	}
	free(numbers);
	return (0);
}

static int	error_overflow(long *nbr, int index, char **argv)
{
	*nbr = ft_atol(argv[index]);
	if (*nbr > INT_MAX)
	{
		write(2, OVERFLOW, ft_strlen(OVERFLOW));
		return (1);
	}
	return (0);
}

void	stack_init(t_stack **a, char **argv, int argc, int flag_argc_2)
{
	long	nbr;
	int		index;
	long	*numbers;

	index = 0;
	numbers = malloc(sizeof(long) * (argc - 1));
	if (numbers == NULL)
		error_free(a, argv, flag_argc_2, NULL);
	while (argv[index])
	{
		if (error_syntax(argv[index]))
			error_free(a, argv, flag_argc_2, numbers);
		if (error_overflow(&nbr, index, argv))
			error_free(a, argv, flag_argc_2, numbers);
		numbers[index++] = (int)nbr;
	}
	if (error_repetition(numbers, argc -1))
		error_free(a, argv, flag_argc_2, numbers);
	if (create_list(a, numbers, argc))
		error_free(a, argv, flag_argc_2, numbers);
	if (flag_argc_2)
		free_matrix(argv);
}
