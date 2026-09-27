#include "Rental.h"
#include <iomanip>
using namespace std;
Rental::Rental(){
    rental_id=0;
    category=apartment;
    description="";
    maxPeople=1;
    price_per_day=1.0;
    reservationNum=0;

}
Rental::Rental(int rentalId, Category ca, string descript, int max_people, double price){
    rental_id=rentalId;
    category = ca ;
    description=descript;
    

    if(price<=0) price=1;
    if (max_people<1) max_people=1;

    maxPeople=max_people;
    price_per_day=price;

    reservationNum=0;//intial num;

}

int Rental::getRentalId() {
    return rental_id;
}

Category Rental::getCategory() {
    return category;
}

bool Rental:: addReservation(string name, int num_people, Date& check_in, Date& check_out){
    
    if (reservationNum>=MAX_ARRAY) return false; //cant add more reservations
    
    //check check in and check out times are accurate
    if (!check_in.lessThan(check_out)) return false;


    if (num_people<1||num_people>maxPeople)return false;

    //add a reservation to the reservation array 
    reservations[reservationNum]=Reservation(name, num_people, check_in, check_out);
    
    reservationNum++;
    //true if adding is successful false otherwise
    return true;

}

void Rental:: removeReservation(string name, Date& check_in){
    //remove a reservation from the reservation array if name matches
    //name of the reservation and the checkin Date matches the checkin Date of the reservation

    for (int i=0; i<reservationNum;i++){
        if (reservations[i].getName()==name && reservations[i].getCheck_in().equals(check_in)){
            //to remove i(the matchin reservation) move every element that comes after it to the left
            for(int j=i;j<reservationNum-1;j++){
                reservations[j]=reservations[j+1];
            }
            reservationNum--;
            return;
        }
    }

}

void Rental:: print(){
    cout << "Rental ID:     " << rental_id << endl;
    cout << "Category:      " << categoryToString(category) << endl;
    cout << "Description:   " << description << endl;
    cout << "Max People:    " << maxPeople << endl;
    cout << "Price per Day:    $" << fixed << setprecision(2) 
<< price_per_day << endl; //to get the exact num ex 10.00

    }
void Rental:: printReservations(){
    //print from earliest to latest(i did it b/c test failed):
    for (int i = 0; i < reservationNum - 1; i++) {
        for (int j = i+1; j < reservationNum; j++) {

            // If reservation j has an earlier check-in date than reservation i
            if (reservations[j].getCheck_in()
                    .lessThan(reservations[i].getCheck_in())) {

                // keep comparing between i and i+ untill its sorted
                Reservation temp = reservations[i];
                reservations[i] = reservations[j];
                reservations[j] = temp;}
                    }
    for(int i=0; i<reservationNum;i++){
        reservations[i].print();
    }
    }
}
void Rental:: printReservation(Date& date){
        for(int i=0; i<reservationNum;i++){
            //opposite to = or later is before check in &has to be before check out
            if (reservations[i].getCheck_in().equals(date)) {
                reservations[i].print();
            }

    }
}