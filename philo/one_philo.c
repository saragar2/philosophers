/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:10:27 by saragar2          #+#    #+#             */
/*   Updated: 2025/05/08 16:16:34 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_general *g, t_philo *p)
{
	my_usleep(g->t_die);
	pthread_mutex_unlock(p->right);
	//supongo que el monitor comprobará que este mongolo ha muerto
}