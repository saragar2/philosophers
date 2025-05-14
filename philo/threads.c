/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:31:06 by saragar2          #+#    #+#             */
/*   Updated: 2025/05/14 21:49:34 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_if_dead(t_philo *p, t_general *g)
{
	int	i;

	i = -1;
	while (++i < g->num_philos)
	{
		pthread_mutex_lock(p->meal_lock);
		if (get_time() - p->last_meal >= g->t_die)
		{
			pthread_mutex_unlock(p->meal_lock);
			print_status("dead", g, &p[i]);
			pthread_mutex_lock(p[0].dead_lock);
			g->dead = 1;
			pthread_mutex_unlock(p[0].dead_lock);
			return (1);
		}
		pthread_mutex_unlock(p->meal_lock);
	}
	return (0);
}

int	check_if_all_ate(t_philo *p, t_general *g)
{
	int	i;
	int	finished_eating;

	i = -1;
	(void)p;
	finished_eating = 0;
	if (g->num_t_eat == -1)
		return (0);
	while (++i < g->num_philos)
	{
		pthread_mutex_lock(g->philos[i].meal_lock);
		if (g->philos[i].eat_cont >= (size_t)g->num_t_eat)
			finished_eating++;
		pthread_mutex_unlock(g->philos[i].meal_lock);
	}
	if (finished_eating == g->num_philos)
	{
		pthread_mutex_lock(g->philos[0].dead_lock);
		g->dead = 1;
		pthread_mutex_unlock(g->philos[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*busybody_pakita(void *philovoid)
{
	t_philo	*p;

	p = (t_philo *)philovoid;
	while (1)
	{
		if (check_if_dead(p->g->philos, p->g) == 1
			|| check_if_all_ate(p, p->g) == 1)
			break ;
	}
	return (philovoid);
}

void	*routine(void *philovoid)
{
	t_philo	*p;

	p = (t_philo *)philovoid;
	if (p->id % 2 == 0)
		my_usleep(1);
	while (1)
	{
		subroutine(p);
		pthread_mutex_lock(p->dead_lock);
		if (p->g->dead == 1)
		{
			pthread_mutex_unlock(p->dead_lock);
			break ;
		}
		pthread_mutex_unlock(p->dead_lock);
	}
	return (philovoid);
}

void	create_philos(t_general *g)
{
	int		i;
	t_philo	pakita;

	i = -1;
	g->stime = get_time();
	pakita.g = g;
	pakita.dead_lock = g->philos[0].dead_lock;
	pakita.meal_lock = g->philos[0].meal_lock;
	pakita.write_lock = g->philos[0].write_lock;
	pakita.id = -1;
	pakita.im_pakita = 1;
	pthread_create(&pakita.pakita_tid, NULL, busybody_pakita, &pakita);
	while (++i < g->num_philos)
	{
		pthread_create(&g->philos[i].tid, NULL, routine, &g->philos[i]);
		my_usleep(1);
	}
	i = -1;
	while (++i < g->num_philos)
		pthread_join(g->philos[i].tid, NULL);
	pthread_join(pakita.pakita_tid, NULL);
	pthread_mutex_destroy(pakita.dead_lock);
	pthread_mutex_destroy(pakita.meal_lock);
	pthread_mutex_destroy(pakita.write_lock);
}
