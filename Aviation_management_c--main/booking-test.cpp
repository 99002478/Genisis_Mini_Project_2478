#include "Flight.h"
#include "passenger.h"
#include "Booking.h"
#include <gtest/gtest.h>
namespace {

class BookingTest : public ::testing::Test {

protected:
  void SetUp() { 
    trips.addReservation("Indigo","6E500", "Hyderabad", "Pune", "p101","PM","pm@gmail.com","9567876554", 350);
    trips.addReservation("Indigo","6E501","Bengaluru", "Pune", "p102","qM","qm@gmail.com","2567876554", 500);
    trips.addReservation("AirIndia", "AI850","Hyderabad", "Chennai","p104","dM","dm@gmail.com","7567876554", 400);
    trips.addReservation("Spicejet","SG301", "Mumbai", "Bengaluru","p105","eM","em@gmail.com","99567876554", 600);
    trips.addReservation("Spicejet","SG302","Bengaluru","Delhi", "p106","uM","um@gmail.com","59567876554", 1200);
    trips.addReservation("AirIndia", "AI900","Pune", "Bengaluru","p101","PM","pm@gmail.com","9967876554",  550);
  }
  void TearDown() {}
  Booking trips;
};

TEST_F(BookingTest, AddReservation) {
  trips.addReservation("Spicejet","SG304","Chennai","Delhi","p103","mM","mm@gmail.com","0567876554", 1300);
  EXPECT_NE((Flight*)NULL, trips.findFlightById("SG304"));
  EXPECT_EQ(7, trips.countAll());
}
TEST_F(BookingTest, RemoveReservation) {
  trips.removeReservation("6E501");
  EXPECT_EQ(NULL, trips.findFlightById("6E501"));
  EXPECT_EQ(5, trips.countAll());
}
TEST_F(BookingTest, CountTest) {             //Just After Setup
  EXPECT_EQ(6, trips.countAll());
}

TEST_F(BookingTest, CountByFlightTest) {  //Just After Setup
  int count = trips.countTripsByFlight("Indigo");
  EXPECT_EQ(2, count);
}
TEST_F(BookingTest, MaxFareTest) {           //Just After Setup
  double maxFare = trips.computeMaxFare();
  double minTime = trips.computeMinTravelTime();
  EXPECT_EQ(12000, maxFare);         //For trip with distance of 1200 miles
  EXPECT_EQ(42, minTime);            //For trip with distance of 350 miles   
}

TEST_F(BookingTest, AnotherTest) {         //Just After Setup
  trips.addReservation("Spicejet","SG308", "Chennai", "Delhi", "p121","PRM","prm@gmail.com","95667876554", 1300);
  trips.addReservation("AirIndia","AI848", "Chennai", "Bengaluru", "p1121","PPRM","pprm@gmail.com","85667876554", 200);
  int count = trips.countTripsByFlight("Spicejet");
  double maxFare = trips.computeMaxFare();
  double minTime = trips.computeMinTravelTime();
  EXPECT_EQ(8, trips.countAll());  
  EXPECT_EQ(3, count);  
  EXPECT_EQ(13000, maxFare);  
  EXPECT_EQ(24, minTime);  
}
}
/*
int main(int argc,char **argv)
{
	testing::InitGoogleTest(&argc,argv);
	return RUN_ALL_TESTS();
}*/
