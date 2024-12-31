/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <sbourziq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:39:41 by sbourziq          #+#    #+#             */
/*   Updated: 2024/09/15 17:12:38 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_arguments(int argc)
{
	if (argc < 5 || argc > 6)
	{
		write(2, "Invalid number of arguments\n", 28);
		return (1);
	}
	return (0);
}

int	allocate_memory(t_data *data)
{
	data->philo = malloc(data->num_philo * sizeof(t_philo));
	if (!data->philo)
	{
		write(2, "Failed to allocate memory for philo", 36);
		return (1);
	}
	data->fork = malloc(data->num_philo * sizeof(pthread_mutex_t));
	if (!data->fork)
	{
		write(2, "Failed to allocate memory for forks", 36);
		free(data->philo);
		return (1);
	}
	return (0);
}

int	initialize_simulation(t_data *data)
{
	if (initialize_mutexes(data) != 0)
	{
		free(data->philo);
		free(data->fork);
		return (1);
	}
	data->flag = 0;
	data->count_meal = 0;
	return (0);
}

int	create_and_monitor_philosophers(t_data *data)
{
	if (create_philosophers(data) != 0)
	{
		cleanup_mutexes(data);
		free(data->philo);
		free(data->fork);
		return (1);
	}
	monitor_philosophers(data, data->philo);
	join_threads(data, data->philo);
	return (0);
}

void	cleanup_resources(t_data *data)
{
	cleanup_mutexes(data);
	free(data->philo);
	free(data->fork);
}
