/*
** Server.h for zappy in /home/hammouche/Documents/PSU_2016/zappy/include/
**
** Made by hamza hammouche
** Login   <hamza.hammouche@epitech.eu>
**
** Started on  Mon Jun 19 16:59:53 2017 hamza hammouche
** Last update Sun Jul  2 17:23:18 2017 martin alais
*/

#ifndef ZAPPY_SERVER_H_
# define ZAPPY_SERVER_H_

#include "Player.h"
#include "Socket.h"
#include "World.h"

typedef struct	s_Team
{
  int		id;
  char		*name;
  int		nbMember;
  struct s_Team *next;
}		t_team;

typedef struct	s_Server
{
  t_undefined	*list_undefined;
  t_graphic	*list_graphic;
  t_Player	*list_player;
  t_Connection	*socket;
  t_World	*world;
  t_team	*list_teams;
  double	f;
  int		nbClientMax;
  double	tmp_time;
}		t_Server;

bool	check_valide_team(char *team_name, t_Server *server,
		       t_undefined *undefine);
bool	end_game(t_Server *serv);
void	init_server(t_Server *server);
void	check_new_player(t_Server *server);
void	basic_init_server(t_Server *server);
void	take_linemate(int id, t_Server *server);
void	take_deraumere(int id, t_Server *server);
void	take_sibur(int id, t_Server *server);
void	take_mendiane(int id, t_Server *server);
void	take_phiras(int id, t_Server *server);
void	take_thystane(int id, t_Server *server);
t_Position	get_spaw_pos(t_Server *server);
void	init_inventaire(t_Player *player, t_Server *);
t_Player	*delete_player(t_Server *serv, t_Player *player);
void	 set_linemate(int id, t_Server *server);
void	set_deraumere(int id, t_Server *server);
void	set_sibur(int id, t_Server *server);
void	set_mendiane(int id, t_Server *server);
void	set_phiras(int id, t_Server *server);
void	set_thystane(int id, t_Server *server);
void	set_food(int id, t_Server *server);

#endif /* !ZAPPY_SERVER_H_ */
