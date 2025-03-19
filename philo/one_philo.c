/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:10:27 by saragar2          #+#    #+#             */
/*   Updated: 2025/03/19 17:45:30 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_general *g, t_philo *p)
{
	usleep(g->t_die);
	pthread_mutex_unlock(p->right);
	//supongo que el monitor comprobará que este mongolo ha muerto
}