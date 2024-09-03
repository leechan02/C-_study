#pragma once

#include <iostream>

template <typename T>
class Array
{
	private:
		T* _array;
		int _size;
	public:
		Array(void) : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		Array(const Array& other) : _array(NULL), _size(0) {*this = other;}
		~Array(void) {delete[] _array;}

		Array& operator=(const Array& other)
		{
			if (this != &other)
			{
				delete[] _array;
				_size = other._size;
				_array = new T[_size];
				for (int i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return (*this);
		}

		T& operator[](int index)
		{
			if (index < 0 || index >= _size)
				throw OutOfBoundsException();
			return (_array[index]);
		}

		const T& operator[](int index) const
		{
			if (index < 0 || index >= _size)
				throw OutOfBoundsException();
			return (_array[index]);
		}

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Index out of bounds");
				}
		};
		int size(void) const {return (_size);}
};