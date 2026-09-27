#ifndef RENTAL_H

#define RENTAL_H


#include <iostream>
#include <string>
#include "Reservation.h"
#include "Category.h"
#include "defs.h"

using namespace cat;//for category 

class Rental{
    private:
        int rental_id;
        Category category;
        string description;
        int maxPeople;
        double price_per_day;

        Reservation reservations[MAX_ARRAY];
        int reservationNum;

    public:
        Rental();//i added it for arr
        Rental(int rental_id, Category category, string description, int maxPeople, double price_per_day);

        //getters for array
        int getRentalId();
        Category getCategory();

        bool addReservation(string name, int num_people, Date& check_in, Date& check_out);
        void removeReservation(string name, Date& check_in);

        void print();
        void printReservations();
        void printReservation(Date& date);


};


#endif 

