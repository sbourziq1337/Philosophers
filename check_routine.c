/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbourziq <sbourziq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:56:12 by sbourziq          #+#    #+#             */
/*   Updated: 2024/09/15 17:21:01 by sbourziq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parsing(t_data *data, char **av)
{
	if (ft_atoi(av[1]) <= 0)
		return (1);
	data->num_philo = ft_atoi(av[1]);
	data->num_frok = data->num_philo;
	if (ft_atoi(av[2]) <= 0)
		return (1);
	data->time_to_die = ft_atoi(av[2]);
	if (ft_atoi(av[3]) <= 0)
		return (1);
	data->time_to_eat = ft_atoi(av[3]);
	if (ft_atoi(av[4]) <= 0)
		return (1);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		if (ft_atoi(av[5]) <= 0)
			return (1);
		data->num_meal = ft_atoi(av[5]);
	}
	else
		data->num_meal = -1;
	return (0);
}

long	ft_process_digits(char *str, int *i)
{
	long	result;

	result = 0;
	while (str[*i] != '\0')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
		{
			if (result > (LONG_MAX - (str[*i] - '0')) / 10)
				return (LONG_MIN);
			result = result * 10 + (str[*i] - '0');
			(*i)++;
		}
		else
		{
			write(2, "Errore\n", 8);
			return (-1);
		}
	}
	return (result);
}

int	ft_atoi(char *av)
{
	int	number;
	int	i;

	number = 0;
	i = 0;
	if (!av)
		return (-1);
	while ((av[i] >= 9 && av[i] <= 13) || (av[i] == 32))
		i++;
	if (av[i] == '+')
		i++;
	if (av[i] == '-')
	{
		write(2, "Errore\n", 8);
		return (-1);
	}
	number = ft_process_digits(av, &i);
	return (number);
}

int	initialize_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philo)
	{
		if (pthread_mutex_init(&data->fork[i], NULL) != 0)
		{
			write(2, "Failed to initialize fork mutex", 32);
			return (1);
		}
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].r_fork = &data->fork[i];
		data->philo[i].l_fork = &data->fork[(i + 1) % data->num_philo];
		data->philo[i].index = i + 1;
		data->philo[i].my_data = data;
		data->philo[i].meals_eaten = 0;
		data->philo[i].start_time = get_current_time();
		data->philo[i].start = get_current_time();
	}
	if (pthread_mutex_init(&data->lock, NULL) != 0)
		return (1);
	return (0);
}

void	monitor_philosophers(t_data *data, t_philo *philo)
{
	int	i;

	while (1)
	{
		i = -1;
		while (++i < data->num_philo)
		{
			pthread_mutex_lock(&data->lock);
			if (get_current_time() - philo[i].start_time > data->time_to_die)
			{
				printf("%zu %d died\n", get_current_time() - philo[i].start,
					philo[i].index);
				data->flag = 1;
				pthread_mutex_unlock(&data->lock);
				return ;
			}
			if (data->num_philo == data->count_meal)
			{
				data->flag = 1;
				pthread_mutex_unlock(&data->lock);
				return ;
			}
			pthread_mutex_unlock(&data->lock);
		}
	}
}
