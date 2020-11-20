#include "catch.hpp"

#include "sorted_array.h"
#include "less.h"
#include "distance.h"


#include <sstream>

TEST_CASE("default initialization int")
{
  sorted_array<int> a;
  CHECK (a.size() == 0);
  CHECK_THROWS (a.at(0));
  CHECK_THROWS (a.erase(0));
  CHECK_THROWS (a.erase(-5));
  CHECK_THROWS (a.erase(5));
}

TEST_CASE("default initialization double")
{
  sorted_array<double> a;
  CHECK (a.size() == 0);
  CHECK_THROWS (a.at(0));
  CHECK_THROWS (a.erase(0));
  CHECK_THROWS (a.erase(-5));
  CHECK_THROWS (a.erase(5));
}

TEST_CASE("default initialization string")
{
  sorted_array<std::string> a;
  CHECK (a.size() == 0);
  CHECK_THROWS (a.at(0));
  CHECK_THROWS (a.erase(0));
  CHECK_THROWS (a.erase(-5));
  CHECK_THROWS (a.erase(5));
}


TEST_CASE("insertion int, check comparator")
{
  sorted_array<int> a;
  a.insert(5);
  CHECK (a.size() == 1);
  CHECK (a.at(0) == 5);
  CHECK (a[0] == 5);

  a.insert(1);
  CHECK (a.size() == 2);
  CHECK (a[0] == 1);
  CHECK (a[1] == 5);
}

TEST_CASE("insertion double")
{
  sorted_array<double> a;
  a.insert(5);
  CHECK (a.size() == 1);
  CHECK (a.at(0) == 5);
  CHECK (a[0] == 5);

  a.insert(1);
  CHECK (a.size() == 2);
  CHECK (a[0] == 1);
  CHECK (a[1] == 5);
}

TEST_CASE("insertion string")
{
  sorted_array<std::string> a;
  a.insert("b");
  CHECK (a.size() == 1);
  CHECK (a.at(0) == "b");
  CHECK (a[0] == "b");

  a.insert("a");
  CHECK (a.size() == 2);
  CHECK (a[0] == "a");
  CHECK (a[1] == "b");
}

TEST_CASE("initialization int")
{
  sorted_array<int> a{17, 9, 5, 2, -100};
  CHECK (a.size() == 5);
  CHECK (a[0] == -100);
  CHECK (a[1] == 2);
  CHECK (a[2] == 5);
  CHECK (a[3] == 9);
  CHECK (a[4] == 17);

  a.insert(1);
  CHECK (a.size() == 6);
  CHECK (a[0] == -100);
  CHECK (a[1] == 1);
  CHECK (a[2] == 2);
  CHECK (a[3] == 5);
  CHECK (a[4] == 9);
  CHECK (a[5] == 17);

  a.erase(5);
  CHECK (a.size() == 5);
  CHECK (a[0] == -100);
  CHECK (a[1] == 1);
  CHECK (a[2] == 2);
  CHECK (a[3] == 5);
  CHECK (a[4] == 9);

  CHECK_THROWS(a.erase(5));

  a.erase(2);
  CHECK (a.size() == 4);
  CHECK (a[0] == -100);
  CHECK (a[1] == 1);
  CHECK (a[2] == 5);
  CHECK (a[3] == 9);
}

TEST_CASE("initialization double")
{
  sorted_array<double> a{17.0, 9.0, 5.0, 2.0, -100.0};
  CHECK (a.size() == 5);
  CHECK (a[0] == -100);
  CHECK (a[1] == 2);
  CHECK (a[2] == 5);
  CHECK (a[3] == 9);
  CHECK (a[4] == 17);

  a.insert(1);
  CHECK (a.size() == 6);
  CHECK (a[0] == -100);
  CHECK (a[1] == 1);
  CHECK (a[2] == 2);
  CHECK (a[3] == 5);
  CHECK (a[4] == 9);
  CHECK (a[5] == 17);

  a.erase(5);
  CHECK (a.size() == 5);
  CHECK (a[0] == -100);
  CHECK (a[1] == 1);
  CHECK (a[2] == 2);
  CHECK (a[3] == 5);
  CHECK (a[4] == 9);

  CHECK_THROWS(a.erase(5));

  a.erase(2);
  CHECK (a.size() == 4);
  CHECK (a[0] == -100);
  CHECK (a[1] == 1);
  CHECK (a[2] == 5);
  CHECK (a[3] == 9);
}

TEST_CASE("initialization string")
{
  sorted_array<std::string> a{"fg", "cd", "cb", "a", "b"};
  CHECK (a.size() == 5);
  CHECK (a[0] == "a");
  CHECK (a[1] == "b");
  CHECK (a[2] == "cb");
  CHECK (a[3] == "cd");
  CHECK (a[4] == "fg");

  a.insert("ax");
  CHECK (a.size() == 6);
  CHECK (a[0] == "a");
  CHECK (a[1] == "ax");
  CHECK (a[2] == "b");
  CHECK (a[3] == "cb");
  CHECK (a[4] == "cd");
  CHECK (a[5] == "fg");


  a.erase(5);
  CHECK (a.size() == 5);
  CHECK (a[0] == "a");
  CHECK (a[1] == "ax");
  CHECK (a[2] == "b");
  CHECK (a[3] == "cb");
  CHECK (a[4] == "cd");

  CHECK_THROWS(a.erase(5));

  a.erase(2);
  CHECK (a.size() == 4);
  CHECK (a[0] == "a");
  CHECK (a[1] == "ax");
  CHECK (a[2] == "cb");
  CHECK (a[3] == "cd");
}

