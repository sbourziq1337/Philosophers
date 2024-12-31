/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <sbourziq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:39:52 by sbourziq          #+#    #+#             */
/*   Updated: 2024/09/15 17:11:24 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_simulation_end(t_philo *phil)
{
	pthread_mutex_lock(&phil->my_data->lock);
	if (phil->my_data->flag == 1)
	{
		pthread_mutex_unlock(&phil->my_data->lock);
		return (1);
	}
	pthread_mutex_unlock(&phil->my_data->lock);
	return (0);
}

void	cleanup_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->fork[i]);
		i++;
	}
	pthread_mutex_destroy(&data->lock);
}
