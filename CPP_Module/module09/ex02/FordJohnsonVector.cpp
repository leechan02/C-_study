#include "FordJohnsonVector.hpp"

void MakePair(std::vector<int> &container, std::vector<t_pair> &pair_container)
{
	for (std::size_t i = 0; i < container.size() - 1; i += 2)
	{
		if (container[i] > container[i + 1])
			std::swap(container[i], container[i + 1]);
		pair_container.push_back(t_pair(container[i], container[i + 1]));
	}
	if (container.size() % 2)
		pair_container.push_back(t_pair(-1, container[container.size() - 1]));
}

void merge(std::vector<t_pair> &container, int start, int mid, int end)
{
	int left = start;
	int right = mid + 1;
	std::vector<t_pair> temp;

	while (left <= mid && right <= end)
	{
		if (container[left].second <= container[right].second)
			temp.push_back(container[left++]);
		else
			temp.push_back(container[right++]);
	}
	if (left > mid)
		while (right <= end)
			temp.push_back(container[right++]);
	else
		while (left <= mid)
			temp.push_back(container[left++]);
	for (int idx = 0; start <= end; ++start, ++idx)
		container[start] = temp[idx];
}

void merge_sort(std::vector<t_pair> &container, int start, int end)
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

void FordJohnson(std::vector<int> &container)
{
	std::vector<t_pair> pair_container;

	MakePair(container, pair_container);

	std::list<int>	main_chain;
	std::vector<t_pend>	pend;

	print_debug(pair_container, main_chain, pend, 1);

	// container를 두 개의 짝 중에서 뒤 원소를 기준으로 병합 정렬
	merge_sort(pair_container, 0, pair_container.size() - 1);
	print_debug(pair_container, main_chain, pend, 2);

	// pend의 각 원소의 인덱스 해당하는 main_chain에 있는 원소의 iterator를 저장.
	std::list<int>::iterator	iter;
	for (std::size_t i = 0; i < pair_container.size(); ++i)
	{
		main_chain.push_back(pair_container[i].second);

		if (i == 0)
			iter = main_chain.begin();
		else
			++iter;

		if (pair_container[i].first != -1)
			pend.push_back(t_pend(pair_container[i].first, iter));
	}

	print_debug(pair_container, main_chain, pend, 3);

	// Jacobsthal 수열을 사용해서 비교해서 insert_sort.
	insert_sort(main_chain, pend);

	// 원본(container)에 정렬된 원소 대입
	std::list<int>::iterator itr = main_chain.begin();
	for (std::size_t i = 0; i < main_chain.size(); ++i, ++itr)
		container[i] = *itr;
}