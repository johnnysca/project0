#include "tspbruteforce.hpp"
#include <algorithm>
#include <iostream>

// NOTE:  This is a sample designed to show you one way to generate all 
// permutations of a vector.  It is NOT a correct answer.
// I encourage you to read this code, understand what it does, 
// and ask questions if you have any.
// Then, your understanding should help you finish the assignment. 
std::vector<unsigned> tsp_bruteforce(const std::vector<std::vector<long>> & graph, unsigned n) {
	unsigned i, bestCost = UINT_MAX; // best cost to store min roundtrip cost
	std::vector<unsigned> perms(n), result(n); 
	
	for(i = 0; i < n; i++) {
		perms[i] = i;
	}

	do {
		unsigned int currCost = costOfJourney(graph, perms);
		if(currCost < bestCost){ // save the curr path as its the current best
			bestCost = currCost;
			result = perms;
		}
	}while( std::next_permutation(perms.begin(), perms.end()));
	return result; 
}

long costOfJourney(const std::vector<std::vector<long>> & graph, const std::vector<unsigned> & journey) {
	unsigned from = journey[journey.size()-1], to = journey[0];
	unsigned cost = graph[from][to]; // cost from the last element to first element
	
	for(unsigned i = journey.size()-2; i != -1; i--){
		from = journey[i];
		to = journey[i+1];
		cost += graph[from][to];
	}
	return cost;
}