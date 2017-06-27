/*
** graphic.h for zappy in /home/alaism/dev/tek2/PSU/zappy/src/game/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:37:32 2017 Martin Alais
** Last update Mon Jun 26 15:54:30 2017 Martin Alais
*/

#include "zappy.h"

void init_graphic(t_graphic *new, int fd, int id)
{
	new->fd = fd;
	new->id = id;
	new->next = NULL;
}

void add_graphic(int fd, t_Server *server)
{
	t_graphic *new;
	t_graphic *tmp;

	new = my_malloc(sizeof(t_graphic));
	tmp = server->list_graphic;
	if (server->list_graphic != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	if (server->list_graphic == NULL)
	{
		init_graphic(new, fd, 1);
		server->list_graphic = new;
	}
	else
	{
		init_graphic(new, fd, tmp->id + 1);
		tmp->next = new;
	}
}

void delete_graphic(t_Server *server, int id)
{
	t_graphic *tmp;
	t_graphic *last;

	last = NULL;
	tmp = server->list_graphic;
	while (tmp)
	{
		if (tmp->id == id)
		{
			printf("Graphic with id %d deleted\n", tmp->id);
			if (last == NULL)
				server->list_graphic = tmp->next;
			else
				last->next = tmp->next;
			free(tmp);
			return;
		}
		last = tmp;
		tmp = tmp->next;
	}
}