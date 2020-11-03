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
	REQUIRE(t3.is_valid());	
}

TEST_CASE("Check time_adjuster", "[adjust_time]")
{
  Time t1{240, 80, 20};

  REQUIRE(t1.adjust_time().is_valid());
}
