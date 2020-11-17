// This test program uses a test framework supporting TDD and BDD.
// You are not required to use the framework, but encouraged to.
// Documentation:
// https://github.com/philsquared/Catch/blob/master/docs/tutorial.md

// Note that the testcases outline here serve simply as inspiration
// you are not required to implement these tests, but you need to
// create tests for your list, so it might be a good idea to use
// these tests as a basis.

// This define lets Catch create the main test program
// (Must be in only one place!)
#include "catch.hpp"
#include "sorted_list.h"

#include <random>

// Komplettering: Testa även er flytttilldelning. KLART (1:a scenariot)

//=======================================================================
// Test cases
//=======================================================================

TEST_CASE( "Create an empty list" ) 
{
    Sorted_List l{};

    REQUIRE( l.is_empty() );
    REQUIRE( l.size() == 0 );
}

// Solve one TEST_CASE or WHEN at a time!
//
// Move this comment and following #if 0 down one case at a time!
// Make sure to close any open braces before this comment.
// The #if 0 will disable the rest of the file.

//KOMPLETTERING
SCENARIO( "Lists can be moved" )
{
  GIVEN( "A list of four items" )
  {
    Sorted_List l{};
    l.insert(2);
    l.insert(2);
    l.insert(2);
    l.insert(2);
    
    WHEN( "A list is moved using the move constructor" )
    {
      Sorted_List l2{std::move(l)};
      THEN(" The second list contains the first list" )
      {
        REQUIRE(l2.to_string() == "[2, 2, 2, 2]");
        REQUIRE(l.is_empty()); 
      }
    }
    WHEN( "A list is moved using move assignment" )
    {
      Sorted_List l2{};
      l2 = std::move(l);
      THEN(" The second list contains the first list" )
      {
        REQUIRE(l2.to_string() == "[2, 2, 2, 2]");
        REQUIRE(l.is_empty()); 
      }
    }
  }
}


TEST_CASE( "Insert an item in an empty list" ) 
{
    Sorted_List l{};

    l.insert(5);

    // Kommentar: REQUIRE_FALSE finns.
    REQUIRE( !(l.is_empty()) );
    REQUIRE( l.size() == 1 );
}

TEST_CASE( "Successful insertion" )
{
  Sorted_List l{};

  l.insert(8);
  REQUIRE( l.first_value() == 8 );
  l.insert(5);
  REQUIRE( l.first_value() == 5 );
}

TEST_CASE( "Successful clear" )
{
  Sorted_List l{};
  l.insert(8);
  l.insert(5);
  l.clear();
  REQUIRE( l.is_empty() );
}

TEST_CASE( "Successful copy" )
{
  Sorted_List l{};
  l.insert(8);
  Sorted_List c{l};
  REQUIRE( l.first_value() == c.first_value() );
}

SCENARIO( "Empty lists" ) 
{
  
    GIVEN( "An empty list" ) 
    {
	Sorted_List l{};
        int number{3};

	REQUIRE( l.is_empty() );
	REQUIRE( l.size() == 0 );
    
	WHEN( "an item is inserted" )
	{
	    // insert an item
          l.insert(number);
      
	    THEN( "the size increase and the item is first in the list" )
	    {
              REQUIRE( !(l.is_empty())  );
              REQUIRE( l.size() == 1 );
              REQUIRE( l.first_value() == number );
	    }
	}
    
	WHEN( "an item is removed" )
	{

	    // remove an item
          l.remove(number);
          
	    THEN( "the list is still empty" )
	    {
		// add your REQUIRE statements
              REQUIRE( l.is_empty() );
              REQUIRE( l.size() == 0 );
	    }
	}
    
	WHEN( "the empty list is copied to a new list" )
	{
	    // copy your list to a new variable (copy constructor)
        Sorted_List c_list{l};

	    THEN( "the new list is also empty" )
	    {
			// add your REQUIRE statements
            REQUIRE( c_list.is_empty() == l.is_empty() );
	    }
	}

        WHEN( "the list gets a node and is copied to a new list")
        {
           l.insert(5);
           Sorted_List copied_list{l};
           
           THEN ( "the copied list contains the same value and size" )
           {
              REQUIRE( copied_list.first_value() == l.first_value() );
              REQUIRE( copied_list.size() == l.size() );
           }
        }
    
	WHEN( "the list is copied to an existing non-empty list" )
	{
          
	    // create and fill a list to act as the existing list
        Sorted_List l2{};
        l2.insert(7);
        l2.insert(9);

	    // copy (assign) your empty list to the existing
      	l2 = l;

	    THEN( "the existing list also becomes empty" )
	    {
			  // add your REQUIRE statements
              REQUIRE( l2.is_empty() );
	    }
      
	}
    }
}


