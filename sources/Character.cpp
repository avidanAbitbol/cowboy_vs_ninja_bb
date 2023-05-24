#include <limits>
#include <vector>
#include <stdexcept>
#include <iostream>
#include "Character.hpp"

namespace ariel {
    // Constructor
    Character::Character(const std::string& name, const Point& location)
            : name(name), location(location), islive(true), inGroup(false), health(0) {}

    // Copy constructor
    Character::Character(const Character& other)
            : name(other.name), location(other.location), islive(other.islive), inGroup(other.inGroup), health(other.health) {}

    // Copy assignment operator
    Character& Character::operator=(const Character& other) {
        if (this != &other) {
            name = other.name;
            location = other.location;
            islive = other.islive;
            inGroup = other.inGroup;
            health = other.health;
        }
        return *this;
    }

    // Move constructor
    Character::Character(Character&& other) noexcept
            : name(std::move(other.name)), location(std::move(other.location)),
              islive(other.islive), inGroup(other.inGroup), health(other.health) {}

    // Move assignment operator
    Character& Character::operator=(Character&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            location = std::move(other.location);
            islive = other.islive;
            inGroup = other.inGroup;
            health = other.health;
        }
        return *this;
    }

    // Destructor
    Character::~Character() = default;
    std::string Character::getName() const {
        return name;
    }
    //setters for location
    void Character::setLocation(const Point location) {
        this->location = location;
    }
    //getters for location
    const Point Character::getLocation() const {
        return location;
    }
    //getters for islive bool
    bool Character::isAlive() const {
        return islive;
    }
    //distance between characters
    double Character::distance(const Character* p) const {
        //check if the character is null
        if (p == nullptr) {
            throw std::invalid_argument("Cannot compute distance to null Character");
        }
        //return the distance between the two characters
        return location.distance(p->getLocation());
    }
    //hit function for damage
    void Character::hit(int damage) {
        //check if the damage is negative
        if (damage < 0) {
            throw std::invalid_argument("Damage cannot be negative");
        }
        health -= damage;
        //check if the character is alive
        if (health <= 0) {
            islive = false;
        }
    }
    //getters for isNinja bool
    bool Character::getIsNinja() const {
        return isNinja;
    }
    //setters for isNinja bool
    void Character::setIsNinja(bool isNinja) {
        this->isNinja = isNinja;
    }

    //setters for health
    void Character::setHealth(int health) {
        this->health = health;
    }
    //getters for health
    int Character::getHealth() const {
        return health;
    }
        //setters for inGroup bool
    void Character::setInGroup(bool inGroup) {
        this->inGroup = inGroup;
    }
        //getters for inGroup bool
    bool Character::getInGroup() const {
        return inGroup;
    }
} // ariel