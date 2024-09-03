#include "PmergeMe.hpp"
#include "BinarySearch.hpp"
#include "Debug.hpp"

void MakePair(std::vector<int> &container, std::vector<t_pair> &pair_container);

void merge(std::vector<t_pair> &container, int start, int mid, int end);

void merge_sort(std::vector<t_pair> &container, int start, int end);

void FordJohnson(std::vector<int> &container);