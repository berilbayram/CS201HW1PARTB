//
// Created by berilbayram on 2.11.2019.
//

#include "Film.h"
using namespace std;


Film::Film(string fTitle, string fDirector, const unsigned int fYear, const unsigned int fDuration) {
    noOfActors = 0;
    title = fTitle;
    director = fDirector;
    year = fYear;
    duration = fDuration;
    actors = NULL;
}

void Film::setActors(Actor* actorsTemp)  {
    actors = new Actor[noOfActors];
    actors = actorsTemp;
}

void Film::deleteActors()  {
    delete[] actors;
    noOfActors = 0;
}

Film::Film(const Film &fToCopy) {
    noOfActors = fToCopy.noOfActors;
    title = fToCopy.title;
    duration = fToCopy.duration;
    year = fToCopy.year;
    director = fToCopy.director;
    actors = new Actor[noOfActors];
    for(unsigned int i = 0; i < noOfActors; i++){
        actors[i] = fToCopy.actors[i];
    }
}

void Film::operator=(const Film &right) {
    title = right.title;
    duration = right.duration;
    year = right.year;
    director = right.director;
    noOfActors = right.noOfActors;
    actors = new Actor[noOfActors];
    if ( &right != this ) {
        for (unsigned int i = 0; i < noOfActors; i++){
            actors[i] = right.actors[i];
        }
    }
}

void Film::getActors(Actor*& a) const {
    a = actors;
}

Film::~Film() {
   delete[] actors;
}

unsigned int Film::calculateAverageActorAge() const {
    unsigned int average = 0;
    unsigned int sum = 0;
    if(noOfActors != 0){
        for(unsigned int i = 0; i < noOfActors; i++){
            sum = sum + (year - actors[i].getBirthYear());
        }
        average = sum / noOfActors;
    }
    return average;
}

unsigned int Film::getNoOfActors() {
    cout<<noOfActors << endl;
    return noOfActors;
}

ostream& operator<<(ostream &out, const Film &f) {
    out << f.title << ", " << f.year << ", " << f.director << ", " << f.duration << " min" << endl;
    for(unsigned int i = 0; i < f.noOfActors; i++){
        out << "\t" << f.actors[i];
    }
    return out;
}
string Film::getFilmDirector() const {
    return director;
}

unsigned int Film::getFilmDuration() const {
    return duration;
}

string Film::getFilmTitle() const {
    return title;
}

bool Film::doesActorExist(string name) {
    for (unsigned int i = 0; i < noOfActors; i++){
        if (actors[i].getName() == name){
            return true;
        }
    }
    return false;
}

void Film::addActors(Actor* actor) {
    Actor* tempActor = new Actor(actor->getName(),actor->getBirthPlace(),actor->getBirthYear());
    Actor* tempActors = new Actor[noOfActors + 1];
    for(unsigned int i = 0; i < noOfActors; i++){
        tempActors[i] = actors[i];
    }
    tempActors[noOfActors] = *tempActor;
    noOfActors++;
    delete[] actors;
    actors = new Actor[noOfActors];
    for(unsigned int i = 0; i < noOfActors; i++){
        actors[i] = tempActors[i];
    }
    delete tempActor;
    delete[] tempActors;
}



unsigned int Film::getFilmYear() const {
    return year;
}