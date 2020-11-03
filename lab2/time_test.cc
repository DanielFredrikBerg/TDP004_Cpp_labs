#include "catch.hpp"
#include "Time.h"

// här lägger ni era testfall. 
// Jobba enligt TDD; 
//  1. Lägg till testfall
//  2. Testa
//  3. Lägg till (minsta möjliga) implementation
//  4. Testa alla testfall
//  5. Refaktorera (skriv om) så att allt ser bra ut

TEST_CASE("Time can be validated", "[is_valid]")
{
	Time t1{1,1,1};
	Time t2{};
	Time t3{t1 ,60};

	REQUIRE(t1.is_valid());
	REQUIRE(t2.is_valid());
	REQUIRE(!t3.is_valid());	
}

TEST_CASE("Check time_adjuster", "[adjust_time]")
{
  Time t1{240, 80, 20};
  Time t2{-245, 20, 10};
  Time t3{-240, -240, -1};
  t1.adjust_time();
  t2.adjust_time();
  t3.adjust_time();
  REQUIRE(t1.get_hour() == 1);
  REQUIRE(t1.get_minute() == 20);
  REQUIRE(t1.get_second() == 20);
  REQUIRE(t2.get_hour() == 19);
  REQUIRE(t3.get_hour() == 19);
  REQUIRE(t3.get_minute() == 59);
  REQUIRE(t3.get_second() == 59);
}

TEST_CASE("Check to_string", "[to_string]")
{
  Time t1{12, 20, 59};
  Time t2{23, 10, 00};
  Time t3{00, 00, 00};
  Time t4{23, 59, 59};
  Time t5{12, 00, 00};

  REQUIRE(t1.to_string(true) == "12:20:59 pm");
  REQUIRE(t2.to_string(true) == "11:10:00 pm");
  REQUIRE(t3.to_string(true) == "00:00:00 am");
  REQUIRE(t2.to_string(false) == "23:10:00");
  REQUIRE(t3.to_string(false) == "00:00:00");
  REQUIRE(t4.to_string(true) == "11:59:59 pm");
  REQUIRE(t5.to_string(true) == "12:00:00 pm");
}


