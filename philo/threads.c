/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:31:06 by saragar2          #+#    #+#             */
/*   Updated: 2025/02/27 20:03:56 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	busybody_pakita()
{
    
}

void	routine()
{
	
}

void	create_philos(t_general *g)
{
	int i;

    i = -1;
    g->stime = get_time();
	while (++i < g->num_philos)
        pthread_create(g->tid[i], NULL, &routine, ); // -------falta el arg de la rutina
    while (++i < g->num_philos)
		pthread_join(g->tid[i], NULL);
}