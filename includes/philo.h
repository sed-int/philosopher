/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:19:24 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/20 17:27:35 by hcho2            ###   ########.fr       */
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
	int	number;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_count;
}	t_arg;

typedef struct s_philo
{
	pthread_t	philo_handle;
	int			num;
	t_time		start_time;
	t_time		last_eat_time;
	t_time		last_sleep_time;
	int			status;
}	t_philo;

typedef struct s_env
{
	t_arg			arg;
	t_philo			*philo;
	int				*forks;
	pthread_mutex_t	*mutex;
	int				start_time;
	int				die_flag;
}	t_env;

/* main */
void	philo(char	**av);

/* utils */
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif
