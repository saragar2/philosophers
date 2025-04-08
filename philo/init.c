/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:09:13 by saragar2          #+#    #+#             */
/*   Updated: 2025/04/08 21:12:11 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_general *g)
{
	int	i;

	i = -1;
	g->forks = malloc(sizeof(pthread_mutex_t) * g->num_philos);
	if (!g->forks)
		print_error("Malloc error: forks", g);
	while (++i < g->num_philos)
		pthread_mutex_init(&g->forks[i], NULL);
	g->philos[0].left = &g->forks[0];
	g->philos[0].right = &g->forks[g->num_philos - 1];
	i = 1;
	while (i < g->num_philos)
	{
		g->philos[i].left = &g->forks[i];
		g->philos[i].right = &g->forks[i - 1];
		i++;
	}
	return (0);
}

void	init_philos(t_general *g)
{
	int	i;

	i = -1;
	g->tid = malloc(sizeof(pthread_t) * g->num_philos);
	if (!g->tid)
		print_error("Malloc error: tid", g);
	g->philos = malloc(sizeof(t_philo) * g->num_philos);
	if (!g->philos)
		print_error("Malloc error: philos", g);
	while (++i < g->num_philos)
	{
		g->philos[i].id = i + 1;
		g->philos[i].eat_cont = 0;
		g->philos[i].eating = 0;
		g->philos[i].last_meal = 0;
		g->philos[i].g = g;
		pthread_mutex_init(&g->philos[i].dead_lock, NULL);
		pthread_mutex_init(&g->philos[i].meal_lock, NULL);
		pthread_mutex_init(&g->philos[i].write_lock, NULL);
	}
}

int	init_and_errs(t_general *g, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		print_error("Invalid amount of arguments", g);
	if (ft_isvalidnum(argv[1]) == 1 || ft_isvalidnum(argv[2]) == 1 || 
		ft_isvalidnum(argv[3]) == 1 || ft_isvalidnum(argv[4]) == 1 ||
		(argc == 6 && ft_isvalidnum(argv[5]) == 1))
		print_error("Invalid argument", g);
	g->start = 0;
	g->end = 0;
	g->stime = 0;
	g->dead = 0;
	g->num_philos = ft_atoi(argv[1], g);
	g->t_die = ft_atoi(argv[2], g);
	g->t_eat = ft_atoi(argv[3], g);
	g->t_sleep = ft_atoi(argv[4], g);
	if (argc == 6)
		g->num_t_eat = ft_atoi(argv[5], g);
	else
		g->num_t_eat = -1;
	init_forks(g);
	init_philos(g);
	return (0);
}
