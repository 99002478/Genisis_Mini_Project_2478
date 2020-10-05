#include "Booking.h"
#include "passenger.h"

#include <list>
#include <iterator>

bool Booking::addReservation(std::string flname,std::string flid,std::string src ,std::string dest,std::string id,std::string name ,std::string em, std::string pn ,double dis)
{	
	pass.push_back(Passenger(flname, flid, src , dest, id, name , em,  pn , dis));
	return true;
}


bool Booking::removeReservation(std::string flightNumber)
{
	std::list<Passenger> :: iterator iter;

   	for(iter=pass.begin();iter!=pass.end();iter++)
    	{
        	if(iter->getflight_id()== flightNumber)
        	{
           	pass.erase(iter);
           	return true;
        	}
    	}
    	return false;
	
}

Passenger* Booking::findFlightById(std::string flight_id)
{
	std::list<Passenger> :: iterator iter;

   	for(iter=pass.begin();iter!=pass.end();iter++)
    	{
        	if(iter->getflight_id()== flight_id)
        	{
           		return &(*iter);
        	}
    	}
    	return NULL;
}

int Booking::countAll()
{
	return pass.size();
}

double Booking::computeMaxFare()
{
	std::list<Passenger> :: iterator iter= pass.begin();
	double maxFair=iter->computeFare();

   	for(;iter!=pass.end();iter++)
    	{
        	 if(maxFair < iter->computeFare())
        	{
            		maxFair = iter->computeFare();
        	}	

    	}
	return maxFair;
}

double Booking::computeMinTravelTime()
{
	std::list<Passenger> :: iterator iter= pass.begin();
	double minTravelTime =iter->computeTravelTime();

   	for(;iter!=pass.end();iter++)
    	{
        	 if(minTravelTime > iter->computeTravelTime())
        	{
            		minTravelTime = iter->computeTravelTime();
        	}	

    	}
	return minTravelTime;
}

int Booking::countTripsByFlight(std::string flname)
{
	std::list<Passenger> :: iterator iter;
	int countTrips=0;

   	for(iter=pass.begin();iter!=pass.end();iter++)
    	{
        	if(iter->getflight_name()== flname)
        	{
           		++countTrips;
        	}
    	}
    	return countTrips;
}

  	







