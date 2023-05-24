//
// Created by avida on 5/15/2023.
//
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include <vector>
#include <string>

#ifndef COWBOY_VS_NINJA_A_TEAM_H
#define COWBOY_VS_NINJA_A_TEAM_H

namespace ariel {

    class Team {
    public:
        Character* leader;
        std::vector<Character*> team;
        Team(Character* leader); // Constructor
        Team(const Team&) = delete; // Declare the deleted special member functions
        Team& operator=(const Team&) = delete;
        Team(Team&&) = delete;
        Team& operator=(Team&&) = delete;
        virtual ~Team();

        virtual void add(Character* character);
        int stillAlive() const;
        virtual void attack(Team* enemyTeam);
        void print();
        Character* getLeader() const;
        void setLeader(Character* leader);
        Character* findClosestCharacters(Character* fromCharacter, const std::vector<Character*>& team) const;
    };

}; // ariel

#endif //COWBOY_VS_NINJA_A_TEAM_H
