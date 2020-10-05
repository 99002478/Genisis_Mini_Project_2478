#include "Flight.h"
#include "passenger.h"
#include <list>
#include <iterator>
using namespace std;
#include <bits/stdc++.h>
#include <gtest/gtest.h>
namespace {

class FlightTest : public ::testing::Test {

protected:
  void SetUp() { // override {
    //ptr = new Passenger("Indigo","6E123","Mumbai","Delhi","p1011","PPM","ppm@gmail.com","8765432345",800);
    std::list<string> res;
		     		std::list<string> ::iterator iter;
		     		//std::string state,district,season,crop;
		     		//double area,production;
		     		//int year;
            std::string flname,flid,src,dest,id,name,em,ph;
		     		double dist;
		    		std::string S, T;
		    		fstream fin;
		    		int count=1;
		    		fin.open("Flight.csv", ios::in);
		    		while(getline(fin, S))
		    		{
		    			stringstream X(S);
		    			while (getline(X, T,'\n'))
		   			 {
		   	 			res.push_back(T);
		    			 }
		   	        }
		    		iter=res.begin();
		   		 ++iter;
		    		for(;iter!=res.end();++iter)
		    		{
		    			stringstream ss(*iter); 
		    			while (ss.good()) 
		    			{ 
						string substr; 
						getline(ss, substr, ','); 
						//cout<<substr<<"  ";
						switch(count)
						{
							case 1:
								flname=substr;
								break;
							case 2:
								flid=substr;
								break;
							case 3:
								src=substr;
								break;
							case 4:
								dest=substr;
								break;
							case 5:
								id=substr;
								break;
							case 6:
								name=substr;
								break;
							case 7:
								em=substr;
              case 8:
								ph=substr;
              case 9:
								dist=std::stod(substr);
								ptr = new Passenger(flname,flid,src,dest,id,name,em,ph,dist); {
  							flname="";flid="";src="";dest="";id="";name="";em="";ph="";
								count=0;dist=0.0;
								break;
						
						}
						++count;
						
		    			} 
		  		}
            }
  }
  void TearDown() {
    delete ptr;
  }
  Flight *ptr;
};
//"Indigo","6E500", "Hyderabad", "Pune", "p101","PM","pm@gmail.com","9567876554", 350
TEST_F(FlightTest, DefaultConstructor) {
  Passenger ft;
  EXPECT_EQ(0, ft.getflight_name().length());
  EXPECT_EQ(0, ft.getflight_id().length());
  EXPECT_EQ(0, ft.getOrigin().length());
  EXPECT_EQ(0, ft.getDestination().length());
  EXPECT_EQ(0, ft.getid().length());
  EXPECT_EQ(0, ft.getname().length());
  EXPECT_EQ(0, ft.getemail().length());
  EXPECT_EQ(0, ft.getphno().length());
  EXPECT_EQ(0, ft.getDistance());
}

TEST_F(FlightTest, ParameterizedConstructor) {
  Passenger *fptr = dynamic_cast<Passenger*>(ptr);
  EXPECT_STREQ("Indigo", fptr->getflight_name().c_str());
  EXPECT_STREQ("6E123", fptr->getflight_id().c_str());
  EXPECT_STREQ("Mumbai", fptr->getOrigin().c_str());
  EXPECT_STREQ("Delhi", fptr->getDestination().c_str());
  EXPECT_STREQ("p1011", fptr->getid().c_str());
  EXPECT_STREQ("PPM", fptr->getname().c_str());
  EXPECT_STREQ("ppm@gmail.com", fptr->getemail().c_str());
  EXPECT_STREQ("8765432345", fptr->getphno().c_str());
  EXPECT_EQ(800, fptr->getDistance());
}
TEST_F(FlightTest, ComputationTest) {
  EXPECT_EQ(8000, ptr->computeFare());      //800 * 10, INR 10 for each mile
  EXPECT_EQ(96, ptr->computeTravelTime());  //96 mins, if speed in 500 miles per hr
}

TEST_F(FlightTest, AnotherTest) {
  Passenger ft("SpiceJet","SG401","Bengaluru", "Chennai","p1211","PQM","pQm@gmail.com","87965432345",200);
  Flight *pt = &ft;
  EXPECT_STREQ("SpiceJet", ft.getflight_name().c_str());
  EXPECT_STREQ("SG401", ft.getflight_id().c_str());
  EXPECT_STREQ("Bengaluru", ft.getOrigin().c_str());
  EXPECT_STREQ("Chennai", ft.getDestination().c_str());
  EXPECT_STREQ("p1211", ft.getid().c_str());
  EXPECT_STREQ("PQM", ft.getname().c_str());
  EXPECT_STREQ("pQm@gmail.com", ft.getemail().c_str());
  EXPECT_STREQ("87965432345", ft.getphno().c_str());
  EXPECT_EQ(200, ft.getDistance());
  EXPECT_EQ(2000, pt->computeFare());        //200 * 10 = 2000
  EXPECT_EQ(24, pt->computeTravelTime());    //24 mins, if speed is 500 miles per hr
}
} // namespace

int main(int argc, char **argv) 
        {
            testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        }
