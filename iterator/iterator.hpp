#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>
#include "../utility/utility.hpp"

namespace ft{

		/*template<bool B, class T, class F>
struct conditional {
	typedef F type;
};
 
template<class T, class F>
struct conditional<true, T, F> { typedef T type; };
*/
template< typename T, bool IsConst>class RandomAccessIterator
{
	public:
		typedef	typename conditional<IsConst, const T, T>::type	value_type;
		typedef	typename conditional<IsConst, const T*, T*>::type	pointer;
		typedef	typename conditional<IsConst, const T&, T&>::type	reference;
		typedef	std::ptrdiff_t	difference_type;
		//this is for std::functions
		typedef	std::random_access_iterator_tag iterator_category;
		
	//maybe protected???
	private:
		pointer _ptr;
		//CONSTRUCTORS
	public:
		RandomAccessIterator() : _ptr(){}
		RandomAccessIterator(pointer a) : _ptr(a){};
		virtual ~RandomAccessIterator() {}	
		RandomAccessIterator(const RandomAccessIterator<T, IsConst> & src) : _ptr(src._ptr){}
		pointer base(void) const{
			return _ptr;
		}
	RandomAccessIterator<T, IsConst> & operator=(RandomAccessIterator<T, IsConst> const & src){
			_ptr = src._ptr;
			return (*this);
		}
		operator RandomAccessIterator<T, true>() const{
			return (RandomAccessIterator<T, true>(_ptr));
		};

		//COMPARISON OPERATORS
		bool operator==(const RandomAccessIterator<T, true> & rhs) const{
			return (_ptr == rhs.base());
		}
		bool operator==(const RandomAccessIterator<T, false> & rhs) const{
			return (_ptr == rhs.base());
		}
		bool operator!=(const RandomAccessIterator<T, true> & rhs) const{
			return (!(*this == rhs));
		}
		bool operator!=(const RandomAccessIterator<T, false> & rhs) const{
			return (!(*this == rhs));
		}
		bool operator>(const RandomAccessIterator<T, true> & rhs) const{
			return (_ptr > rhs.base());
		}
		bool operator>(const RandomAccessIterator<T, false> & rhs) const{
			return (_ptr > rhs.base());
		}
		bool operator<(const RandomAccessIterator<T, true> & rhs) const{
			return (_ptr < rhs.base());
		}
		bool operator<(const RandomAccessIterator<T, false> & rhs) const{
			return (_ptr < rhs.base());
		}
		bool operator<=(const RandomAccessIterator<T, true> & rhs) const{
			return (_ptr <= rhs.base());
		}
		bool operator<=(const RandomAccessIterator<T, false> & rhs) const{
			return (_ptr <= rhs.base());
		}
		bool operator>=(const RandomAccessIterator<T, true> & rhs) const{
			return (_ptr >= rhs.base());
		}
		bool operator>=(const RandomAccessIterator<T, false> & rhs) const{
			return (_ptr >= rhs.base());
		}
		
		//OPERATORS
		RandomAccessIterator & operator++(){
			++_ptr;
			return (*this);
		}
		RandomAccessIterator  operator++(int){
			RandomAccessIterator tmp(*this);
			++_ptr;
			return(tmp);
		}
		RandomAccessIterator & operator--(){
			--_ptr;
			return (*this);

		}
		RandomAccessIterator  operator--(int){
			RandomAccessIterator tmp = *this;
			--_ptr;
			return(tmp);
		}
		RandomAccessIterator operator+(const difference_type & a) const{
			return (_ptr + a);
		}
	
		RandomAccessIterator operator-(const difference_type & a) const{
			return(_ptr - a);
		}
		difference_type operator-(const RandomAccessIterator<T,true> & b){
			return(_ptr - b.base());
		}
		difference_type operator-(const RandomAccessIterator<T, false> & b){
			return(_ptr - b._ptr);
		}
		RandomAccessIterator & operator+=(const difference_type & a){
			_ptr += a;
			return (*this);
		}
		RandomAccessIterator & operator-=(const difference_type & a){
			_ptr -= a;
			return (*this);
		}
		pointer operator->(){
			return(_ptr);
		}
		value_type & operator*(){
			return(*_ptr);
		}
		reference operator[](difference_type n) const{
			return(*(_ptr + n));
		}
};

template<typename L, bool IsConst>
RandomAccessIterator<L, IsConst> operator +(const typename RandomAccessIterator<L, IsConst>::difference_type & a, const RandomAccessIterator<L, IsConst> & iter){
		return	(iter + a);	
	}

template<typename L, bool IsConst>
RandomAccessIterator<L, IsConst> operator -(const typename RandomAccessIterator<L, IsConst>::difference_type & a, const RandomAccessIterator<L, IsConst> & iter){
		return	(iter - a);	
	}

};
#endif
