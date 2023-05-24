//
// Created by avida on 5/15/2023.
//
#include "Character.hpp"
#include <string>

#ifndef COWBOY_VS_NINJA_A_NINJA_H
#define COWBOY_VS_NINJA_A_NINJA_H

namespace ariel {

    class Ninja : public Character {
        int speed;

    public:
        Ninja(const std::string& name, const Point& location);
        // Declare the deleted special member functions
        Ninja(const Ninja& other) = delete;
        Ninja& operator=(const Ninja& other) = delete;
        Ninja(Ninja&& other) = delete;
        Ninja& operator=(Ninja&& other) = delete;
        void move(const Character *player);
        void slash(Character *other);
        string print()override;
        ~Ninja()override = default;
        void setSpeed(int speed);
        const int getSpeed() const;
        void damage(Character *character)override;
    };

} // ariel

#endif //COWBOY_VS_NINJA_A_NINJA_H
