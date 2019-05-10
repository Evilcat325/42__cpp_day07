#ifndef FT_ARRAY_HPP
#define FT_ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
	unsigned int n;
	T *arr;

public:
	class ArrayIndexOutOfBound : public std::exception
	{
		virtual const char *what() const throw();
	};
	Array();
	Array(unsigned int n);
	~Array();
	Array(Array const &rhs);
	Array &operator=(Array const &rhs);
	T &operator[](unsigned int i) const;
	unsigned int size() const;
};

template <typename T>
const char *Array<T>::ArrayIndexOutOfBound::what() const throw()
{
	return "Access out of bound";
}

template <typename T>
Array<T>::Array()
		: n(10), arr(new T[n])
{
}

template <typename T>
Array<T>::Array(unsigned int n)
		: n(n), arr(new T[n])
{
}

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
Array<T>::Array(Array<T> const &rhs)
		: n(rhs.n), arr(new T[rhs.n])
{
	for (unsigned int i = 0; i < n && i < rhs.n; ++i)
		arr[i] = T(rhs.arr[i]);
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> const &rhs)
{
	for (unsigned int i = 0; i < n && i < rhs.n; ++i)
		arr[i] = rhs.arr[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i) const
{
	if (i >= n)
		throw Array<T>::ArrayIndexOutOfBound();
	else
		return arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return n;
}

#endif /* FT_Array_HPP */
