/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-oirg <bel-oirg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 01:37:28 by bel-oirg          #+#    #+#             */
/*   Updated: 2024/01/10 10:32:10 by bel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dataclear(t_data **hold)
{
	t_data	*tmp;
	t_data	*ptr;

	if (!hold || !*hold)
		return ;
	tmp = *hold;
	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		free(ptr->data);
		free(ptr);
	}
	*hold = NULL;
}

void	*my_malloc(size_t size, int mode)
{
	static t_data	*head;
	t_data			*node;
	void			*data;

	if (mode == 1)
	{
		data = malloc(size);
		if (!data)
			return (dataclear(&head), exit(1), NULL);
		node = malloc(sizeof(t_data));
		if (!node)
			return (dataclear(&head), exit(1), NULL);
		node->data = data;
		node->next = NULL;
		(head) && (node->next = head);
		head = node;
		return (data);
	}
	if (!mode)
		return (dataclear(&head), exit(1), NULL);
	return (dataclear(&head), exit(0), NULL);
}
