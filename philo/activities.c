/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activities.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 17:21:51 by saragar2          #+#    #+#             */
/*   Updated: 2025/03/04 18:02:57 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	comer_techo(size_t milis)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milis)
		usleep(500); //por que 500????
}

void	lonchazo()
{
	
}

void	limpiar_el_cristal()
{

}
