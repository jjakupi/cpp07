#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdlib.h>

template <typename T>
class Array
{
	private:
		T			 *m_data; //pointer te data jo data vet
		unsigned int m_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& copy);

		T		&operator[](unsigned int i);
		T const	&operator[](unsigned int i)const;


		~Array();

		unsigned int size()const;

		class OutofBounds : public std::exception
		{
			public :

				virtual const char * what() const throw()
				{
					return ("Index out of bounds");
				}
		};
};
#include "Array.tpp"
#endif
