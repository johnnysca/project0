#include <vector>
#include <gtest/gtest.h>
#include "tspbruteforce.hpp"
#include "zeckendorf.hpp"

namespace{

	/*
	 * Test cases marked RequiredTSPBF are required for the TSP brute force portion.
	 * If your code does not pass all of them, your score for that portion will be zero.
	 * If your codes DOES pass them, we will run other test cases to grade your work.
	 */

	//TEST 1
	TEST(RequiredTSPBF, TestCostOfJourney)
	{
		std::vector< std::vector< long > > distances = 
		{
				{0, 2, 9, 1000}, 
				{1, 0, 6, 4}, 
				{1000, 7, 0, 8}, 
				{6, 3, 1000, 0}
		};
		std::vector<unsigned> journey = {0, 2, 3, 1};
		EXPECT_TRUE( costOfJourney(distances, journey) == 21);
	}

	TEST(RequiredTSPBF, TestFindJourney)
	{
		std::vector< std::vector< long > > distances = 
		{
				{0, 2, 9, 1000}, 
				{1, 0, 6, 4}, 
				{1000, 7, 0, 8}, 
				{6, 3, 1000, 0}
		};
		std::vector<unsigned> expected = {0, 2, 3, 1};
		EXPECT_TRUE( tsp_bruteforce(distances, 4) == expected );
	}

	// TEST 2
	// TEST(RequiredTSPBF, TestCostOfJourney)
	// {
	// 	std::vector< std::vector< long > > distances = 
	// 	{
	// 			{0,10,15,20},
	// 			{5,0,9,10},
	// 			{6,13,0,12},
	// 			{8,8,9,0}
	// 	};
	// 	std::vector<unsigned> journey = {0, 1, 3, 2};
	// 	EXPECT_TRUE( costOfJourney(distances, journey) == 35);
	// }

	// TEST(RequiredTSPBF, TestFindJourney)
	// {
	// 	std::vector< std::vector< long > > distances = 
	// 	{
	// 			{0,10,15,20},
	// 			{5,0,9,10},
	// 			{6,13,0,12},
	// 			{8,8,9,0}
	// 	};
	// 	std::vector<unsigned> expected = {0, 1, 3, 2};
	// 	EXPECT_TRUE( tsp_bruteforce(distances, 4) == expected );
	// }

	// TEST(RequiredTSPBF, TestCostOfJourney)
	// {
	// 	std::vector< std::vector< long > > distances = 
	// 	{
	// 			{0,16,11,6},
	// 			{8,0,13,16},
	// 			{4,7,0,9},
	// 			{5,12,2,0}
	// 	};
	// 	std::vector<unsigned> journey = {0, 3, 2, 1};
	// 	EXPECT_TRUE( costOfJourney(distances, journey) == 23);
	// }

	// TEST(RequiredTSPBF, TestFindJourney)
	// {
	// 	std::vector< std::vector< long > > distances = 
	// 	{
	// 			{0,16,11,6},
	// 			{8,0,13,16},
	// 			{4,7,0,9},
	// 			{5,12,2,0}
	// 	};
	// 	std::vector<unsigned> expected = {0, 3, 2, 1};
	// 	EXPECT_TRUE( tsp_bruteforce(distances, 4) == expected );
	// }

	// TEST(RequiredTSPBF, TestCostOfJourney)
	// {
	// 	std::vector< std::vector< long > > distances = 
	// 	{
	// 			{0,12,29,22,13,24},
	// 			{12,0,19,3,25,6},
	// 			{29,19,0,21,23,28},
	// 			{22,3,21,0,4,5},
	// 			{13,25,23,4,0,16},
	// 			{24,6,28,5,16,0}
	// 	};
	// 	std::vector<unsigned> journey = {0,2,1,5,3,4};
	// 	EXPECT_TRUE( costOfJourney(distances, journey) == 76);
	// }

	// TEST(RequiredTSPBF, TestFindJourney)
	// {
	// 	std::vector< std::vector< long > > distances = 
	// 	{
	// 			{0,12,29,22,13,24},
	// 			{12,0,19,3,25,6},
	// 			{29,19,0,21,23,28},
	// 			{22,3,21,0,4,5},
	// 			{13,25,23,4,0,16},
	// 			{24,6,28,5,16,0}
	// 	};
	// 	std::vector<unsigned> expected = {0,2,1,5,3,4};
	// 	EXPECT_TRUE( tsp_bruteforce(distances, 6) == expected );
	// }

