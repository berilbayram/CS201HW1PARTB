//
// Created by berilbayram on 2.11.2019.
//

#include "FC.h"
using namespace std;

FC::FC() {
    noOfFilms = 0;
    films = new Film[noOfFilms];
}

FC::FC(const FC &fcToCopy) {
        noOfFilms = fcToCopy.noOfFilms;
        films = new Film[noOfFilms];
        for(unsigned int i = 0; i < noOfFilms; i++) {
            films[i] = fcToCopy.films[i];
        }
}

FC::~FC() {
    noOfFilms = 0;
    delete[] films;
}

void FC::operator=(const FC &right) {
        noOfFilms = right.noOfFilms;
        films = new Film[noOfFilms];
        if ( &right != this ) {
            for (unsigned int i = 0; i < noOfFilms; i++){
                films[i] = right.films[i];
            }
        }
}

unsigned int FC::getFilms(Film *&allFilms) const {
    allFilms = new Film[noOfFilms];
    for(int i = 0; i < noOfFilms; i++){
        allFilms[i] = films[i];
    }
    return noOfFilms;
}


bool FC::addFilm(const string fTitle, const string fDirector, const unsigned int fYear, const unsigned int fDuration) {
    Film* tempFilms = new Film[noOfFilms + 1];
    for(unsigned int i = 0; i < noOfFilms; i++) {
        tempFilms[i] = films[i];
    }
    Film* tempFilm = new Film(fTitle,fDirector,fYear,fDuration);
    tempFilms[noOfFilms] = *tempFilm;
    Actor* tempActors = new Actor[0];

    tempFilms[noOfFilms].setActors(tempActors);
    for(unsigned int i = 0; i < noOfFilms; i++) {
        if (films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector ) {
            delete tempFilm;
            delete[] tempFilms;
            return false;
        }
    }
    noOfFilms++;
    delete[] films;
    films = new Film[noOfFilms];
    for(unsigned int i = 0; i < noOfFilms; i++){
        films[i] = tempFilms[i];
    }
    delete tempFilm;
    delete[] tempFilms;
    return true;
}


bool FC::addActor(const string fTitle, const string fDirector, const string aName, const string aBirthPlace,
                  const unsigned int aBirthYear) {
    bool doesActorExist;
    Actor* tempActor = new Actor(aName,aBirthPlace,aBirthYear);
    for (unsigned int i = 0; i < noOfFilms; i++){
        if (films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector){
            doesActorExist = films[i].doesActorExist(aName);
            if (doesActorExist) {
                return false;
            } else{
                films[i].addActors(tempActor);
                delete tempActor;
                return true;
            }
        }
    }
    return false;
}

bool FC::removeActors(const string fTitle, const string fDirector) {
    for(unsigned int i = 0; i < noOfFilms; i++){
        if (films[i].getFilmDirector() == fDirector && films[i].getFilmDirector() == fDirector){
            films[i].deleteActors();
            return true;
        }
    }
    return false;
}

bool FC::removeFilm(const string fTitle, const string fDirector) {
        for(unsigned int i = 0; i < noOfFilms; i++ ){
            if(films[i].getFilmTitle() == fTitle && films[i].getFilmDirector() == fDirector){
                Film* delFilm = new Film("","",0,0);
                films[i] = *delFilm;
                Film* tempFilms = new Film[noOfFilms - 1];
                unsigned int j = 0;
                for(unsigned int i = 0; i < noOfFilms; i++){
                    if (films[i].getFilmTitle() != "" || films[i].getFilmDirector() != ""){
                        tempFilms[j] = films[i];
                        j++;
                    }
                }
                noOfFilms--;
                delete[] films;
                films = new Film[noOfFilms];
                for(unsigned int i = 0; i < noOfFilms; i++){
                    films[i] = tempFilms[i];
                }
                delete delFilm;
                delete[] tempFilms;
                return true;
            }
        }
        return false;
}

unsigned int FC::calculateAverageDuration() const {
    unsigned int average = 0;
    unsigned int sum = 0;
    if (noOfFilms != 0){
        for(unsigned int i = 0; i < noOfFilms; i++){
            sum = sum + films[i].getFilmDuration();
        }
        average = sum/noOfFilms;
    }
    return average;
}



