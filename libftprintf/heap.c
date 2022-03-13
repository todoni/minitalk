/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:17:56 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 21:18:02 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "heap.h"

static void	swap(t_fp *p, t_fp *c)
{
	t_fp	tmp;

	tmp = *p;
	*p = *c;
	*c = tmp;
}

static t_fp	*make_root(void)
{
	t_fp	*root;

	root = (t_fp *)malloc(sizeof(t_fp));
	if (root == 0)
		return (0);
	return (root);
}

void	heap_initialize(t_heap *heap)
{
	int	i;

	i = 0;
	while (i < MAX_SIZE)
	{
		heap->func[i].print = 0;
		heap->func[i].print_space = 0;
		heap->func[i].print_padding = 0;
		heap->func[i].print_string = 0;
		heap->func[i].print_plus = 0;
		heap->func[i].print_minus = 0;
		heap->func[i].print_precision = 0;
		heap->func[i].print_char = 0;
		heap->func[i].priority = 0;
		i++;
	}
	heap->size = 0;
}

void	heap_insert(t_heap *heap, t_fp function)
{
	int	index;

	heap->size += 1;
	index = heap->size;
	while (index != 1 && function.priority < heap->func[index / 2].priority)
	{
		heap->func[index] = heap->func[index / 2];
		index /= 2;
	}
	heap->func[index] = function;
}

t_fp	*heap_delete(t_heap *heap)
{
	t_fp	*root;
	int		parent;
	int		child;

	root = 0;
	parent = 1;
	root = make_root();
	if (heap->size == 0 || !root)
		return (root);
	*root = heap->func[1];
	heap->func[1] = heap->func[heap->size--];
	while (1)
	{
		child = parent * 2;
		if ((child + 1 <= heap->size) && \
				(heap->func[child].priority > heap->func[child + 1].priority))
			child++;
		if ((child > heap->size) || \
				(heap->func[child].priority > heap->func[parent].priority))
			break ;
		swap(&heap->func[parent], &heap->func[child]);
		parent = child;
	}
	heap->func[heap->size + 1].usage = NOT_USED;
	return (root);
}
