#ifndef BOOKING_H_INCLUDED
#define BOOKING_H_INCLUDED
#include "Flight.h"
#include "passenger.h"
#include <list>

class Booking
{
	std::list<Passenger> pass;
  public:
 	bool addReservation(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string, double);
    	bool removeReservation(std::string);
    	Passenger* findFlightById(std::string);
    	int countAll();
    	double computeMaxFare();
    	double computeMinTravelTime();
    	int countTripsByFlight(std::string);
  	
};

#endif
