/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:16:25 by saragar2          #+#    #+#             */
/*   Updated: 2025/02/12 16:31:07 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

u_int64_t	get_time(void)
{
	u_int64_t		time;
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		print_error("Error in gettimeofday()");
	time = (tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000);
	return (time);
}