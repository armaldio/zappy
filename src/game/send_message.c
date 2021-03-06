/*
** send_message.c for zappy in /home/hammouche/Documents/PSU_2016/zappy/src/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Fri Jun 23 11:45:52 2017 hamza hammouche
** Last update Sun Jul  2 22:32:21 2017 Walter Bonetti
*/

#include "zappy.h"
#include "Incantation.h"

void		send_message_position(t_graphic *head, char *msg)
{
  t_graphic	*tmp;

  tmp = head;
  while (tmp)
    {
      send_message_graphic(tmp, msg);
      tmp = tmp->next;
    }
}

bool	send_message_undefine(t_undefined *player, char *msg)
{
  int	a;

  a = ucbuffer_write(player->write_buffer, msg, strlen(msg));
  if (a <= 0)
    return (false);
  ucbuffer_move(player->write_buffer, &player->write_buffer->tail, a);
  return (true);
}

bool	send_message_graphic(t_graphic *player, char *msg)
{
  int	a;

  if (msg[0] == '\0')
    return (false);
  if (player == NULL || player->fd == 0)
    return (false);
  a = ucbuffer_write(player->write_buffer, msg, strlen(msg));
  if (a <= 0)
    return (false);
  ucbuffer_move(player->write_buffer, &player->write_buffer->tail, a);
  return (true);
}
