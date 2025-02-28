/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:43:24 by saragar2          #+#    #+#             */
/*   Updated: 2025/02/27 20:35:09 by saragar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_general
{
	pthread_t		*tid;
	struct s_philo	*philos; //sin inicializar (malloc hecho en init_philos() pero sin contenido)
	pthread_mutex_t	*forks;
	int				start;
	int				end;
	u_int64_t		stime;
	int				num_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_t_eat;
}				t_general;

typedef struct s_philo
{
	int	    			id;
	pthread_t			thread; //sin inicializar
	int					t_die;
	int					eat_cont;
	int					status;
	pthread_mutex_t		*right;
	pthread_mutex_t		*left;
	pthread_mutex_t		dead_lock;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		write_lock;
}				t_philo;

// ------------------------------------------------------------parsing
void		print_error(char *arg);
int			init_and_errs(t_general *g, int argc, char **argv);
int			init_forks(t_general *g);
void		init_philos(t_general *g);
// ------------------------------------------------------------threads MODIFICA LOS ARGS PLS
void		one_philo(t_general *g);
void		busybody_pakita();
void		routine();
void		create_philos();
// ------------------------------------------------------------time
u_int64_t	get_time(void); //COMO QUE VOID A SECAS????
// ------------------------------------------------------------utils
int			ft_atoi(const char *str);
int 		ft_isvalidnum(char *s);

#endif