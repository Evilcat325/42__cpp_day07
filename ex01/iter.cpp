#include <iostream>

template <typename T>
void print(T const &input)
{
	std::cout << input << std::endl;
}

// template <typename T, template <typename> typename F>
// void iter(T *array, unsigned long n, F<T> op)
// {
// 	for (int i = 0; i < n; i++)
// 		op(array[i]);
// }

template <typename T, typename F>
void iter(T *array, unsigned long n, F op)
{
	for (unsigned long i = 0; i < n; i++)
		op(array[i]);
}

int main()
{
	int ints[] = {4, 5, 6, 7, 8};
	iter<int>(ints, sizeof(ints) / sizeof(int), print<int>);
	//float floats[] = {4.2, 5.2, 6.2, 7.2, 8.2};
	// iter(floats, sizeof(floats) / sizeof(float), &print);
	// std::string strings[] = {"abc", "this", "that"};
	// iter(strings, sizeof(strings) / sizeof(std::string), &print);
}
