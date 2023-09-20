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
	void    plageAddNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
	int     shortestSpan() const;
	int     longestSpan() const;

	Span    &operator=(const Span &rhs);


	class ToManyAddException : std::exception {
	public:
		virtual const char * thereIsAnIssue() {
			return "The span is full";
		}
	};

	class NoNumberEnoughForSearchException : std::exception {
	public:
		virtual const char * thereIsAnIssue() {
			return "No number enough in the span";
		}
	};


private:
	std::vector<int>    _v1;
	int                 _nbAdd;
};


#endif //CPP08_SPAN_HPP
