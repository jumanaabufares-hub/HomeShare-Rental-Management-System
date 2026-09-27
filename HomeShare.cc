#include "HomeShare.h"

using namespace std;

HomeShare::HomeShare() {
    rentalsNum = 0;
}


void HomeShare:: addRental(int rental_id, Category category, string description, int maxPeople, double price_per_day){

    //if theres room in rental arr 
    if(rentalsNum>= MAX_ARRAY) {
        cout<<"full, no room available."<<endl;
            return; //to stop
            }

     //check if rental id already exists
    for (int i = 0; i < rentalsNum; i++){
        if (rentals[i].getRentalId()==rental_id){
             cout<<"failed to add rental, Id already exists."<<endl;
            return;
            }
    }

    //add rental to back of array
        rentals[rentalsNum] = Rental(rental_id, category, description, maxPeople, price_per_day);
            rentalsNum++;
            //print wether successful or not
            cout<<"Rental is successfully added."<<endl;
        }

void HomeShare:: removeRental(int rental_id){
    // If there is a Rental with the given rental id, remove it from arr
    for (int i = 0; i < rentalsNum; i++) {
        if (rentals[i].getRentalId() == rental_id) {

            for (int j = i; j < rentalsNum - 1; j++) {
                rentals[j] = rentals[j + 1]; //remove arr and move to the left
            }

            rentalsNum--;
            cout << "Rental is successfully removed." << endl;
            return;
        }
    }
    cout<<"no rental with this id found"<<endl;


}

void HomeShare::addReservation(int rental_id, string name, int num_people, Date& check_in, Date& check_out){
    // Find a Rental with the given rental id 
    for (int i = 0; i < rentalsNum; i++) {
        if (rentals[i].getRentalId() == rental_id) {
    
            //add Reservation with the parameters to rental
            if (rentals[i].addReservation(name, num_people, check_in, check_out)){
            cout << "Reservation is successfully added." << endl;
            return;}
            else{
                cout<<"failed to add reservation;"<<endl;
                return;
                
            }
        }
    }
    cout<<"no rental with this id found"<<endl;

}

void HomeShare::removeReservation(int rental_id, string name, Date& checkin){
    //remove Reservation under given name with matching checkin Date from Rental with given number
    for (int i = 0; i < rentalsNum; i++) {

        if (rentals[i].getRentalId() == rental_id)//void Rental:: removeReservation(...)already checks for name and check in

         {

            rentals[i].removeReservation(name, checkin);
            cout << "Reservation removed." << endl;
            return;}
        }
    cout<<"failed to remove reservation, no rental with this id found."<<endl;
}

void HomeShare:: printRentals(){
    //print all Rentals managed by HomeShare
    for (int i = 0; i < rentalsNum; i++) {
        rentals[i].print();
    }

}

void HomeShare:: printReservations(int rental_id){
     //all Reservations at the Rental with the given rental id
    for (int i = 0; i < rentalsNum; i++) {
        if (rentals[i].getRentalId() == rental_id) {
            rentals[i].printReservations();
            return;}

    }
    cout << "no rental with this ID found." << endl;

}

void HomeShare:: printReservations(Date& date){
            //all Reservations on any Rental on the given date
    for (int i = 0; i < rentalsNum; i++) {
    rentals[i].printReservation(date);}
        }

void HomeShare:: printRentalsByCategory(Category category){
    // print all Rentals in the given category
    for (int i = 0; i < rentalsNum; i++) {
        if (rentals[i].getCategory() == category) {
            rentals[i].print();}
        }
}


