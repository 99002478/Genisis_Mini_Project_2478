all: all.out 
all.out : Flight.o passenger.o Booking.o flight-test.o booking-test.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
booking-test.o: booking-test.cpp Flight.h passenger.h Booking.h
	g++ $< -c
flight-test.o: flight-test.cpp Flight.h passenger.h
	g++ $< -c
Booking.o : Booking.cpp Booking.h passenger.h Flight.h
	g++ $< -c
Passenger.o : passenger.cpp passenger.h Flight.h
	g++ $< -c    
Flight.o : Flight.cpp Flight.h
	g++ $< -c
clean:
	rm -rf *.o *.out
