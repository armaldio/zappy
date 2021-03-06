//
//-----------------------------------------------------------------------------
//Filename:    Egg.hpp
//-----------------------------------------------------------------------------
//
// Created by bonett_w on 6/26/17.
//-----------------------------------------------------------------------------
//

#ifndef CLIENTQT_EGG_HPP
#define CLIENTQT_EGG_HPP


#include <SFML/System.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Player.hpp"

namespace zappy {
    class Egg {
    private:
        std::string _team;
        sf::Vector2f _pos;
        unsigned int _id;
        Player *_player;
        bool _isHatch;

    public:
        // GUI
        sf::RectangleShape corpShape;

    public:
        Egg(unsigned int id, Player * player, int x, int y);

        virtual ~Egg();

        const sf::Vector2f &getPosition() const;

        void setPosition(const sf::Vector2f &_pos);

        unsigned int getId() const;

        void setId(unsigned int _id);

        Player * getPlayer() const;

        void setPlayer(Player *player);

        const bool isHatch() const;

        void setHatches(bool value);

        const std::string &getTeamName() const;

    };
}

#endif //CLIENTQT_EGG_HPP