SCENARIO( "Single item lists" )
{

    GIVEN( "A list with one item in it" )
    {
      Sorted_List l{};
      l.insert(5);
	// create the given scenario
    
	WHEN( "a smaller item is inserted" )
	{
          l.insert(2);

	    THEN( "first value is the smaller value" )
	    {
              REQUIRE( l.first_value() == 2 );
              REQUIRE( l.to_string() == "[2, 5]");
	    }
	}
	WHEN( "a larger item is inserted" )
	{
          l.insert(10);

	    THEN( "the larger item will be placed last" )
	    {
              REQUIRE( l.to_string() == "[5, 10]" );
	    }
	}
	WHEN( "an item is removed" )
	{
          l.remove(5);

	    THEN( "the list is empty" )
	    {
               REQUIRE( l.is_empty() );
              REQUIRE( l.to_string() == "[]" );
	    }
	}
	WHEN( "the list is copied to a new list" )
	{
          Sorted_List new_list{l};

          THEN( "new_list contains the same elements as l" )
          {
             REQUIRE( l.to_string() == new_list.to_string() );
          }
	}
	WHEN( "the list is copied to an existing non-empty list" )
	{
           Sorted_List non_empty{};
           non_empty.insert(3);
           l = non_empty;
           
           THEN( "the list now contains the same values and size as the non-empty list" )
           {
              REQUIRE( l.to_string() == non_empty.to_string() );
              REQUIRE( l.size() == non_empty.size() );
           }
	}
    }
}

SCENARIO( "Multi-item lists" )
{

    GIVEN( "A list with five items in it" )
    {
       Sorted_List five{};
       five.insert(2);
       five.insert(4);
       five.insert(6);
       five.insert(8);
       five.insert(10);

	// create the given scenario and all THEN statements
	// and all REQUIRE statements
    
	WHEN( "an item smaller than all others is inserted" )
	{
           five.insert(0);

           THEN( "the smaller item is placed first" )
           {
              REQUIRE( five.first_value() == 0 );
              REQUIRE( five.to_string() == "[0, 2, 4, 6, 8, 10]" );
           }
	}
      
	WHEN( "an item larger than all others is inserted" )
	{
           five.insert(11);

           THEN( "the larger item is placed last" )
           {
              REQUIRE( five.to_string() == "[2, 4, 6, 8, 10, 11]" );
           }

	}
	WHEN( "an item smaller than all but one item is inserted" )
	{
           five.insert(3);

           THEN( "the item is placed in the second place" )
           {
              REQUIRE( five.to_string() == "[2, 3, 4, 6, 8, 10]" );
           }

	}
	WHEN( "an item larger than all but one item is inserted" )
	{
           five.insert(9);

           THEN( "the smaller item is placed second last" )
           {
              REQUIRE( five.to_string() == "[2, 4, 6, 8, 9, 10]" );
           }

	}
	WHEN( "an item is removed" )
	{
           five.remove(6);

           THEN( "all items but the one removed are still in the list" )
           {
              REQUIRE( five.to_string() == "[2, 4, 8, 10]" );
           }

	}
	WHEN( "all items are removed" )
	{
           five.clear();
           
           THEN( "the list is empty" )
           {
              REQUIRE( five.is_empty() );
           }
	}
	WHEN( "the list is copied to a new list" )
	{
           Sorted_List new_list{five};
           THEN( "list and new list contain the same items" )
           {
              REQUIRE( five.to_string() == new_list.to_string() );
           }
	}
	WHEN( "the list is copied to an existing non-empty list" )
	{
           Sorted_List new_list{};
           new_list.insert(2);
           new_list.insert(2);
           new_list.insert(2);
           new_list = five;
           THEN( "the lists contain the same values" )
           {
              REQUIRE( new_list.to_string() == five.to_string() );
           }
	}
    }
}



