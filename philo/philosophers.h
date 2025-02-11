/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:43:24 by saragar2          #+#    #+#             */
/*   Updated: 2025/02/05 19:39:17 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <pthread.h>

typedef struct s_general
{
	int		num;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		num_t_eat;
}				t_general;

typedef struct s_philo
{
	int	    			*id;
	pthread_t			thread;
	pthread_mutex_t		fork;
	struct s_philo		right;
	struct s_philo		left;
}				t_philo;

// ------------------------------------------------------------parsing
void	print_error(char *arg);
int		init_and_errs(t_general *g, int argc, char **argv);
// ------------------------------------------------------------utils
int		ft_atoi(const char *str);
int 	ft_isvalidnum(char *s);

#endif