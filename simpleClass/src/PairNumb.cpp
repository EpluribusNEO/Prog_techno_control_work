#include "PairNumb.h"
#include <string>
#include <cstdio>

PairNumb::PairNumb():name("Noname"), first(0),second(0){}

PairNumb::PairNumb(std::string name, int first, int second){
    this->name = name;
    this->first = first;
    this->second = second;
}

PairNumb::~PairNumb(){
     std::printf("\t%s deleted!\n",this->name.c_str());
}

void PairNumb::selfPrint(){
    std::printf("%s (%d, %d)\n",
                this->name.c_str(), this->first, this->second);
}

/* Гетеры */
std::string PairNumb::getName(){ return this->name; }
int PairNumb::getFirst(){ return this->first; }
int PairNumb::getSecond(){ return this->second; }
/* Гетеры */

/* Сеттеры */
void PairNumb::setName(std::string name){ this->name = name; }
void PairNumb::setFirst(int first){ this->first = first; }
void PairNumb::setSecond(int second){ this->second = second;}
/* /Сеттеры */

PairNumb PairNumb::operator+(const PairNumb& right){
    std::string nm = name + "_" + right.name;
    int frst = first + right.first;
    int scnd = second + right.second;
    PairNumb result(nm, frst, scnd);
    return result;
}
