/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:21:51 by saragar2          #+#    #+#             */
/*   Updated: 2025/05/08 21:34:07 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *s, t_general *g, t_philo *p)
{
	size_t	t;
	
    // printf("\n\nHOLA SOY EL %d\n", p->id);
    // pthread_mutex_lock(g->philos[0].dead_lock);
	    pthread_mutex_lock(p->dead_lock);
    if (g->dead == 0)
    {
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
    }
	pthread_mutex_unlock(p->dead_lock);
}

void	comer_techo(size_t milis, t_general *g, t_philo *p)
{
	// size_t	start;

	print_status("sleep", g, p);
	// start = get_time();
	// (void)start;
	// while ((get_time() - start) < milis)
		// my_usleep(500); //por que 500????
	// my_usleep(g->t_sleep);
	my_usleep(milis);
}

void lonchazo(t_general *g, t_philo *p)
{
    pthread_mutex_t *first;
    pthread_mutex_t *second;

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
    pthread_mutex_lock(second);
    print_status("fork", g, p);
    pthread_mutex_lock(p->meal_lock);
    print_status("eat", g, p);
    p->eating = 1;
    my_usleep(g->t_eat);
    p->eating = 0;
    p->last_meal = get_time();
    pthread_mutex_unlock(p->meal_lock);
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
    // while (++i < g->num_philos)
    // {
    //     printf("\nHOLA SOY EL %d\n", i);
    //     // if (g->philos[i].tid)
    //         pthread_join(g->philos[i].tid, NULL);
    // }
    // pthread_mutex_destroy(g->philos[0].dead_lock);
    // pthread_mutex_destroy(g->philos[0].meal_lock);
    // pthread_mutex_destroy(g->philos[0].write_lock);
    i = -1;
    while (++i < g->num_philos)
        pthread_mutex_destroy(&g->forks[i]);
    if (g->forks)
        free(g->forks);
    if (g->philos)
        free(g->philos);
}
