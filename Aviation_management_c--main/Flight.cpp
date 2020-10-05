#include "Flight.h"

//Construtor
Flight::Flight(): fl_name(""),fl_id(""),src_city(""),dest_city(""),distance(0.0){}
Flight::Flight(std::string flname,std::string flid,std::string src,std::string dest,double dis):
 fl_name(flname),
 fl_id(flid),
 src_city(src),
 dest_city(dest),
 distance(dis){}


 // Getters

 //Operations
 double Flight:: computeFare()  {
 return (distance * mile_rateINR);
 }

 double Flight:: computeTravelTime()  {
 double temp = static_cast<double> (distance) /SpeedInHr;
 return temp * 60;
 }

std:: string Flight::getflight_name(){
return fl_name;
}
std:: string Flight::getflight_id(){
return fl_id;
}
std:: string  Flight::getOrigin(){
return src_city;
}
std:: string Flight::getDestination(){
return dest_city;
}
double Flight::getDistance(){
return distance;
}
