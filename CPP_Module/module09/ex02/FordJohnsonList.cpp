#include "FordJohnsonList.hpp"

void MakePair(std::list<int> &container, std::list<t_pair> &pair_container)
{
	std::list<int>::iterator	first = container.begin();
	std::list<int>::iterator	second;
	for (std::size_t i = 0; i < container.size() - 1; i += 2, ++first, ++first)
	{
		second = first, ++second;
		if (*first > *second)
			std::swap(*first, *second);
		pair_container.push_back(t_pair(*first, *second));
	}
	if (container.size() % 2)
	{
		second = container.end(), --second;
		pair_container.push_back(t_pair(-1, *second));
	}
}

void merge(std::list<t_pair> &container, int start, int mid, int end)
{
	int left = start;
	int right = mid + 1;
	std::list<t_pair> temp;

	std::list<t_pair>::iterator left_it = container.begin();
	std::list<t_pair>::iterator right_it = container.begin();

 	std::advance(left_it, start);
	std::advance(right_it, mid + 1);
	while (left <= mid && right <= end)
	{
		if (left_it->second <= right_it->second)
			temp.push_back(*left_it++), ++left;
		else
			temp.push_back(*right_it++), ++right;
	}
	if (left > mid)
		while (right <= end)
			temp.push_back(*right_it++), ++right;
	else
		while (left <= mid)
			temp.push_back(*left_it++), ++left;

	std::list<t_pair>::iterator temp_it = temp.begin();
	std::list<t_pair>::iterator container_it = container.begin();
 	std::advance(container_it, start);
	for (; temp_it != temp.end(); ++container_it, ++temp_it)
		*container_it = *temp_it;
}

void merge_sort(std::list<t_pair> &container, int start, int end)
{
	int mid;

	if (start < end)
	{
		mid = (start + end) / 2;
		merge_sort(container, start, mid);
		merge_sort(container, mid + 1, end);
		merge(container, start, mid, end);
	}
}

void FordJohnson(std::list<int> &container)
{
	std::list<t_pair> pair_container;

	MakePair(container, pair_container);

	std::list<int>	main_chain;
	std::vector<t_pend>	pend;

	print_debug(pair_container, main_chain, pend, 1);

	// container를 두 개의 짝 중에서 뒤 원소를 기준으로 병합 정렬
	merge_sort(pair_container, 0, pair_container.size() - 1);
	print_debug(pair_container, main_chain, pend, 2);

	// pend의 각 원소의 인덱스 해당하는 main_chain에 있는 원소의 iterator를 저장.
	std::list<int>::iterator iter;
	std::list<t_pair>::iterator pair_iter = pair_container.begin();
	for (std::size_t i = 0; i < pair_container.size(); ++i)
	{
		main_chain.push_back(pair_iter->second);

		if (i == 0)
			iter = main_chain.begin();
		else
			++iter;

		if (pair_iter->first != -1)
			pend.push_back(t_pend(pair_iter->first, iter));
		++pair_iter;
	}

	print_debug(pair_container, main_chain, pend, 3);

	// Jacobsthal 수열을 사용해서 비교해서 insert_sort.
	insert_sort(main_chain, pend);

	// 원본(container)에 정렬된 원소 대입
	std::list<int>::iterator copy_it = main_chain.begin();
	std::list<int>::iterator container_it = container.begin();
	for (; container_it != container.end(); ++copy_it, ++container_it)
		*container_it = *copy_it;
}
