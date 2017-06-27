/*
** level6.c for zappy in /home/alaism/dev/tek2/PSU/zappy/src/commande/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Mon Jun 26 13:30:03 2017 Martin Alais
** Last update Mon Jun 26 16:25:41 2017 hamza hammouche
*/

#include "zappy.h"
#include "Incantation.h"

t_Player **get_list_level_6(t_Server *server, t_Player *player)
{
	t_Player **tmp2;
	t_Player *tmp;
	int a;

	a = 0;
	tmp2 = my_malloc(sizeof(t_Player *) * 5);
	tmp2[0] = NULL;
	tmp2[1] = NULL;
	tmp2[2] = NULL;
	tmp2[3] = NULL;
	tmp2[4] = NULL;
	tmp = server->list_player;
	while (tmp)
	{
		if (tmp->id != player->id && tmp->action->is_leveling == true &&
			tmp->level == 6 && a < 5 && tmp->inventaire->linemate >= 1 &&
			tmp->inventaire->deraumere >= 2 && tmp->inventaire->sibur >= 3 &&
			tmp->inventaire->phiras >= 1)
		{
			tmp2[a] = tmp;
			a += 1;
		}
		tmp = tmp->next;
	}
	return (tmp2);
}

void level_up_6(t_Player **player, t_Server *server)
{
	int a;

  (void)server;
	a = 0;
	while (a < 5)
	{
		player[a]->inventaire->linemate -= 1;
		player[a]->inventaire->deraumere -= 2;
		player[a]->inventaire->sibur -= 3;
		player[a]->inventaire->phiras -= 1;
		player[a]->action->is_leveling = false;
		player[a]->level = 7;
		printf("Player %d reach level 7!\n", player[a]->id);
		event_endI(server, player[a]);
		stok_answer(player[a], "ok\n");
		a += 1;
	}
}

void incan_6(t_Server *server, t_Player *player)
{
	t_Player *tmp;
	t_Player **tmp2;

	tmp = server->list_player;
	if (tmp->inventaire->linemate >= 1 && tmp->inventaire->deraumere >= 2 &&
		tmp->inventaire->sibur >= 3 && tmp->inventaire->phiras >= 1)
	if (check_nbr_at_level(server, 6) >= 6)
	{
		tmp2 = get_list_level_6(server, player);
		if (tmp2[0] != NULL && tmp2[1] != NULL &&
			tmp2[2] != NULL && tmp2[3] != NULL && tmp2[4] != NULL)
		{
			player->inventaire->linemate -= 1;
			player->inventaire->deraumere -= 2;
			player->inventaire->sibur -= 3;
			player->inventaire->phiras -= 1;
			player->action->is_leveling = false;
			player->level = 7;
			printf("Player %d reach level 7!\n", player->id);
	    event_endI(server, player);
			stok_answer(player, "ok\n");
			level_up_6(tmp2, server);
			free(tmp2);
		}
	}
}