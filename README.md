# HomeShare-Rental-Management-System
HomeShare Rental Management System is a backend rental management system that manages rental properties and their reservations. It allows users to add and remove rentals, display rental information, and view reservations. The system also uses categories and dates to organize rental information and manage reservation check-in and check-out dates.

# Files and Descriptions
Category.h / Category.cc — Defines rental categories and converts category values to strings.

Date.h / Date.cc — Stores date information and helps manage reservation check-in and check-out dates.

defs.h — Defines constants, including the maximum array sizes used by the rental system.

Tester.h / Tester.cc — Contains functions used to test the backend functionality.

Rental.h / Rental.cc — Stores information about a rental unit and its array of reservations.

Reservation.h / Reservation.cc — Stores information about a rental reservation.

HomeShare.h / HomeShare.cc — Manages the collection of rentals and provides functionality to add, remove, and display rentals and reservations.

main.cc — Contains the main function and starts the program.

Makefile — Contains the commands needed to compile and link the source files into the a1 executable.

# Compilation and Execution
The program is compiled and linked using a Makefile. The .cc source files are compiled into .o object files, which are then linked together to create the a1 executable.

To compile and run the program:

make clean
make
./a1
