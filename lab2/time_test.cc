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
	Time t3{t1,60};
	Time t4{"23:35:21"};

	REQUIRE(t1.is_valid());
	REQUIRE(t2.is_valid());
	REQUIRE(t3.is_valid());
	REQUIRE(t4.is_valid());	
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

TEST_CASE("Checking + operator", "[operator+]")
{
  Time t3{23, 59, 59};
  Time t1{t3 + 20};
  REQUIRE(t1.get_hour() == 0);
  REQUIRE(t1.get_minute() == 0);
  REQUIRE(t1.get_second() == 19);
  REQUIRE((t1 + 20).get_second() == 39);
}

TEST_CASE("Checking - operator", "[operator-]")
{
  Time t1{01, 00, 00};
  Time t3{0, 0, 0};
  Time t4{23, 50, 30};
  Time t5{t1 - 40 * 60};
  Time t6{t3 - 670};
  REQUIRE(t5.get_hour() == 0);
  REQUIRE(t5.get_minute() == 20);
  REQUIRE(t5.get_second() == 00);
  REQUIRE(t6.get_hour() == 23);
  REQUIRE(t6.get_minute() == 48);
  REQUIRE(t6.get_second() == 50);
}

TEST_CASE("Checking prefix ++ operator", "[operator++]")
{
  Time t1{23, 59, 59};
  ++t1;
  REQUIRE(t1.get_hour() == 0);
  REQUIRE(t1.get_minute() == 0);
  REQUIRE(t1.get_second() == 0);
  ++t1;
  REQUIRE(t1.get_hour() == 0);
  REQUIRE(t1.get_minute() == 0);
  REQUIRE(t1.get_second() == 1);
}

TEST_CASE("Checking postfix ++ operator", "[operator++]")
{
  Time t1{23, 59, 59};
  Time t2{t1++};
  REQUIRE(t2.get_hour() == 23);
  REQUIRE(t2.get_minute() == 59);
  REQUIRE(t2.get_second() == 59);
  t1++;
  REQUIRE(t1.get_hour() == 0);
  REQUIRE(t1.get_minute() == 0);
  REQUIRE(t1.get_second() == 1);
}

TEST_CASE("Checking prefix -- operator", "[operator--]")
{
  Time t1{00, 00, 00};
  --t1;
  REQUIRE(t1.get_hour() == 23);
  REQUIRE(t1.get_minute() == 59);
  REQUIRE(t1.get_second() == 59);
  --t1;
  REQUIRE(t1.get_hour() == 23);
  REQUIRE(t1.get_minute() == 59);
  REQUIRE(t1.get_second() == 58);
}

TEST_CASE("Checking postfix -- operator", "[operator--]")
{
  Time t1{00, 00, 00};
  Time t2{t1--};
  REQUIRE(t2.get_hour() == 00);
  REQUIRE(t2.get_minute() == 00);
  REQUIRE(t2.get_second() == 00);
  t1--;
  REQUIRE(t1.get_hour() == 23);
  REQUIRE(t1.get_minute() == 59);
  REQUIRE(t1.get_second() == 58);
}

TEST_CASE("Checking >= operator", "[operator>=]")
{
  Time t1{22, 10, 00};
  Time t2{22, 10, 00};
  Time t3{02, 43, 18};
  REQUIRE(t1 >= t2);
  REQUIRE(t1 >= t3);
  REQUIRE(!(t3 >= t2));
}

TEST_CASE("Checking <= operator", "[operator<=]")
{
  Time t1{22, 10, 00};
  Time t2{22, 10, 00};
  Time t3{02, 43, 18};
  REQUIRE(t1 <= t2);
  REQUIRE(t3 <= t2);
}

TEST_CASE("Checking > operator", "[operator>]")
{
  Time t1{22, 10, 00};
  Time t2{22, 10, 00};
  Time t3{02, 43, 18};
  REQUIRE(!(t1 > t2));
  REQUIRE(t2 > t3);
}

TEST_CASE("Checking < operator", "[operator<]")
{
  Time t1{22, 10, 00};
  Time t2{22, 10, 00};
  Time t3{02, 43, 18};
  REQUIRE(!(t1 < t2));
  REQUIRE(t3 < t2);
}

TEST_CASE("Checking == operator", "[operator==]")
{
  Time t1{22, 10, 00};
  Time t2{22, 10, 00};
  Time t3{02, 43, 18};
  REQUIRE(t1 == t2);
  REQUIRE(!(t3 == t2));
}

TEST_CASE("Checking != operator", "[operator!=]")
{
  Time t1{22, 10, 00};
  Time t2{22, 10, 00};
  Time t3{02, 43, 18};
  REQUIRE(!(t1 != t2));
  REQUIRE(t1 != t3);
}

TEST_CASE("Checking << operator", "[operator<<]")
{
  Time t1{23, 59, 59};
  std::string str{"23:59:59"};
  std::stringstream str_stream{};
  str_stream << t1;
  REQUIRE(str_stream.str() == str);
}

TEST_CASE("Checking >> operator", "[operator>>]")
{
  Time t1{"23:58:40"};
  Time t2{};
  std::stringstream str_stream{};
  str_stream << t1;
  str_stream >> t2;
  REQUIRE(t2.get_hour() == 23);
  
  str_stream << "24:25:26";
  try
  {
    str_stream >> t2;
  }
  catch (std::exception& e)
  {
    REQUIRE(!str_stream.good());
  }
}
