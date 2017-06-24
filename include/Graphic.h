/*
** Graphic.h for zappy in /home/alaism/dev/tek2/PSU/zappy/include/
**
** Made by Martin Alais
** Login   <martin.alais@epitech.eu>
**
** Started on  Thu Jun 22 15:51:04 2017 Martin Alais
** Last update Sat Jun 24 11:37:48 2017 Martin Alais
*/

#ifndef ZAPPY_GRAPHIC_H_
# define ZAPPY_GRAPHIC_H_

#include "zappy.h"

void commande_graphic(t_graphic *player, t_Server *server, char *data);
void commande_msz(t_graphic *player, t_Server *server, char *data);
void commande_sgt(t_graphic *player, t_Server *server, char *data);
void commande_bct2(t_Server *server, int x, int y, t_graphic *player);
void commande_tna(t_graphic *player, t_Server *server, char *data);
void commande_btc(t_graphic *player, t_Server *server, char *data);
void commande_mct(t_graphic *player, t_Server *server, char *data);
void commande_ppo(t_graphic *player, t_Server *server, char *data2);
void commande_plv(t_graphic *player, t_Server *server, char *data2);
void commande_pin(t_graphic *player, t_Server *server, char *data2);
void commande_sst(t_graphic *player, t_Server *server, char *data2);
void commande_smg(t_graphic *player, char *data);
void commande_smg_all(t_Server *server, char *data);
void commande_pnw(t_Server *server, t_Player *player, t_graphic *graphic);

#endif /* !ZAPPY_GRAPHIC_H_ */
