/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunminjo <hyunminjo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:50:04 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/21 20:28:55 by hyunminjo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philo(t_env *env, t_philo *philo)
{
	int	current;

	gettimeofday(&philo->tv, 0);
	current = philo->tv.tv_usec - philo->last_eat_time;
	if (current > env->arg.time_to_die)
		env->is_dead = philo->num;
}
