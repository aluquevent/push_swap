/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:54:38 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/04 19:49:41 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/ft_printf.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

# include "list.h"
# include "operations.h"
# include "sorting.h"

int		init_stacks(t_ring **stack_a, t_ring **stack_b, int *nums, size_t elements);
int		*process_numbers(char **data, size_t *elements);

#endif
