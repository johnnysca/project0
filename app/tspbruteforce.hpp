#ifndef __TSP_BRUTE_FORCE_HPP
#define __TSP_BRUTE_FORCE_HPP

#include <vector>

std::vector<unsigned> tsp_bruteforce(const std::vector<std::vector<long>> & graph, unsigned n);

long costOfJourney(const std::vector<std::vector<long>> & graph, const std::vector<unsigned> & journey);


#endif
