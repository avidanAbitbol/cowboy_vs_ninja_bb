
#include "Team.hpp"
#include <stdexcept>
#include <algorithm>
#include <limits>

namespace ariel {
    // Constructor for Team class that takes a Character* argument
    Team::Team(Character *leader) {
        if (leader == nullptr) {
            throw std::runtime_error("The leader is null");
        }
        if (leader->getInGroup()) {
            throw std::runtime_error("The leader is already in a team");
        }
        //set the leader of the team in the vector
        this->leader = leader;
        team.push_back(leader);
        leader->setInGroup(true);
    }
    //check if the team is alive
    int Team::stillAlive() const {
        int count = 0;
        for (const auto &character: team) {
            if (character->isAlive()) {
                count++;
            }
        }
        return count;
    }
    //add a character to the team
    void Team::add(Character *character) {
        if (character == nullptr) {
            throw std::runtime_error("The character is null");
        }

        if (character->getInGroup()) {
            throw std::runtime_error("The character is already in a team");
        }

        if (team.size() >= 10) {
            throw std::runtime_error("The team is full");
        }

        character->setInGroup(true);
        team.push_back(character);

        std::sort(team.begin(), team.end(), [](Character *a, Character *b) {
            if (a->getIsNinja() && !b->getIsNinja()) {
                return true;
            }
            if (!a->getIsNinja() && b->getIsNinja()) {
                return false;
            }
            return a->getIsNinja() && b->getIsNinja();
        });
    }
    //attack function for the team
    void Team::attack(Team *enemyTeam) {
        if (enemyTeam == nullptr) {
            throw std::invalid_argument("Cannot attack a null team");
        }
        if(!enemyTeam->stillAlive()){
            throw std::runtime_error("The enemy team is dead");
        }
        if (!stillAlive() || !enemyTeam->stillAlive()) {
            return; // Return if either team is dead
        }
        if(!this->leader->isAlive()){
            this->setLeader(findClosestCharacters(this->leader, this->team)); // No team members left alive
        }
        Character *closestEnemy = nullptr;
        closestEnemy = findClosestCharacters(this->leader, enemyTeam->team);
        if(closestEnemy== nullptr){
            return;// No team members left alive
        }
        for(auto &character:team){
            if(character->isAlive()){
                if(!closestEnemy->isAlive()){
                    closestEnemy = findClosestCharacters(this->leader, enemyTeam->team);
                }
                if(closestEnemy== nullptr){
                    return;// No team members left alive
                }

                if(character->getIsNinja()) {
                    static_cast<Ninja*>(character)->damage(closestEnemy);
                }
                    // Check if character is a Cowboy and call shoot
                else if(!character->getIsNinja()) {
                    static_cast<Cowboy*>(character)->shoot(closestEnemy);
                }
            }
        }
    }
    //find the closest character
    Character* Team::findClosestCharacters(Character* fromCharacter, const std::vector<Character*>& team) const {
        Character* closestCharacter = nullptr;
        double closestDistance = std::numeric_limits<double>::max();

        for (const auto& character : team) {
            if (character != fromCharacter && character->isAlive()) {
                double distance = character->distance(fromCharacter);

                if (distance < closestDistance) {
                    closestDistance = distance;
                    closestCharacter = character;
                }
            }
        }

        return closestCharacter;
    }



    void Team::print()  {
        for (const auto &character: team) {
            character->print();
        }
    }

    Team::~Team() {
        for (auto &character: team) {
            delete character;
        }
    }

    Character *Team::getLeader() const {
        return leader;
    }
    //set the leader of the team
    void Team::setLeader(Character *leader) {
        if (leader != nullptr) {
            if (!leader->getInGroup()) {
                throw std::runtime_error("The leader is not part of this team");
            }
            this->leader = leader;
        }
    }

} // ariel
