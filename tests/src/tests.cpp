#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../src/duration.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 

//testcases for initial start times

TEST_CASE("Duration")
{
    // test Duration()
    Duration clock = Duration(); 
    REQUIRE(clock.getDuration() == 0); 

    // test Duration(int t)
    clock = Duration(10); 
    REQUIRE(clock.getDuration() == 10);

    // test if we set time back
    clock = Duration(3);
    REQUIRE(clock.getDuration() == 3);
}

TEST_CASE("tick")
{
    Duration clock = Duration(); 
    clock.tick(); 
    REQUIRE(clock.getDuration() == 1);
    clock.tick(); 
    REQUIRE(clock.getDuration() == 2);

    clock.tick(10);
    REQUIRE(clock.getDuration() == 12);
    clock.tick(0); 
    REQUIRE(clock.getDuration() == 12);
}
TEST_CASE("alarm")

{
    Duration clock = Duration(); 
    REQUIRE(clock.hasAlarmBeenSet() == false); 
    clock.setAlarm(2);
    REQUIRE(clock.hasAlarmBeenSet() == true);
    clock.tick(); 
    REQUIRE(clock.hasAlarmBeenSet() == true);
    clock.tick(); 
    REQUIRE(clock.getDuration() == 2); // 
    REQUIRE(clock.hasAlarmBeenSet() == false); 

    clock.tick(100); 
    clock.setAlarm(1);
    REQUIRE(clock.hasAlarmBeenSet() == false);
}