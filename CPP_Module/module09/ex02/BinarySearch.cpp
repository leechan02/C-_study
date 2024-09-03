#include "BinarySearch.hpp"

void binary_search(std::list<int> &main_chain, int num, std::list<int>::iterator end)
{
	std::list<int>::iterator start = main_chain.begin();
	std::list<int>::iterator mid;

	while (start != end)
	{
		mid = start;
		std::advance(mid, std::distance(start, end) / 2);
		if (*mid < num)
			start = ++mid;
		else
			end = mid;
	}
	main_chain.insert(end, num);
}

void insert_sort(std::list<int> &main_chain, std::vector<t_pend> &pend)
{
	int	idx;
	int	insert_idx;
	int	jacob_sum;
	int	pend_size;
	std::vector<int>	jacob_dp;

	jacob_sum = 0;
	pend_size = pend.size();
	// 0번째, 1번째 초기화
	jacob_dp.push_back(2);
	jacob_dp.push_back(2);
	for (idx = 0; jacob_sum < pend_size; ++idx)
	{
		if (idx >= 2)
			jacob_dp.push_back(jacob_dp[idx - 1] + 2 * jacob_dp[idx - 2]);

		insert_idx = jacob_sum + jacob_dp[idx] - 1;
		if (insert_idx > pend_size)
			insert_idx = pend_size - 1;
		while (insert_idx >= jacob_sum)
		{
			binary_search(main_chain, pend[insert_idx].num, pend[insert_idx].iter);
			--insert_idx;
		}
		jacob_sum += jacob_dp[idx];
	}
}
