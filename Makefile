all: a1
#link files -o and compile .cc and output a1 executable
a1: main.cc Tester.o Category.o Date.o Reservation.o Rental.o HomeShare.o
	g++ -o a1 main.cc Tester.o Category.o Date.o Reservation.o Rental.o HomeShare.o

Tester.o: Tester.cc Tester.h 
	g++ -c Tester.cc

Category.o: Category.cc Category.h
	g++ -c Category.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Reservation.o: Reservation.cc Reservation.h Date.h
	g++ -c Reservation.cc

Rental.o: Rental.cc Rental.h Reservation.h Category.h defs.h
	g++ -c Rental.cc

HomeShare.o: HomeShare.cc HomeShare.h Rental.h
	g++ -c HomeShare.cc

#remove a1 executable and all obj files
clean:
	rm -f a1 *.o