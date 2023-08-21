/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:19:24 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/21 20:27:22 by hyunminjo        ###   ########.fr       */
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

enum e_stat
{
	EATING,
	THINKING,
	SLEEPING,
	DEAD
};

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
	int				start_time;
	int				last_eat_time;
	int				last_sleep_time;
	enum e_stat		stat;
	struct s_env	*env;
	t_time			tv;
}	t_philo;

typedef struct s_env
{
	t_arg			arg;
	t_philo			*philos;
	char			*forks;
	pthread_mutex_t	*mutex;
	int				start_time;
	int				is_dead;
}	t_env;

/* main */
void	philo(char	**av);

/* routine */
void	*routine(void *philo);
void	kill_philo(t_env *env, t_philo *philo);

/* utils */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif
