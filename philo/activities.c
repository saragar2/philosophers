/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:21:51 by saragar2          #+#    #+#             */
/*   Updated: 2025/04/16 17:02:34 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *s, t_general *g, t_philo *p)
{
	size_t	t;
	
	pthread_mutex_lock(&p->write_lock);
	t = get_time() - g->stime;
	if (f_strcmp(s, "fork"))
		printf("%s[%lu] %d has taken a fork\n", PINK, t, p->id);
	else if (f_strcmp(s, "eat"))
		printf("%s[%lu] %d is eating\n", BLUE, t, p->id);
	else if (f_strcmp(s, "sleep"))
		printf("%s[%lu] %d is sleeping\n", GREEN, t, p->id);
	else if (f_strcmp(s, "think"))
		printf("%s[%lu] %d is thinking\n", YELLOW, t, p->id);
	else if (f_strcmp(s, "dead"))
		printf("%s[%lu] %d died\n", PURPLE, t, p->id);
	pthread_mutex_unlock(&p->write_lock);
}

void	comer_techo(size_t milis, t_general *g, t_philo *p)
{
	size_t	start;

	print_status("sleep", g, p);
	start = get_time();
	while ((get_time() - start) < milis)
		my_usleep(500); //por que 500????
}

void	lonchazo(t_general *g, t_philo *p)
{
	printf("\ndebug\n");
	pthread_mutex_lock(p->right);
	print_status("fork", g, p);
	if (g->num_philos == 1)
		one_philo(g, p);
	pthread_mutex_lock(p->left);
	print_status("fork", g, p);
	print_status("eat", g, p);
	pthread_mutex_lock(&p->meal_lock);
	my_usleep(g->t_eat);
	p->eating = 1;
	p->last_meal = get_time();
	pthread_mutex_unlock(&p->meal_lock);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
}

void	pintarlas(t_general *g, t_philo *p)
{
	print_status("think", g, p);
}

void	limpiarlas(t_general *g)
{
	int	i;

	i = -1;
	while (++i < g->num_philos)
	{
		if (g->forks)
		{
			pthread_mutex_destroy(g->philos[i].right);
			pthread_mutex_destroy(g->philos[i].left);
		}
		if (g->philos)
		{
			pthread_mutex_destroy(&g->philos[i].dead_lock);
			pthread_mutex_destroy(&g->philos[i].meal_lock);
			pthread_mutex_destroy(&g->philos[i].write_lock);
		}
	}
	if (g->forks)
		free(g->forks);
	if (g->philos)
		free(g->philos);
}
