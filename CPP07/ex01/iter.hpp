#ifndef CPP07_ITER_HPP
#define CPP07_ITER_HPP

template<typename T>
void incrementVal(T *i) {
	(*i)++;
}

template<typename T>
void decrementVal(T *i) {
	(*i)--;
}

template<typename T>
void doSomething(T *i) {
	if (*i == 0)
		(*i)++;
	else
		(*i)--;
}

template<typename T, typename F>
void iter(T **array, int arrayLength, F function) {
	for (int i = 0; i < arrayLength; ++i) {
		function(array[i]);
	}
}

#endif //CPP07_ITER_HPP