SCENARIO( "Lists can be copied" )
{

  GIVEN( "A list with five items in it, and a new copy of that list" )
  {
    Sorted_List five{};
    five.insert(2);
    five.insert(4);
    five.insert(6);
    five.insert(8);
    five.insert(10);
    Sorted_List copy{five};

	WHEN( "the original list is changed" )
	{
          five.remove(4);
	    THEN( "the copy remain unmodified" )
	    {
              REQUIRE( five.to_string() != copy.to_string() );
              REQUIRE( copy.to_string() == "[2, 4, 6, 8, 10]");
	    }
	}

	WHEN( "the copied list is changed" )
	{
          copy.remove(10);
	    THEN( "the original remain unmodified" )
	    {
              REQUIRE( copy.to_string() != five.to_string() );
              REQUIRE( five.to_string() == "[2, 4, 6, 8, 10]");
	    }
	}
    }
}



SCENARIO( "Lists can be heavily used" )
{

    GIVEN( "A list with 1000 random items in it" )
    {
      Sorted_List many{};
	// create the given list with 1000 random items
	std::random_device rd;
	std::uniform_int_distribution<int> uniform(1,1000);
    
	for (int i{0}; i < 1000; ++i)
	{
	    int random { uniform(rd) }; // generate a random number
	    many.insert(random);
	}
    
	WHEN( "the list has 1000 random numbers inserted" )
	{
          for (int j{0}; j < 1000; j++)
          {
            int random { uniform(rd) };
            many.insert(random);
          }
	    // THEN the list has 2000 items in correct order
	    // (assumes unique inserts or duplicates allowed)
          THEN( "the list has 2000 items in order from small to big" )
          {
            REQUIRE( many.size() == 2000 );
            REQUIRE( many.is_sorted() );
          }
	}

	WHEN( "the list has 20000 random numbers removed" )
	{
          for (int j{0}; j < 20000; j++)
          {
            int random { uniform(rd) };
            many.remove(random);
          }
	    // THEN the list is empty
	    // (assumes successful removes)
          THEN( "the list is empty" )
          {
            REQUIRE( many.is_empty() );
          }
	}
    }
}

Sorted_List trigger_move(Sorted_List l)
{
    // do some (any) modification to list
    l.insert(6);
    return l;
}

SCENARIO( "Lists can be passed to functions" )
{
  
    GIVEN( "A list with 5 items in it" )
    {
	Sorted_List given{};
	// insert 5 items
        for (int i{0}; i < 5; i++)
        {
          given.insert(i);
        }

	WHEN( "the list is passed to trigger_move()" )
	{
	    Sorted_List l{ trigger_move(given) };
      
	    THEN( "the given list remain and the result have the change" )
	    {
              REQUIRE( given.size() == 5 );
              REQUIRE( l.size() == 6 );
              REQUIRE( given.to_string() != l.to_string() );
	    }
	}
    }
}




// In addition you must of course verify that the list is printed
// correct and that no memory leaks occur during use. You can solve
// the printing part on your own. Here's how to run the (test) program
// when you check for memory leaks:

// You must of course verify that no memory leaks occur during use.
// To do so, an external program must be used to track what memory
// is allocated and free'd, you can run such a program like so:
//
// $ valgrind --tool=memcheck a.out

// Finally you need to check that you can do all operations that make
// sense also on a immutable list (eg all operations but insert):  
void use_const_list(Sorted_List const& l)
{
    // perform every operation that do not modify the list here
  l.is_empty();
  l.is_sorted();
  l.size();
  l.first_value();
  l.to_string();
  l.print();
}


