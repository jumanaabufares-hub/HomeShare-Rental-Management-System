#ifndef HOMESHARE_H

#define HOMESHARE_H


#include <iostream>
#include <string>
#include "Rental.h"
#include "defs.h"

class HomeShare{
    private:
        Rental rentals[MAX_ARRAY];
        int rentalsNum;

    public:
        HomeShare();
        
        void addRental(int rental_id, Category category, string description, int maxPeople, double price_per_day);

        void removeRental(int rental_id);

        void addReservation(int rental_id, string name, int num_people, Date& check_in, Date& check_out);

        void removeReservation(int rental_id, string name, Date& checkin);

        void printRentals();

        void printReservations(int rental_id);
        void printReservations(Date& date);

        void printRentalsByCategory(Category category);

};



#endif