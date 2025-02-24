#ifndef __ACTOR_H
#define __ACTOR_H
#include <string>
using namespace std;
#include <iostream>
class Actor{
public:
    Actor(const string aName = "", const string aBirthPlace = "",
          const unsigned int aBirthYear = 0);
    Actor(const Actor &actorToCopy);
    ~Actor();
    void operator=(const Actor &right);
    string getName() const;
    string getBirthPlace() const;
    unsigned int getBirthYear() const;
    friend ostream& operator<<(ostream& out, const Actor& a);
private:
    string name;
    string birthPlace;
    unsigned int birthYear;
};
#endif