TEST_CASE("const array int")
{
  sorted_array<int> const a{1, 2, 3, 4, 5};

  CHECK (a.size() == 5);
  CHECK (a[0] == 1);
  CHECK (a[0] == a.at(0));
  CHECK (a[1] == 2);
  CHECK (a[1] == a.at(1));
  CHECK (a[2] == 3);
  CHECK (a[2] == a.at(2));
  CHECK (a[3] == 4);
  CHECK (a[3] == a.at(3));
  CHECK (a[4] == 5);
  CHECK (a[4] == a.at(4));
  CHECK_THROWS (a.at(5));
}

TEST_CASE("const array int, testing distance with multiple copies")
{
  Distance<int> d{1};
  sorted_array<int, Distance<int>> const a{{1, 1, 1, 2, 2}, d};

  CHECK (a.size() == 5);
  CHECK (a[0] == 1);
  CHECK (a[0] == a.at(0));
  CHECK (a[1] == 1);
  CHECK (a[1] == a.at(1));
  CHECK (a[2] == 1);
  CHECK (a[2] == a.at(2));
  CHECK (a[3] == 2);
  CHECK (a[3] == a.at(3));
  CHECK (a[4] == 2);
  CHECK (a[4] == a.at(4));
  CHECK_THROWS (a.at(5));
}


TEST_CASE("const array int, testing distance, default comp")
{
  Distance<int> d{0};
  sorted_array<int, Distance<int>> const a{{1, 2, 3, 4, 5}, d};
  CHECK (a.size() == 5);
  CHECK (a[0] == 1);
  CHECK (a[0] == a.at(0));
  CHECK (a[1] == 2);
  CHECK (a[1] == a.at(1));
  CHECK (a[2] == 3);
  CHECK (a[2] == a.at(2));
  CHECK (a[3] == 4);
  CHECK (a[3] == a.at(3));
  CHECK (a[4] == 5);
  CHECK (a[4] == a.at(4));
  CHECK_THROWS (a.at(5));
}

TEST_CASE("const array double")
{
  Distance<double> d{4.0};
  sorted_array<double, Distance<double>> const a{{1.0, 2.0, 3.0, 4.0, 5.0}, d};

  CHECK (a.size() == 5.0);
  CHECK (a[0] == 4.0);
  CHECK (a[0] == a.at(0));
  CHECK (a[1] == 3.0);
  CHECK (a[1] == a.at(1));
  CHECK (a[2] == 5.0);
  CHECK (a[2] == a.at(2));
  CHECK (a[3] == 2.0);
  CHECK (a[3] == a.at(3));
  CHECK (a[4] == 1.0);
  CHECK (a[4] == a.at(4));
  CHECK_THROWS (a.at(5));
}

TEST_CASE("const array double, testing distance")
{
  sorted_array<double> const a{1.0, 2.0, 3.0, 4.0, 5.0};

  CHECK (a.size() == 5.0);
  CHECK (a[0] == 1.0);
  CHECK (a[0] == a.at(0));
  CHECK (a[1] == 2.0);
  CHECK (a[1] == a.at(1));
  CHECK (a[2] == 3.0);
  CHECK (a[2] == a.at(2));
  CHECK (a[3] == 4.0);
  CHECK (a[3] == a.at(3));
  CHECK (a[4] == 5.0);
  CHECK (a[4] == a.at(4));
  CHECK_THROWS (a.at(5));
}

TEST_CASE("const array string")
{
  sorted_array<string> const a{"a", "b", "c", "d", "e"};

  CHECK (a.size() == 5);
  CHECK (a[0] == "a");
  CHECK (a[0] == a.at(0));
  CHECK (a[1] == "b");
  CHECK (a[1] == a.at(1));
  CHECK (a[2] == "c");
  CHECK (a[2] == a.at(2));
  CHECK (a[3] == "d");
  CHECK (a[3] == a.at(3));
  CHECK (a[4] == "e");
  CHECK (a[4] == a.at(4));
  CHECK_THROWS (a.at(5));
}


TEST_CASE("print empty int")
{
  std::ostringstream oss;
  sorted_array<int> empty;
  oss << empty;
  CHECK (oss.str() == "{}");
}

TEST_CASE("print empty double")
{
  std::ostringstream oss;
  sorted_array<double> empty;
  oss << empty;
  CHECK (oss.str() == "{}");
}

TEST_CASE("print empty string")
{
  std::ostringstream oss;
  sorted_array<std::string> empty;
  oss << empty;
  CHECK (oss.str() == "{}");
}

TEST_CASE("print int")
{
  std::ostringstream oss;
  sorted_array<int> array{2, 3, 5, 7, 11, 13};
  oss << array;
  CHECK (oss.str() == "{2, 3, 5, 7, 11, 13}");
}

TEST_CASE("print double")
{
  std::ostringstream oss;
  sorted_array<double> array{2.1, 3.1, 5.1, 7.1, 11.1, 13.1};
  oss << array;
  CHECK (oss.str() == "{2.1, 3.1, 5.1, 7.1, 11.1, 13.1}");
}

TEST_CASE("print string")
{
  std::ostringstream oss;
  sorted_array<std::string> array{"xa", "bb", "hello", "emacs"};
  oss << array;
  CHECK (oss.str() == "{bb, emacs, hello, xa}");
}
