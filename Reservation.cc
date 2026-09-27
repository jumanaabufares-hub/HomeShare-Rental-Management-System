#include "Reservation.h"

    Reservation::Reservation(){
        name="";
        num_people=0;
    }

    Reservation::Reservation(string n, int numPeople, Date& checkIn, Date& checkOut){
        name=n;
        num_people=numPeople;
        check_in=checkIn;
        check_out=checkOut;

    } 


    string Reservation:: getName(){
        return name;
    }
    Date& Reservation::getCheck_in(){
        return check_in;
    }
    Date& Reservation::getCheck_out(){
        return check_out;
    }
    int Reservation::getNum_people(){
        return num_people;
    }
    
    void Reservation::print(){
        cout<<"reservation made by: "<<getName()<<", for "
        <<getNum_people()<< " people. check in date: ";
        getCheck_in().print(); 
        cout<< " check out date: ";
        getCheck_out().print();
        cout<< "." << endl;
    }