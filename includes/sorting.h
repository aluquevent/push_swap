/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluque-v <aluque-v@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:39:29 by aluque-v          #+#    #+#             */
/*   Updated: 2025/05/09 15:39:50 by aluque-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "list.h"
# include "operations.h"

// Validation
int		*validate_args(int argc, char **argv, size_t *elements);

// Sorting algorithms
void	sort_two(t_ring *a);
void	sort_three(t_ring *a);
void	sort_stack(t_ring *a, t_ring *b);
void	turkish_sort(t_ring *a, t_ring *b);

// Auxiliar sorting functions 
void	rotate_to_pos(t_ring *a, int pos);
void	final_rotation(t_ring *a);
void	optimized_push_initial(t_ring *a, t_ring *b);
void	optimize_small_sort(t_ring *a, t_ring *b);
int		find_target_position(t_ring *a, int value);

#endif
