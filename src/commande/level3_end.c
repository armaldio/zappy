/*
** level3_end.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 28 17:48:50 2017 Martin Alais
** Last update Sun Jul  2 14:56:05 2017 martin alais
*/

#include "zappy.h"

int	*build_tab_3()
{
  int	*tab;

  tab = malloc(sizeof(int) * 7);
  tab[0] = 0;
  tab[1] = 2;
  tab[2] = 0;
  tab[3] = 1;
  tab[4] = 0;
  tab[5] = 2;
  tab[6] = 0;
  return (tab);
}

void	clean_player3(t_Player *player)
{
  player->action->is_leveling = false;
  send_message(player, "ko\n");
}

bool	is_ready_to_up_3(t_Player *tmp, t_Player *player)
{
  if (tmp->id != player->id && tmp->level == 3)
    return (true);
  return (false);
}

bool		incan_3bis(t_Server *server, t_Player *player)
{
  t_Player	*tmp;

  tmp = server->list_player;
  if (nbr_case_rdy(server, player) == 2)
    {
      while (tmp && is_ready_to_up_3(tmp, player) == false)
	tmp = tmp->next;
      if (is_ready_to_up_3(tmp, player) == true)
	{
	  player->action->is_leveling = false;
	  tmp->action->is_leveling = false;
	  player->action->friend_list[0] = tmp->id;
	  tmp->action->friend_list[0] = player->id;
	  send_message(player, "ko\n");
	  send_message(tmp, "Elevation Underway\n");
	  return (false);
	}
      else
	{
	  clean_player3(player);
	  return (false);
	}
    }
  return (true);
}

void		incan_3(t_Server *server, t_Player *player)
{
  t_Player	*tmp;

  tmp = server->list_player;
  if (compare_tab(build_tab_3(), build_tab(server, player)) &&
      nbr_case_rdy(server, player) == 2)
    {
      while (tmp && is_ready_to_up_3(tmp, player) == false)
	tmp = tmp->next;
      if (is_ready_to_up_3(tmp, player) == true)
	{
	  set_incan2(player, tmp);
	  player->action->friend_list[0] = tmp->id;
	  tmp->action->friend_list[0] = player->id;
	  send_message(player, "Elevation Underway\n");
	  send_message(tmp, "Elevation Underway\n");
	  return ;
	}
      else
	return (clean_player3(player));
    }
  else if (incan_3bis(server, player) == false)
    return ;
  player->action->is_leveling = false;
  send_message(player, "ko\n");
}
