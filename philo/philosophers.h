/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:43:24 by saragar2          #+#    #+#             */
/*   Updated: 2025/02/11 19:26:42 by saragar2         ###   ########.fr       */
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
	pthread_t		*tid;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_t_eat;
}				t_general;

typedef struct s_philo
{
	t_general			*general;
	int	    			id;
	pthread_t			thread;
	pthread_mutex_t		fork;
	struct s_philo		right;
	struct s_philo		left;
	int					t_die;
	int					eat_cont;
	int					eating;
	int					status;
	pthread_mutex_t		lock;
}				t_philo;

// ------------------------------------------------------------parsing
void	print_error(char *arg);
int		init_and_errs(t_general *g, int argc, char **argv);
// ------------------------------------------------------------utils
int		ft_atoi(const char *str);
int 	ft_isvalidnum(char *s);

#endif