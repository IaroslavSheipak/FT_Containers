#include <iostream>

namespace ft{


template<typename T>class const_iterator;
template<typename T>class iterator
{
	public:
		typedef T				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		pointer					_ptr;

		iterator(){
			_ptr = 0;
		}
		iterator(const iterator & src){
			*this = src;
		}
		iterator & operator=(const iterator & src){
			_ptr = src.ptr;
			return (*this);
		}
		~iterator(){};

		//COMPARSION OPERATORS
		bool operator==(const iterator & rhs) const{
			return (_ptr == rhs.ptr);
		}
		bool operator==(const const_iterator<T> &rhs) const{
			return (_ptr == rhs.ptr);
		}
		bool operator!=(const iterator & rhs) const{
			return (_ptr != rhs.ptr);
		}
		bool operator!=(const const_iterator<T> &rhs) const{
			return (_ptr != rhs.ptr);
		}
		bool operator>(const iterator & rhs) const{
			return (_ptr > rhs.ptr);
		}
		bool operator>(const const_iterator<T> &rhs) const{
			return (_ptr > rhs.ptr);
		}
		bool operator<(const iterator & rhs) const{
			return (_ptr < rhs.ptr);
		}
		bool operator<(const const_iterator<T> &rhs) const{
			return (_ptr < rhs.ptr);
		}
		bool operator<=(const iterator & rhs) const{
			return (_ptr <= rhs.ptr);
		}
		bool operator<=(const const_iterator<T> &rhs) const{
			return (_ptr <= rhs.ptr);
		}
		bool operator>=(const iterator & rhs) const{
			return (_ptr >= rhs.ptr);
		}
		bool operator>=(const const_iterator<T> &rhs) const{
			return (_ptr >= rhs.ptr);
		}
		iterator & operator++(){
			++_ptr;
			return (*this);
		}
		iterator & operator++(int){
			iterator tmp = *this;
			++_ptr;
			return(tmp);
		}
		iterator & operator--(){
			--_ptr;
			return (*this);

		}
		iterator & operator--(int){
			iterator tmp = *this;
			--_ptr;
			return(tmp);
		}
		iterator operator+(const difference_type & a){
			return (_ptr + a);
		}
		template<typename L>
		friend iterator<L> operator+(const typename iteraror<L>:::difference_type & a, const iterator<L> & iter);
	
		iterator operator-(const difference_type & a){
			return(_ptr - a);
		}
		difference_type operator-(const iterator & b){
			return(_ptr - b._ptr);
		}
		difference_type operator-(const const_iterator<T> & b){
			return(_ptr - b._ptr);
		}

		
};



template<typename T>class const_reverse_iterator;
template<typename T>class reverse_iterator;

};

