#pragma once

#include "PmergeMe.hpp"

template <typename Container>
void	print_debug(Container &pair_container,
					std::list<int> &main_chain, std::vector<t_pend> &pend, int num)
{
	(void)pair_container, (void)main_chain, (void)pend, (void)num;
	typename Container::iterator iter;
	switch (num)
	{
	case 1:
		#ifdef DEBUG
			std::cout << "Pair: ";
			iter = pair_container.begin();
			for (; iter != pair_container.end(); ++iter)
				std::cout << "(" << (*iter).first << ", " << (*iter).second << ") ";
			std::cout << std::endl;
		#endif
		break ;
	case 2:
		#ifdef DEBUG
			std::cout << "Merge: ";
			iter = pair_container.begin();
			for (; iter != pair_container.end(); ++iter)
				std::cout << "(" << (*iter).first << ", " << (*iter).second << ") ";
			std::cout << std::endl;
		#endif
		break ;
	case 3:
		#ifdef DEBUG
			std::cout << "main_chain: ";
			std::list<int>::iterator itr = main_chain.begin();
			for (std::size_t i = 0;	i < main_chain.size(); ++i, ++itr)
				std::cout << *itr << " ";
			std::cout << std::endl;

			std::cout << "pend: ";
			for (std::size_t i = 0; i < pend.size(); ++i)
				std::cout << "(" << pend[i].num << ", " << *pend[i].iter << ") ";
			std::cout << std::endl;
		#endif
		break ;
	}
}