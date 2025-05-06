/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:31:06 by saragar2          #+#    #+#             */
/*   Updated: 2025/04/16 16:37:13 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_dead(t_philo *p, size_t t_die)
{
	pthread_mutex_lock(&p->meal_lock);
	// if (get_time() - p->last_meal >= t_die
	// 	&& p->eating == 0) 
	// if (get_time() - p->last_meal >= t_die)
	printf("\n debug HOLA SOY %d, Y LA RESTA ENTRE GET_TIME Y LAST MEAL ES %ld\n", p->id, get_time() - p->last_meal);
	if (p->im_pakita == 0 && get_time() - p->last_meal >= t_die)
		return (pthread_mutex_unlock(&p->meal_lock), 1); //arreglala que está fea
	pthread_mutex_unlock(&p->meal_lock);
	return (0);
}

// Check if any philo died

int	check_if_dead(t_philo *p, t_general *g)
{
	int	i;

	i = -1;
	while (++i < g->num_philos)
	{
		pthread_mutex_lock(&p[0].dead_lock);
		printf("\ndebug OYE AQUI SOMOS EN TOTAL %d, Y YO SOY %d\n---------------------------------------------", g->num_philos, p[i].id);
		pthread_mutex_unlock(&p[0].dead_lock);
		if (philosopher_dead(&p[i], g->t_die) == 1)
		{
			print_status("dead", g, p);
			pthread_mutex_lock(&p[i].dead_lock); //p[0]??
			g->dead = 1;
			pthread_mutex_unlock(&p[i].dead_lock);
			return (1);
		}
	}
	return (0);
}

int	check_if_all_ate(t_philo *p, t_general *g)
{
	int	i;
	int	finished_eating;

	i = -1;
	finished_eating = 0;
	if (g->num_t_eat == -1)
		return (0);
	while (++i < g->num_philos)
	{
		pthread_mutex_lock(&p[i].meal_lock);
		if (p[i].eat_cont >= (size_t)g->num_t_eat)
			finished_eating++;
		pthread_mutex_unlock(&p[i].meal_lock);
	}
	if (finished_eating == g->num_philos)
	{
		pthread_mutex_lock(&p[0].dead_lock);
		g->dead = 1;
		pthread_mutex_unlock(&p[0].dead_lock);
		// printf("\ndebug PAKITA\n");
		return (1); //por que coño sales pakita (Salas)
	}
	return (0);
}

void	*busybody_pakita(void *philovoid)
{
	t_philo	*p;

	p = (t_philo *)philovoid;
	while (1)
	{
		if (check_if_dead(p->g->philos, p->g) == 1 || check_if_all_ate(p, p->g) == 1)
		{
			break ;
		}
	}
	limpiarlas(p->g);
	exit(1); //apaño casero que hay que re apañar
	return (philovoid);
}

void	*routine(void *philovoid)
{
	t_philo	*p;
	
	p = (t_philo *)philovoid;
	if (p->id % 2 == 0)
		my_usleep(1);
	pthread_mutex_lock(&p->dead_lock);
	
	while (1)
	{
		pthread_mutex_unlock(&p->dead_lock);
		lonchazo(p->g, p);
		comer_techo(p->g->t_sleep, p->g, p);
		pintarlas(p->g, p);
		pthread_mutex_lock(&p->dead_lock);
	}
	pthread_mutex_unlock(&p->dead_lock);
	return (philovoid);
}

void	create_philos(t_general *g)
{
	int i;
	t_philo	pakita;

    i = -1;
    g->stime = get_time();
	pthread_mutex_init(&pakita.dead_lock, NULL);
	pthread_mutex_init(&pakita.meal_lock, NULL);
	pthread_mutex_init(&pakita.write_lock, NULL);
	pakita.g = g;
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
}
