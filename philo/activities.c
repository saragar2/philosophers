/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:21:51 by saragar2          #+#    #+#             */
/*   Updated: 2025/03/13 18:56:26 by saragar2         ###   ########.fr       */
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

void	lonchazo()
{
	
}

void	pintarlas(t_general *g, t_philo *p)
{
	print_status("think", g, p);
}
