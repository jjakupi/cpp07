#include "Array.hpp"

template <typename T>
Array<T>::Array() : m_data(NULL), m_size(0)
{

}
template <typename T>
Array<T>::Array(unsigned int n) : m_data(new T[n]), m_size(n)
{

}

template <typename T>
Array<T>::Array(Array const &copy) : m_data(new T[copy.m_size]), m_size(copy.m_size)
								//merr memorie te madhsis se size; // sa elemente jan brenda
{
	for(unsigned i = 0; i < m_size; i++)
		m_data[i] = copy.m_data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& copy)
{
	if(this != &copy)
	{
		delete[] m_data; // fshij memorin e vjeter te objektit qe te mund te bejme asssignment e objektit tjeter!
		m_size = copy.m_size; //sa elemente jan brenda
		m_data = new T[m_size]; // merr memorie te madhsis se size nese njuk e dim size,
								//new T i 'objektit 'copy' se di sa meomori ka nevoj;
		for(unsigned i = 0; i < m_size; i++)
			m_data[i] = copy.m_data[i];// kopjo qfar ka ne objektin a te objekti b nje nga nje ;
	}
	return *this;
}
template <typename T>
T	&Array<T>::operator[](unsigned int i)
{
	if(i >= m_size)
		throw (Array::OutofBounds());
	return m_data[i];
}

template <typename T>
T const	&Array<T>::operator[](unsigned int i)const
{
	if(i >= m_size)
		throw (Array::OutofBounds());
	return m_data[i];
}
template <typename T>
Array<T>::~Array()
{
	delete [] m_data;
}

template <typename T>
unsigned int Array<T>::size()const
{
	return m_size;
}
