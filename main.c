#include "thread.h"

static void	*ft_announce(void *p_data)
{
	t_mut	*mutest;
	int		*j;

	mutest = (t_mut *)p_data;
	pthread_mutex_lock(&mutest->mutex);
	usleep(2000000);
	j = (int *)malloc(sizeof(int) * 1);
	if (j == 0)
		return (0);
	mutest->i = mutest->i + 1;
	*j = mutest->i;
	ft_write("salut les amis c'est squeezi, cette video numero %d est sponso lol mdr\n", mutest, mutest->i, 0);
	pthread_mutex_unlock(&mutest->mutex);
	return ((void*)j);
}

ft_write(char *str, t_mut *mutest, int i, int j)
{
	pthread_mutex_lock(&mutest->write);
	printf(str, i, j);
	pthread_mutex_unlock(&mutest->write);
}

int main()
{
	t_announce 	youteubeur[5];
	t_mut		mutest;
	int			i;
	int			*j;

	i = 0;
	pthread_mutex_init(&mutest.mutex, NULL);
	pthread_mutex_init(&mutest.write, NULL);
	mutest.i = 0;
	while (i < 5)
	{
		youteubeur[i].name = i;
		if (pthread_create(&youteubeur[i].thread, 0, ft_announce, (void *)&mutest))
		{
			printf("Error\n");
			return (0);
		}
		usleep(2);
		i++;
	}
	printf("fin alloc\n");
	i = 0;
	while (i < 5)
	{
		pthread_join(youteubeur[i].thread, (void **)&j);
		ft_write("pid:%d: fin annonce %d\n", &mutest, youteubeur[i].name, *j);
		free(j);
		i++;
	}
	pthread_mutex_destroy(&mutest.mutex);
	return (1);	
}
