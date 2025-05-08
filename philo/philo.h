/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saragar2 <saragar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:43:24 by saragar2          #+#    #+#             */
/*   Updated: 2025/05/08 20:38:59 by saragar2         ###   ########.fr       */
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

# define PINK    "\033[38;2;255;182;193m"
# define BLUE    "\033[38;2;173;216;230m"
# define GREEN   "\033[38;2;152;251;152m"
# define YELLOW  "\033[38;2;255;255;153m"
# define PURPLE  "\033[38;2;216;191;216m"  
# define ORANGE  "\033[38;2;255;218;185m"
# define CYAN    "\033[38;2;175;238;238m"
# define LAVENDER "\033[38;2;230;230;250m"

typedef struct s_general
{
	struct s_philo	*philos; //sin inicializar (malloc hecho en init_philos() pero sin contenido)
	pthread_mutex_t	*forks;
	struct s_philo	*pakita;
	u_int64_t		start;
	int				end;
	u_int64_t		stime;
	int				dead;
	int				num_philos;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	long int		num_t_eat;
}				t_general;

typedef struct s_philo
{
	pthread_t			tid;
	pthread_t			pakita_tid;
	int					im_pakita;
	int	    			id;
	struct s_general	*g;
	pthread_t			thread; //sin inicializar
	size_t				eat_cont;
	int					eating;
	u_int64_t			last_meal;
	pthread_mutex_t		*right;
	pthread_mutex_t		*left;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
	pthread_mutex_t		*write_lock;
}				t_philo;

// ------------------------------------------------------------init
int			init_forks(t_general *g);
void		init_philos(t_general *g);
int			init_and_errs(t_general *g, int argc, char **argv);
// ------------------------------------------------------------main
void		print_error(char *arg);
// ------------------------------------------------------------one_philo
void		one_philo(t_general *g, t_philo *p);
// ------------------------------------------------------------threads MODIFICA LOS ARGS PLS
int			philosopher_dead(t_philo *p, size_t t_die);
int			check_if_dead(t_philo *p, t_general *g);
int			check_if_all_ate(t_philo *p, t_general *g);
void		*busybody_pakita(void *philovoid);
void		*routine(void *philovoid);
void		create_philos(t_general *g);
// ------------------------------------------------------------time
u_int64_t	get_time();
int			my_usleep(size_t milis);
// ------------------------------------------------------------utils
int 		ft_isvalidnum(char *s);
size_t		ft_atoi(const char *str);
int			f_strcmp(const char *s1, const char *s2);
// ------------------------------------------------------------activities MODIFICA LOS ARGS PLS
void		print_status(char *s, t_general *g, t_philo *p);
void		comer_techo(size_t milis, t_general *g, t_philo *p);
void		lonchazo(t_general *g, t_philo *p);
void		pintarlas(t_general *g, t_philo *p);
void		limpiarlas(t_general *g);

#endif