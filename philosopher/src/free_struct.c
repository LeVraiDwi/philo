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
