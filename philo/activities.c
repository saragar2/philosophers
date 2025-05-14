/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:21:51 by saragar2          #+#    #+#             */
/*   Updated: 2025/05/14 21:51:56 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *s, t_general *g, t_philo *p)
{
	size_t	t;

	pthread_mutex_lock(p->dead_lock);
	if (g->dead == 0)
	{
		t = get_time() - g->stime;
		if (f_strcmp(s, "fork") == 0)
			printf("%s%lu %d has taken a fork\n", YELLOW, t, p->id);
		else if (f_strcmp(s, "eat") == 0)
			printf("%s%lu %d is eating\n", PINK, t, p->id);
		else if (f_strcmp(s, "sleep") == 0)
			printf("%s%lu %d is sleeping\n", BLUE, t, p->id);
		else if (f_strcmp(s, "think") == 0)
			printf("%s%lu %d is thinking\n", GREEN, t, p->id);
		else if (f_strcmp(s, "dead") == 0)
			printf("%s%lu %d died\n", PURPLE, t, p->id);
	}
	pthread_mutex_unlock(p->dead_lock);
}

void	comer_techo(size_t milis, t_general *g, t_philo *p)
{
	print_status("sleep", g, p);
	my_usleep(milis);
}

void	lonchazo(t_general *g, t_philo *p)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (p->right < p->left)
	{
		first = p->right;
		second = p->left;
	}
	else
	{
		first = p->left;
		second = p->right;
	}
	pthread_mutex_lock(first);
	print_status("fork", g, p);
	if (g->num_philos == 1)
	{
		pthread_mutex_unlock(first);
		my_usleep(g->t_die);
		return ;
	}
	pthread_mutex_lock(second);
	hasta_el_tabique(g, p);
	pthread_mutex_unlock(second);
	pthread_mutex_unlock(first);
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
		pthread_mutex_destroy(&g->forks[i]);
	free(g->philos[0].dead_lock);
	free(g->philos[0].meal_lock);
	free(g->philos[0].write_lock);
	if (g->forks)
		free(g->forks);
	if (g->philos)
		free(g->philos);
}
