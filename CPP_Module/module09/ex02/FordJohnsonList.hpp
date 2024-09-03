#include "PmergeMe.hpp"
#include "BinarySearch.hpp"
#include "Debug.hpp"

void MakePair(std::list<int> &container, std::list<t_pair> &pair_container);

void merge(std::list<t_pair> &container, int start, int mid, int end);

void merge_sort(std::list<t_pair> &container, int start, int end);

void FordJohnson(std::list<int> &container);