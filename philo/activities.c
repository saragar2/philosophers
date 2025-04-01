/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:21:51 by saragar2          #+#    #+#             */
/*   Updated: 2025/04/01 19:02:36 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *s, t_general *g, t_philo *p)
{
	size_t	t;
	
	pthread_mutex_lock(p->write_lock);
	t = get_time() - g->stime;
	if (f_strcmp(s, "fork"))
		printf("%s[%u] %d  has taken a fork", PINK, t, p->id);
	else if (f_strcmp(s, "eat"))
		printf("%s[%u] %d  is eating", BLUE, t, p->id);
	else if (f_strcmp(s, "sleep"))
		printf("%s[%u] %d  is sleeping", GREEN, t, p->id);
	else if (f_strcmp(s, "think"))
		printf("%s[%u] %d  is thinking", YELLOW, t, p->id);
	else if (f_strcmp(s, "dead"))
		printf("%s[%u] %d  died", PURPLE, t, p->id);
	pthread_mutex_unlock(p->write_lock);
}

void	comer_techo(size_t milis, t_general *g, t_philo *p)
{
	size_t	start;

	print_status("sleep", g, p);
	start = get_time();
	while ((get_time() - start) < milis)
		usleep(500); //por que 500????
}

void	lonchazo(t_general *g, t_philo *p)
{
	pthread_mutex_lock(p->right);
	print_status("fork", g, p);
	if (g->num_philos == 1)
		one_philo(g, p);
	pthread_mutex_lock(p->left);
	print_status("fork", g, p);
	print_status("eat", g, p);
	pthread_mutex_lock(p->meal_lock);
	usleep(g->t_eat);
	p->eating = 1;
	p->last_meal = get_time();
	pthread_mutex_unlock(p->meal_lock);
	pthread_mutex_unlock(p->right);
	pthread_mutex_unlock(p->left);
}

void	pintarlas(t_general *g, t_philo *p)
{
	print_status("think", g, p);
}
