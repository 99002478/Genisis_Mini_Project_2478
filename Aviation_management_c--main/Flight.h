#ifndef __FLIGHT_H
#define __FLIGHT_H

#include<string>

const double mile_rateINR = 10.0;
const double SpeedInHr = 500;

class Flight{
protected :

std::string fl_name;
std::string fl_id;
std::string src_city;
std::string dest_city;
double distance;   

public:
// Constructors
Flight();
Flight(std::string,std::string,std::string,std::string,double);

//Operations
virtual double computeFare() ;
virtual double computeTravelTime() ;

// Getters
 virtual std::string getflight_name();
 virtual std::string getflight_id();
 virtual std:: string getOrigin();
 virtual std:: string getDestination();
 virtual double getDistance();

}; // Class ending


#endif
