#ifndef CPP08_EASYFIND_HPP
#define CPP08_EASYFIND_HPP

#include <list>
#include <vector>

template< typename T>
bool easyfind(T listValue, int num) {
	typename T::const_iterator it;
	typename T::const_iterator ite = listValue.end();

	for (it = listValue.begin(); it != ite; ++it) {
		if (*it == num)
			return true;
	}
	return false;
}

#endif //CPP08_EASYFIND_HPP

