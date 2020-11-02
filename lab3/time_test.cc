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

	REQUIRE(t1.is_valid());
}