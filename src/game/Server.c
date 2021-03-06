/*
** Server.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:21:42 2017 Martin Alais
** Last update Sun Jul  2 18:16:26 2017 martin alais
*/

#include "Server.h"
#include "Player.h"
#include "Socket.h"
#include "zappy.h"
#include "Event.h"

int		get_new_id(t_Server *server)
{
  int		a;
  t_Player	*tmp;

  a = 0;
  tmp = server->list_player;
  while (tmp)
    {
      if (tmp->isEgg == false)
	a = tmp->id;
      tmp = tmp->next;
    }
  return (a);
}

void	eggs_connection_message(int a, t_Player *p)
{
  (void) a;
  send_message(p, "WELCOME\n");
  printf("Linking connection to player %d\n", p->id);
  send_message(p, "ok\n");
}

void	check_new_player(t_Server *server)
{
  int	a;

  set_socket_statue(server->socket->fd, 0);
  a = accept(server->socket->fd,
	     (struct sockaddr *)&server->socket->s_in_accept,
	     &server->socket->s_in_size_accept);
  set_socket_statue(server->socket->fd, 1);
  t_Player *p = get_First_Player_Available(server->list_player);
  if (a != -1)
    {
      if (p != NULL)
	{
	  p->fd = a;
	  eggs_connection_message(a, p);
	  p->is_connected = true;
	  p->isEgg = false;
	  p->controlled = true;
	  event_conection_for_eggs(server, p);
	  p->id = get_new_id(server) + 1;
	  event_new_player(server, p);
	  return ;
	}
      else
	add_undefined(a, server);
    }
}
