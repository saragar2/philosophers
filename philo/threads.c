/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:31:06 by saragar2          #+#    #+#             */
/*   Updated: 2025/03/19 18:43:35 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	busybody_pakita()
{
    
}

void	routine(void *philovoid)
{
	t_philo	*p;
	
	p = (t_philo *)philovoid;
}

void	create_philos(t_general *g)
{
	int i;

    i = -1;
    g->stime = get_time();
	while (++i < g->num_philos)
	{
        pthread_create(g->tid[i], NULL, &routine, &g->philos[i]);
		usleep(1);
	}
    while (++i < g->num_philos)
		pthread_join(g->tid[i], NULL);
}