/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:18:26 by saragar2          #+#    #+#             */
/*   Updated: 2025/05/14 21:45:43 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isvalidnum(char *s)
{
	int	i;
	int	res;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	res = ft_atoi(s);
	if (res <= 0)
		return (1);
	return (0);
}

size_t	ft_atoi(const char *str)
{
	size_t	nb;

	nb = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*(str + 1) == '+' || *(str + 1) == '-')
			print_error("Atoi error: more than one sign");
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		nb = nb * 10 + (*str - '0');
		str++;
	}
	if (nb <= 0)
		print_error("You can't use 0");
	return (nb);
}

int	f_strcmp(const char *s1, const char *s2)
{
	int	cont;

	cont = 0;
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		cont = (unsigned char)*s1 - (unsigned char)*s2;
	return (cont);
}

void	hasta_el_tabique(t_general *g, t_philo *p)
{
	print_status("fork", g, p);
	print_status("eat", g, p);
	my_usleep(g->t_eat);
	pthread_mutex_lock(p->meal_lock);
	p->last_meal = get_time();
	p->eat_cont++;
	pthread_mutex_unlock(p->meal_lock);
}

void	subroutine(t_philo *p)
{
	pthread_mutex_lock(p->dead_lock);
	if (p->g->dead == 0)
	{
		pthread_mutex_unlock(p->dead_lock);
		lonchazo(p->g, p);
		pthread_mutex_lock(p->dead_lock);
	}
	if (p->g->dead == 0)
	{
		pthread_mutex_unlock(p->dead_lock);
		comer_techo(p->g->t_sleep, p->g, p);
		pthread_mutex_lock(p->dead_lock);
	}
	if (p->g->dead == 0)
	{
		pthread_mutex_unlock(p->dead_lock);
		pintarlas(p->g, p);
		pthread_mutex_lock(p->dead_lock);
	}
	pthread_mutex_unlock(p->dead_lock);
}
