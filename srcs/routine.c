/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:36 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/22 00:46:18 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_env *env, t_philo *philo)
{
	int	current;

	// while (pthread_mutex_lock(&env->mutex[philo->num]) != 0)
	// 	;
	// gettimeofday(&philo->tv, 0);
	// current = philo->tv.tv_usec - philo->start_time;
	// printf("%d philo %d has taken a fork\n", current, philo->num);
	// while (pthread_mutex_lock(&env->mutex[(philo->num + 1) % env->arg.number_of_philos]) != 0)
	// 	;
	pthread_mutex_lock(&env->mutex[philo->num]);
	pthread_mutex_lock(&env->mutex[(philo->num + 1) % env->arg.number_of_philos]);
	gettimeofday(&philo->tv, 0);
	current = philo->tv.tv_usec - philo->start_time;
	printf("%d philo %d has taken a fork\n", current, philo->num);
}

void	eat_meal(t_env *env, t_philo *philo)
{
	gettimeofday(&philo->tv, 0);
	philo->last_eat_time = philo->tv.tv_usec - philo->start_time;
	philo->stat = EATING;
	printf("%d philo %d is eating\n", philo->last_eat_time, philo->num);
	pthread_mutex_unlock(&env->mutex[(philo->num + 1) % env->arg.number_of_philos]);
	pthread_mutex_unlock(&env->mutex[philo->num]);
}

void	sleep_philo(t_env *env, t_philo *philo)
{
	int	current;

	gettimeofday(&philo->tv, 0);
	current = philo->tv.tv_usec - philo->start_time;
	printf("%d philo %d is sleeping\n", current, philo->num);
	philo->stat = SLEEPING;
	usleep(env->arg.time_to_sleep);
}

void	think_philo(t_env *env, t_philo *philo)
{
	int	current;

	(void)env;
	gettimeofday(&philo->tv, 0);
	current = philo->tv.tv_usec - philo->start_time;
	philo->stat = THINKING;
	printf("%d philo %d is thinking\n", current, philo->num);
}

void	*routine(void *data)
{
	int		current;
	t_philo *philo;

	philo = (t_philo *)data;
	if (philo->num % 2)
	{
		while (philo->env->is_dead == -1)
		{
			think_philo(philo->env, philo);
			pick_forks(philo->env, philo);
			eat_meal(philo->env, philo);
			sleep_philo(philo->env, philo);
		}
	}
	else
	{
		while (philo->env->is_dead == -1)
		{
			pick_forks(philo->env, philo);
			eat_meal(philo->env, philo);
			sleep_philo(philo->env, philo);
			think_philo(philo->env, philo);
		}
	}
	gettimeofday(&philo->tv, 0);
	current = philo->tv.tv_usec - philo->start_time;
	printf("%d philo %d died\n", current, philo->env->is_dead);
	return (0);
}
