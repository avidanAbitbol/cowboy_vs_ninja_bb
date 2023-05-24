//
// Created by avida on 5/15/2023.
//
#include "Character.hpp"

#ifndef COWBOY_VS_NINJA_A_COWBOY_H
#define COWBOY_VS_NINJA_A_COWBOY_H

namespace ariel {

    class Cowboy: public Character {
        int bullets;
    public:
        Cowboy(const std::string& name, const Point& location);
        // Declare the deleted special member functions
        Cowboy(const Cowboy& other) = delete;
        Cowboy& operator=(const Cowboy& other) = delete;
        Cowboy(Cowboy&& other) = delete;
        Cowboy& operator=(Cowboy&& other) = delete;
        string print()override;
        bool hasboolets();
        void reload();
        void shoot(Character *wasShot);
        ~Cowboy()override = default;
        void damage(Character *character)override;
    };

} // ariel

#endif //COWBOY_VS_NINJA_A_COWBOY_H
