#ifndef CPP08_SPAN_HPP
#define CPP08_SPAN_HPP

#include <stdexcept>
#include <vector>

class Span {
public:
	Span();
	Span(int N);
	Span(const Span &src);
	~Span();

	void    addNumber(int value);
	int     shortestSpan() const;
	int     longestSpan() const;

	Span    &operator=(const Span &rhs);


	class ToManyAdd : std::exception {
	public:
		virtual const char * thereIsAnIssue() {
			return "The span is full";
		}
	};

	class NoNumberEnoughForSearch : std::exception {
	public:
		virtual const char * thereIsAnIssue() {
			return "No number enough in the span";
		}
	};


private:
	std::vector<int>    _v1;
};


#endif //CPP08_SPAN_HPP
