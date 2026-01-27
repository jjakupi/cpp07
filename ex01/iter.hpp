#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template<typename T_array, typename T_function>

void iter(T_array *array, size_t length, T_function function)
{
	for(size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void print_value(const T& x)
{
	std::cout << x << std::endl;
}

template <typename T>
void increment(T& x)
{
	x = x + 1;
}

template <typename T>
void print_string(const T& s)
{
	std::cout << s << std::endl;
}

void add_exclamation(std::string& s)
{
	s += "!";
}

#endif