	// TEST(RequiredTSPBF, TestCostOfJourney)
	// {
	// 	std::vector< std::vector< long > > distances = 
	// 	{
	// 			{0,10,15,20},
	// 			{10,0,35,25},
	// 			{15,35,0,30},
	// 			{20,25,30,0}
	// 	};
	// 	std::vector<unsigned> journey = {0,1,3,2};
	// 	EXPECT_TRUE( costOfJourney(distances, journey) == 80);
	// }

	// TEST(RequiredTSPBF, TestFindJourney)
	// {
	// 	std::vector< std::vector< long > > distances = 
	// 	{
	// 			{0,10,15,20},
	// 			{10,0,35,25},
	// 			{15,35,0,30},
	// 			{20,25,30,0}
	// 	};
	// 	std::vector<unsigned> expected = {0,1,3,2};
	// 	EXPECT_TRUE( tsp_bruteforce(distances, 4) == expected );
	// }


/*
 * The following two functions are used in test cases below.
 * You MAY use them if you create additional test cases.
 * However, you MAY NOT use them in your code elsewhere (such as in app/)
 */


// This returns true iff zRep is a Zeckendorf representation of the given target number. 
bool confirmAddsTo(const std::bitset<48> &zRep, unsigned target)
{

	constexpr unsigned MAX_FIB_BITS = 48;	
	std::vector<unsigned>  fibs;
	fibs.push_back(0);
	fibs.push_back(1);
	unsigned total = 0;
	while( fibs.size() < MAX_FIB_BITS )
	{
		fibs.push_back( fibs[fibs.size() - 1] + fibs[fibs.size() - 2] );
	}
	for(unsigned i=0; i < zRep.size(); i++)
	{
		if( zRep[i] == 1 )
		{
			total += fibs[i];
		}
	}
	return total == target;
}


// returns true iff zRep has no two consecutive ones.
bool confirmIsZeckendorfRep(const std::bitset<48> & zRep)
{
	if( zRep[0] == 1 and zRep[1] == 1 )
	{
		return false;
	}
	if( zRep[47] == 1 and zRep[46] == 1 )
	{
		return false;
	}
	for(unsigned i=1; i < 47; i++)
	{
		if( zRep[i] == 1 )
		{
			if( zRep[i-1] == 1 or zRep[i+1] == 1 )
			{
				return false;
			}
		}
	}
	return true;

}


	/*
	 * Test cases marked RequiredZeckendorf are required for the Zeckendorf numbers portion.
	 * If your code does not pass all of them, your score for that portion will be zero.
	 * If your codes DOES pass them, we will run other test cases to grade your work.
	 */

	TEST(RequiredZeckendorf, TestSmallSum)
	{
		constexpr unsigned TARGET_VALUE = 610 + 89 + 5;
		//constexpr unsigned TARGET_VALUE = 4;
		//constexpr unsigned TARGET_VALUE = 3 + 8 + 13
		auto zRep = zeckendorf( TARGET_VALUE );
		EXPECT_TRUE( confirmAddsTo(zRep, TARGET_VALUE) and confirmIsZeckendorfRep(zRep) );
	}


	TEST(RequiredZeckendorf, TestMediumSum)
	{
		constexpr unsigned TARGET_VALUE = 514229 + 6765;
		auto zRep = zeckendorf( TARGET_VALUE );
		EXPECT_TRUE( confirmAddsTo(zRep, TARGET_VALUE) and confirmIsZeckendorfRep(zRep) );
	}

	TEST(RequiredZeckendorf, TestLargeFibValue)
	{
		// despite the test name, 2971215073 *is not* the largest value we could test when grading.
		// It is, however, the largest Fibonacci number that fits into an unsigned.
		
		constexpr unsigned int TARGET_VALUE = 2971215073;
		//constexpr unsigned TARGET_VALUE = UINT_MAX;
		//constexpr unsigned TARGET_VALUE = UINT_MAX+1;
		//constexpr unsigned TARGET_VALUE = 267914296 + 1836311903;
		auto zRep = zeckendorf( TARGET_VALUE );
		EXPECT_TRUE( confirmAddsTo(zRep, TARGET_VALUE) and confirmIsZeckendorfRep(zRep) );
	}


}
