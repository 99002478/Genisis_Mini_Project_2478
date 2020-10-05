#ifndef __PASSENGER_H
#define __PASSENGER_H

#include<string>
#include"Flight.h"


class Passenger: public Flight{
 protected:
 std::string PID;
 std::string P_name;
 std::string email;
 std::string phno;

 public:
 // Constructor
 Passenger();
 Passenger(std::string ,std::string,std::string ,std::string ,std::string ,std::string,std::string,std::string,double);

//Operations
 double computeFare() ;
 double computeTravelTime() ;

//getters
 std:: string getid();
 std::string getname();
 std::string getemail();
 std::string getphno();
 std::string getflight_name();
 std::string getflight_id();
 std:: string getOrigin();
 std:: string getDestination();
 double getDistance();
};

#endif
