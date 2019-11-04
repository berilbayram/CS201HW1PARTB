//
// Created by berilbayram on 2.11.2019.
//

#include "Actor.h"

Actor::Actor(string aName, string aBirthPlace, const unsigned int aBirthYear) {
    name = aName;
    birthYear = aBirthYear;
    birthPlace = aBirthPlace;
}

Actor::Actor(const Actor &actorToCopy) {
    name = actorToCopy.name;
    birthPlace = actorToCopy.birthPlace;
    birthYear = actorToCopy.birthYear;
}

Actor::~Actor() {
}

void Actor::operator=(const Actor &right) {
    name = right.name;
    birthYear = right.birthYear;
    birthPlace = right.birthPlace;
}
ostream& operator<<(ostream &out, const Actor &a) {
    out << a.name << ", " << a.birthPlace << ", " << a.birthYear << endl;
}

string Actor::getBirthPlace() const {
    return birthPlace;
}

string Actor::getName() const {
    return name;
}

unsigned int Actor::getBirthYear() const {
    return birthYear;
}

