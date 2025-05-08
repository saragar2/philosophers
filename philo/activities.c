/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:21:51 by saragar2          #+#    #+#             */
/*   Updated: 2025/05/08 16:32:47 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *s, t_general *g, t_philo *p)
{
	size_t	t;
	
	pthread_mutex_lock(&p->write_lock);
	t = get_time() - g->stime;
	if (f_strcmp(s, "fork") == 0)
		printf("%s[%lu] %d has taken a fork\n", PINK, t, p->id);
	else if (f_strcmp(s, "eat") == 0)
		printf("%s[%lu] %d is eating\n", BLUE, t, p->id);
	else if (f_strcmp(s, "sleep") == 0)
		printf("%s[%lu] %d is sleeping\n", GREEN, t, p->id);
	else if (f_strcmp(s, "think") == 0)
		printf("%s[%lu] %d is thinking\n", YELLOW, t, p->id);
	else if (f_strcmp(s, "dead") == 0)
		printf("%s[%lu] %d died\n", PURPLE, t, p->id);
	pthread_mutex_unlock(&p->write_lock);
}

void	comer_techo(size_t milis, t_general *g, t_philo *p)
{
	size_t	start;

	(void)milis;
	print_status("sleep", g, p);
	start = get_time();
	(void)start;
	// while ((get_time() - start) < milis)
		// my_usleep(500); //por que 500????
	// my_usleep(g->t_sleep);
	my_usleep(milis);
}

int	lonchazo(t_general *g, t_philo *p)
{
	pthread_mutex_lock(p->right);
	// if (g->dead == 1)
		// return (pthread_mutex_unlock(p->right));
	print_status("fork", g, p);
	// printf("\ndebug SOY %d Y VOY A COMER. g->dead = %d-------------------\n", p->id, p->g->dead);
	// if (g->dead == 1)
	// 	return (pthread_mutex_unlock(p->right));
	// printf("\ndebug SOY %d Y VOY A COMER DE NUEVO. g->dead = %d-------------------\n", p->id, p->g->dead);
	pthread_mutex_lock(p->left);
	print_status("fork", g, p);
	if (g->dead == 0)
	{
		pthread_mutex_lock(&p->meal_lock);
		print_status("eat", g, p);
		p->eating = 1;
		my_usleep(g->t_eat);
		p->eating = 0;
		p->last_meal = get_time();
		pthread_mutex_unlock(&p->meal_lock);
	}
	pthread_mutex_unlock(p->left);
	pthread_mutex_unlock(p->right);
	return (0);
}

void	pintarlas(t_general *g, t_philo *p)
{
	print_status("think", g, p);
}

void	limpiarlas(t_general *g)
{
	int	i;

	i = -1;
	// printf("\ndebug SOY %d Y VOY A MORIR. g->dead = %d-------------------\n", g->p.id, g->p->g->dead);

	while (++i < g->num_philos)
	{
		/*pthread_mutex_lock(&g->philos[0].write_lock);
		printf("\nCUCU TRAS???\n");
		pthread_mutex_unlock(&g->philos[0].write_lock);*/
		if (&g->forks)
		{
			pthread_mutex_unlock(&g->forks[0]);
			// printf("\nFork nbr [%d]----------------------------------------------------------------------------------\n", i);
		}
		pthread_mutex_destroy(&g->forks[i]);
		if (g->philos)
		{
			pthread_mutex_destroy(&g->philos[i].dead_lock);
			pthread_mutex_destroy(&g->philos[i].meal_lock);
			pthread_mutex_destroy(&g->philos[i].write_lock);
		}
		pthread_detach(g->philos[i].tid);
	}
	if (g->forks)
		free(g->forks);
	if (g->philos)
		free(g->philos);
}
