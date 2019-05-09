#include <iostream>
#include <sstream>
#include "Array.hpp"

int main()
{
	Array<int> arr;
	for (unsigned int i = 0, e = arr.size(); i < e; i++)
		arr[i] = i;
	Array<int> arr_copy(arr), arr_assign;
	arr_assign = arr;
	for (unsigned int i = 0, e = arr.size(); i < e; i++)
		std::cout << arr[i] << " " << arr_copy[i] << " " << arr_assign[i] << std::endl;
	Array<std::string> strarr(5);
	for (unsigned int i = 0, e = strarr.size(); i < e; i++)
	{
		std::stringstream ss;
		ss << i << "test";
		strarr[i] = ss.str();
	}
	Array<std::string> strarr_copy(strarr), strarr_assign(5);
	strarr_assign = strarr;
	for (unsigned int i = 0, e = strarr.size(); i < e; i++)
		std::cout << strarr[i] << " " << strarr_copy[i] << " " << strarr_assign[i] << std::endl;
	return 0;
}
