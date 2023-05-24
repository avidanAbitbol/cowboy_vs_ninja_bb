//
// Created by avida on 5/15/2023.
//
#include <stdexcept>

#include "Cowboy.hpp"

namespace ariel {
    Cowboy::Cowboy(const string &name, const Point &location) : Character(name, location) {
        setIsNinja(false) ;
        bullets = 6;
        setHealth(110);
    }
    string Cowboy::print(){
        if(!isAlive()){
            return "X"+getName()+" is dead";
        }
        return "C"+getName()+ "-" + to_string(getHealth() ) + " is at "+getLocation().print();
    }
    //check if the cowboy has bullets
    bool Cowboy::hasboolets(){
        return bullets > 0;
    }
    //reload the cowboy
    void Cowboy::reload() {
        if (!this->isAlive()) {
            throw std::runtime_error("you can't reload if you are dead");
        }
        bullets = 6;
    }
    //shoot with the cowboy
    void Cowboy::shoot(Character *wasShot) {
        if (this == wasShot) {
            throw std::runtime_error("you can't shoot yourself");
        }
        if (!wasShot->isAlive()) {
            throw std::runtime_error("the character is dead");
        }
        if (!this->isAlive()) {
            throw std::runtime_error("you can't shoot if you are dead");
        }
        //check if the cowboy has bullets
        if (hasboolets()) {
            bullets--;
            wasShot->hit(10);
        } else {
            reload();
        }
    }
    //didnt use it
    void Cowboy::damage(Character *character) {
    }

} // ariel