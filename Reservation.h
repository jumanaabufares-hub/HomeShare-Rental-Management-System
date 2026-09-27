#ifndef RESERVATION_H
#define RESERVATION_H
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Reservation{
    private:
        string name;
        int num_people;

        Date check_in;
        Date check_out;

    public:
    //ctor:
    Reservation();
    Reservation(string name, int num_people, Date& check_in, Date& check_out);

    //getters for rental class:
    string getName();
    Date& getCheck_in();
    Date& getCheck_out();
    int getNum_people();
    
    void print();//all classes need print 


};


#endif 