#ifndef CPP07_ARRAY_HPP
#define CPP07_ARRAY_HPP

template<typename T>
class Array {
public:
	Array();
	Array(unsigned int n);
	Array(const Array &src);
	~Array();

	Array &operator=(const Array &rhs);
	T &operator[](size_t pos);

	unsigned int size() const;
private:
	unsigned int _length;
	T *_value;
};



template<typename T>
Array<T> &Array<T>::operator=(const Array &rhs) {
	if (this->_value != NULL)
		delete [] this->_value;
	this->_value = new T[rhs._length];
	for (unsigned int i = 0; i < rhs.size(); ++i) {
		this->_value[i] = rhs._value[i];
	}
	return *this;
}

template<typename T>
Array<T>::Array() : _length(0) {
	this->_value = NULL;
}

template<typename T>
Array<T>::Array(unsigned int n) : _length(n) {
	this->_value = new T[n];
	for (unsigned int i = 0; i < n; ++i) {
		this->_value[i] = T();
	}
}

template<typename T>
Array<T>::Array(const Array &src) {
	*this = src;
}

template<typename T>
Array<T>::~Array() {
	if (this->_value != NULL)
		delete [] this->_value;
}

template<typename T>
unsigned int Array<T>::size() const {
	return this->_length;
}

template<typename T>
T &Array<T>::operator[](size_t pos) {
	return this->_value[pos];
}

#endif //CPP07_ARRAY_HPP
