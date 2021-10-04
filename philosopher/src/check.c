#include "philosophr.c"

void	*ft_check(void *data)
{
	int	i;
	t_philosophe	**philo;
	int	done_eat;

	i = 0;
	eat = 0;
	philo = (t_philosophe **)data;
	while (1)
	{
		if (i >= philo[0]->setting->time[0])
		{
			if (done_eat + 1 == philo->setting->time[4])
			{
				philo->setting->end  = 0;
				return (&done_eat);
			}
			else
				eat = 0;
			i = 0;
		}
			if (!ft_check_philo(philo[i], &done_eat))
				return (0);
		i++;
	}
}
