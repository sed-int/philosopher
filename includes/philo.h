/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:19:24 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/25 18:18:53 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct timeval	t_time;
/* input */

typedef struct s_arg
{
	int	number_of_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_count;
}	t_arg;

typedef struct s_philo
{
	pthread_t		thr;
	int				num;
	int				eat_cnt;
	long			last_eat_time;
	int				last_sleep_time;
	int				left;
	int				right;
	int				is_dead;
	struct s_env	*env;
}	t_philo;

typedef struct s_env
{
	t_arg			arg;
	t_philo			*philos;
	char			*forks;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	dead_mutex;
	int				is_over;
	int				eat_cnt;
	long			start_time;
}	t_env;

/* main */
void	philo(char	**av);

/* init */
void	init_env(t_env *env, char **av);
void	init_philo(t_env *env, t_philo *philos);

/* monitor */
void	*count_monitor(void *arg);
void	*death_monitor(void *arg);

/* routine */
void	*routine(void *philo);
long	get_time(void);
int		ft_usleep(long time);
int		is_dead(t_philo *philo, t_env *env);

/* utils */
int		ft_atoi(const char *str);
void	free_all(t_env *env);
void	print_msg(t_philo *philo, char *msg);

#endif
