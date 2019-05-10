#include <iostream>

template <typename U>
void print(U const &input)
{
	std::cout << input << std::endl;
}

template <typename T, typename F>
void iter(T *array, unsigned long n, F op)
{
	for (unsigned long i = 0; i < n; i++)
		op(array[i]);
}

template <typename T>
void iter_limit(T *array, unsigned long n, void f(T const &))
{
	for (unsigned long i = 0; i < n; i++)
		f(array[i]);
}

// well guess we don't have fully functional programing until c++11 with lambda
// cannot pass a template template function as a argument...
// template <typename T, template <typename> typename F>
// void iter(T *array, unsigned long n, F<T> op)
// {
// 	for (int i = 0; i < n; i++)
// 		op(array[i]);
// }

// well I guess this way compliler knows where to call the template function
// we could elimiate the need to indicate type twice....
// guess too much overheal lol....
template <typename T>
class print_fn
{
public:
	T input;
	print_fn(T input) : input(input){};
	void operator()()
	{
		std::cout << input << std::endl;
	}
};

template <typename T, template <typename> class F>
class iter_fn
{
public:
	T *array;
	unsigned long n;
	iter_fn(T *array, unsigned long n) : array(array), n(n){};
	void operator()()
	{
		for (unsigned long i = 0; i < n; i++)
		{
			F<T> pfn(array[i]);
			pfn();
		}
	}
};

int main()
{
	int ints[] = {4, 5, 6, 7, 8};
	float floats[] = {4.2, 5.2, 6.2, 7.2, 8.2};
	std::string strings[] = {"abc", "this", "that"};

	std::cout << "Explicit instantiation" << std::endl;
	iter<int>(ints, sizeof(ints) / sizeof(int), print<int>);
	iter<float>(floats, sizeof(floats) / sizeof(float), print<float>);
	iter(strings, sizeof(strings) / sizeof(std::string), print<std::string>);
	std::cout << "functor" << std::endl;
	(iter_fn<int, print_fn>(ints, sizeof(ints) / sizeof(int)))();
	(iter_fn<float, print_fn>(floats, sizeof(floats) / sizeof(float)))();
	(iter_fn<std::string, print_fn>(strings, sizeof(strings) / sizeof(std::string)))();
	std::cout << "limited interface with implicit type deduction" << std::endl;
	iter_limit(ints, sizeof(ints) / sizeof(int), print);
	iter_limit(floats, sizeof(floats) / sizeof(float), print);
	iter_limit(strings, sizeof(strings) / sizeof(std::string), print);
}
