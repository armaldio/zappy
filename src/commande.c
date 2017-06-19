#include "zappy.h"
#include "Incantation.h"

void commande_forward(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->gaze == UP)
		go_up(server, id);
	else if (tmp->gaze == DOWN)
		go_down(server, id);
	else if (tmp->gaze == RIGHT)
		go_right(server, id);
	else
		go_left(server, id);
}

void commande_right(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->gaze == UP)
		tmp->gaze = RIGHT;
	else if (tmp->gaze == RIGHT)
		tmp->gaze = DOWN;
	else if (tmp->gaze == DOWN)
		tmp->gaze = LEFT;
	else
		tmp->gaze = UP;
	send_message(tmp->fd, "OK\n");
}

void commande_left(int id, t_Server *server, char *data)
{
	t_Player *tmp;

	(void) data;
	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	if (tmp->gaze == UP)
		tmp->gaze = LEFT;
	else if (tmp->gaze == LEFT)
		tmp->gaze = DOWN;
	else if (tmp->gaze == DOWN)
		tmp->gaze = RIGHT;
	else
		tmp->gaze = UP;
	send_message(tmp->fd, "OK\n");
}

void commande_incantation(int id, t_Server *server, char data)
{
	void	*mfunction_ptr[] = {incan_1, incan_2, incan_3, incan_4, incan_5, NULL};
	t_Player *tmp;
	void	(*fct_ptr)(int, t_Server *);

	(void) data;
	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	fct_ptr = mfunction_ptr[tmp->level - 1];
	fct_ptr(id, server);
}

void command_take(int id, t_Server *server, char *data)
{
	t_Player *tmp;
	char *all_stone[] = {"linemate", "deraumere", "sibur", "mendiane", "phiras", "thystane", NULL};
	void	*mfunction_ptr[] = {take_linemate, take_deraumere, take_sibur, take_mendiane, take_phiras, take_thystane, NULL};
	void	(*fct_ptr)(int id, t_Server *);
	int a;

	a = 0;
	data += 5;
	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	while(all_stone[a])
	{
		if (strncmp(all_stone[a], data, strlen(all_stone[a])) == 0)
		{
			fct_ptr = mfunction_ptr[a];
			fct_ptr(id, server);
			print_world(server->world);
			return;
		}
		a += 1;
	}
}

void command_not_found(int id, t_Server *server)
{
	t_Player *tmp;

	tmp = server->list_player;
	while(tmp->next && tmp->id != id)
		tmp = tmp->next;
	send_message(tmp->fd, "KO\n");
}

void parser_commande(int id, t_Server *server, char *data)
{
	char	*mcommand[] = {"Forward", "Right", "Left", "Incantation", "Take", NULL};
	void	*mfunction_ptr[] = {commande_forward, commande_right, commande_left, commande_incantation, command_take, NULL};
	void	(*fct_ptr)(int, t_Server *, char *);
	int		a;

	a = 0;
	while(mcommand[a])
	{
		if (strncmp(mcommand[a], data, strlen(mcommand[a])) == 0)
		{
			fct_ptr = mfunction_ptr[a];
			fct_ptr(id, server, data);
			return;
		}
		a += 1;
	}
	command_not_found(id, server);
}
