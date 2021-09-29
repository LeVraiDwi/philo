#include "philosopher.h"

int	ft_free_fork(int nb_philo, t_fork **array_fork)
{
	int	i;
	
	i = 0;
	while (i < nb_philo && array_fork != 0 && array_fork[i] != 0)
	{
		pthread_mutex_destroy(&array_fork[i]->mutex);
		if (array_fork[i] != 0)
			free(array_fork[i]);
		i++;
	}
	if (array_fork != 0)
		free(array_fork);
	return (0);
}

int	ft_free_philo(int nb_philo, t_philosophe **philo)
{
	int i;

	i = 0;
	if (!philo)
		return (0);
	while (i < nb_philo)
	{
		free(philo[i]);
		i++;
	}
	free(philo);
	return (0);
}

int	ft_free_struct(t_setting setting, t_philosophe **philo, t_fork **array_fork)
{
	ft_free_fork(setting.time[0], array_fork);
	ft_free_philo(setting.time[0], philo);
	pthread_mutex_destroy(&setting.write);
	return (0);
}
