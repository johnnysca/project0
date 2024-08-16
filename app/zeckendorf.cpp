#include <bitset>
#include <iostream>
#include <vector>
#include "zeckendorf.hpp"


std::bitset<48> zeckendorf(unsigned u) {
	std::bitset<48> rep;  // note: this will set all the bits to zero.
	std::vector<unsigned> fibNums(48); // to compute first 48 fib nums that fit in unsigned data type
	fibNums[0] = 0;
	fibNums[1] = 1;

	unsigned idx;
	for(idx = 2; idx<48; idx++) {
		fibNums[idx] = fibNums[idx-1] + fibNums[idx-2];
	}
	
	// start from taking the largest fib that is not > u
	idx = 47;
	while(idx != -1 and u){
		if(u >= fibNums[idx]){ // do regular subtraction
			u -= fibNums[idx];
			rep[idx] = 1;
			idx -= 2; // prevent taking two fibs that are next to each other
		}
		else idx--; // skip since subtracting will result in u becoming ~UINT_MAX 
	}
	return rep;
}