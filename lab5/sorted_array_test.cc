#include "catch.hpp"

#include "sorted_array.h"
#include "less.h"


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
    sorted_array<double> a{17, 9, 5, 2, -100};
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

TEST_CASE("const array double")
{
    sorted_array<double> const a{1, 2, 3, 4, 5};

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
    sorted_array<double> array{2, 3, 5, 7, 11, 13};
    oss << array;
    CHECK (oss.str() == "{2, 3, 5, 7, 11, 13}");
}
