/*
** update_function.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Wed Jun 21 13:32:36 2017 Martin Alais
** Last update Sun Jul  2 18:17:54 2017 martin alais
*/

#include "zappy.h"
#include "Incantation.h"

void	check_update_level(t_Server *server, t_Player *player)
{
  void	*mfunction_ptr[] = {incan_1, incan_2, incan_3,
			    incan_4, incan_5, incan_6, incan_7, NULL};
  void	(*fct_ptr)(t_Server *, t_Player *);

  fct_ptr = mfunction_ptr[player->level - 1];
  fct_ptr(server, player);
}

void		check_player_leveling(t_Server *server)
{
  t_Player	*tmp;

  tmp = server->list_player;
  while (tmp)
    {
      if (tmp->action->is_leveling == true)
	check_update_level(server, tmp);
      tmp = tmp->next;
    }
}
