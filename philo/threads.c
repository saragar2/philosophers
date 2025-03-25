/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:31:06 by saragar2          #+#    #+#             */
/*   Updated: 2025/03/25 18:42:40 by saragar2         ###   ########.fr       */
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
	if (p->id % 2 == 0)
		usleep(1);
	pthread_mutex_lock(p->dead_lock);
	while (p->dead_lock != 1)
	{
		pthread_mutex_unlock(p->dead_lock);
		lonchazo(p->g, p);
		pintarlas(p->g, p);
		comer_techo(p->g->t_sleep, p->g, p);
		pthread_mutex_lock(p->dead_lock);
	}
	pthread_mutex_unlock(p->dead_lock);
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