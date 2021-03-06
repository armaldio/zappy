/*
** server2.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 19 19:21:28 2017 Martin Alais
** Last update Sun Jul  2 22:07:07 2017 hamza hammouche
*/

#include "Server.h"
#include "Player.h"
#include "Socket.h"
#include "zappy.h"

void	basic_init_server(t_Server *server)
{
  server->list_player = NULL;
  server->socket = my_malloc(sizeof(t_Connection));
  server->world = my_malloc(sizeof(t_World));
  server->list_teams = NULL;
  server->nbClientMax = 5;
  basic_init_socket(server->socket);
  basic_init_world(server->world);
  server->f = 100;
}

void	init_inventaire(t_Player *player, t_Server *server)
{
  player->inventaire = my_malloc(sizeof(t_Inventaire));
  player->inventaire->deraumere = 0;
  player->inventaire->linemate = 0;
  player->inventaire->mendiane = 0;
  player->inventaire->phiras = 0;
  player->inventaire->sibur = 0;
  player->inventaire->thystane = 0;
  player->inventaire->food = my_safe_div((1260 / server->f),
					 (126 / server->f));
}

void		init_server(t_Server *server)
{
  struct timeval tvTime;

  gettimeofday(&tvTime, NULL);
  init_socket(server->socket);
  server->socket->s_in_size_accept = sizeof(server->socket->s_in_accept);
  server->list_player = NULL;
  server->list_graphic = NULL;
  server->list_undefined = NULL;
  init_world(server->world);
  server->tmp_time = 0;
}

t_Position	get_spaw_pos(t_Server *server)
{
  t_Position	res;

  res.x = rand() % (server->world->height - 1);
  res.y = rand() % (server->world->width - 1);
  return (res);
}
