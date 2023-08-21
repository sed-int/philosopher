/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:37:36 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/21 17:20:32 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(t_env *env, t_philo *philo)
{
	int	current;

	while (pthread_mutex_lock(&env->mutex[philo->num]) != 0)
		;
	gettimeofday(&philo->tv);
	current = philo->tv.tv_usec - philo->start_time;
	printf("%d philo %d has taken a fork\n", current, philo->num);
	while (pthread_mutex_lock(&env->mutex[philo->num + 1]) != 0)
		;
	gettimeofday(&philo->tv);
	current = philo->tv.tv_usec - philo->start_time;
	printf("%d philo %d has taken a fork\n", current, philo->num);
}

void	eat_meal(t_env *env, t_philo *philo)
{
	gettimeofday(&philo->tv);
	philo->last_eat_time = tv.tv_usec - philo->start_time;
	philo->stat = EATING;
	printf("%d philo %d is eating\n", philo->last_eat_time, philo->num);
	pthread_mutex_unlock(&env->mutex[philo->num]);
	pthread_mutex_unlock(&env->mutex[philo->num + 1]);
}

void	sleep_philo(t_env *env, t_philo *philo)
{
	int	current;

	gettimeofday(&philo->tv);
	current = philo->tv.tv_usec - philo->start_time;
	printf("%d philo %d is sleeping\n", current, philo->num);
	philo->stat = SLEEPING;
	usleep(env->arg.time_to_sleep);
}

void	think_philo(t_env *env, t_philo *philo)
{
	int	current;

	gettimeofday(&philo->tv);
	current = philo->tv.tv_usec - philo->start;
	philo->stat = THINKING;
	printf("%d philo %d is thinking\n", current, philo->num);
}

void	routine(void *philo)
{
	int	current;

	while (philo->env->is_dead == -1)
	{
		think_philo(philo->env, philo);
		pick_forks(philo->env, philo);
		eat_meal(philo->env, philo);
		sleep_philo(philo->env, philo);
	}
	gettimeofday(&philo->tv);
	current = philo->tv.tv_usec - philo->start;
	printf("%d philo %d is thinking\n", current, philo->env->is_dead);
}
