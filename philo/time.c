/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:16:25 by saragar2          #+#    #+#             */
/*   Updated: 2025/05/08 19:17:19 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

u_int64_t	get_time()
{
	u_int64_t		time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000);
	return (time);
}

int	my_usleep(size_t milis)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < milis)
		usleep(1);
	return (0);
}