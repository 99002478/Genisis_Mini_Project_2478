#include"passenger.h"

Passenger:: Passenger():
 Flight(){
     PID="";
     P_name="";
     email="";
     phno="";
  }

Passenger:: Passenger(std::string flname,std::string flid,std::string src ,std::string dest,std::string id,std::string name ,std::string em, std::string pn ,double dis):
Flight(flname,flid,src,dest,dis) {
     PID=id;
     P_name=name;
     email=em;
     phno=pn;
 }

//Operations
 double Passenger:: computeFare()  {
 return (distance * mile_rateINR);
 }

 double Passenger:: computeTravelTime() {
  double temp = static_cast<double> (distance) /SpeedInHr;
  return temp * 60;
 }

//getters
std:: string Passenger:: getid(){
  return PID;
}
std:: string Passenger:: getname(){
    return P_name;
}
std:: string Passenger:: getemail(){
  return email;
}
std:: string Passenger:: getphno(){
  return phno;
}
std:: string Passenger::getflight_name(){
return fl_name;
}
std:: string Passenger::getflight_id(){
return fl_id;
}
std:: string  Passenger::getOrigin(){
return src_city;
}
std:: string Passenger::getDestination(){
return dest_city;
}
double Passenger::getDistance(){
return distance;
}