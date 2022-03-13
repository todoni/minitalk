/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:18:10 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 21:18:12 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAP_H
# define HEAP_H

# include <stdlib.h>
# include "functions.h"
# define MAX_SIZE 11

typedef struct s_heap
{
	t_fp	func[MAX_SIZE + 1];
	int		size;
}	t_heap;

void	heap_initialize(t_heap *heap);
void	heap_insert(t_heap *heap, t_fp function);
t_fp	*heap_delete(t_heap *heap);

#endif
