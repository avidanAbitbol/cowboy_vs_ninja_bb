#include "Point.hpp"
#include <vector>
#include <string>
#ifndef COWBOY_VS_NINJA_A_CHARACTER_H
#define COWBOY_VS_NINJA_A_CHARACTER_H

namespace ariel {

    class Character {
        Point location;
        bool islive;
        std::string name;
        int health;
        bool isNinja;
        bool inGroup;

    public:
        Character(const std::string& name, const Point& location);
        Character(const Character& other); // Copy constructor
        Character& operator=(const Character& other); // Copy assignment operator
        Character(Character&& other) noexcept; // Move constructor
        Character& operator=(Character&& other) noexcept; // Move assignment operator
        virtual ~Character(); // Destructor

        std::string getName() const;
        void setLocation(Point location);
        const Point getLocation() const;
        bool isAlive() const;
        double distance(const Character* player) const;
        void hit(int damage);
        virtual std::string print() = 0;
        bool getIsNinja() const;
        void setIsNinja(bool isNinja);
        virtual void damage(Character* enemy) = 0;
        void setHealth(int health);
        int getHealth() const;
        void setInGroup(bool inGroup);
        bool getInGroup() const;
    };

} // ariel

#endif //COWBOY_VS_NINJA_A_CHARACTER_H
