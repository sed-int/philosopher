/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcho2 <hcho2@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:50:04 by hcho2             #+#    #+#             */
/*   Updated: 2023/08/21 16:00:32 by hcho2            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_philo(t_env *env, t_philo *philo)
{
	int	current;

	gettimeofday(&philo->tv);
	current = philo->tv.tv_usec - philo->last_eat_time;
	if (current > env->arg.time_to_die)
		env->is_dead = philo->num;
}
