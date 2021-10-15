#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iostream>

namespace ft{



template<bool B, class T, class F>
struct conditional { typedef T type; };
 
template<class T, class F>
struct conditional<false, T, F> { typedef F type; };


//template< bool B, class T, class F >
//	typedef typename conditional<B,T,F>::type conditional_t;

//template<typename T>class ConstRandomAccessIterator;
template< typename T>class RandomAccessIterator
{
	public:
		typedef T				value_type;
		typedef std::ptrdiff_t	difference_type;
		//typedef typename conditional<IsConst, const T*, T*>::type			pointer;
		typedef T* 				pointer;
		typedef T&				reference;
		//this is for std::functions
		typedef	std::random_access_iterator_tag iterator_category;
		//this is for vector, delete later
		//template <class _Tp, class _Alloc> friend class vector;
	private:
		//typename conditional<IsConst, const T*, T*>::type  _testptr;
		pointer _ptr;
		//CONSTRUCTORS
		RandomAccessIterator(pointer a){
			_ptr = a;
		}
	public:
		pointer base(void) const{
			return _ptr;
		}
		RandomAccessIterator(){
			_ptr = 0;
		}
		RandomAccessIterator(const RandomAccessIterator & src){
			*this = src;
		}
		template <typename It>
		RandomAccessIterator & operator=(const RandomAccessIterator<It> & src){
			_ptr = src.base();
			return (*this);
		}
	
	//	template<typename A = T, typename = std::enable_if<IsConst == true> >
		~RandomAccessIterator(){};

		//COMPARISON OPERATORS
		bool operator==(const RandomAccessIterator & rhs) const{
			return (*_ptr == *rhs._ptr);
		}
		bool operator!=(const RandomAccessIterator  & rhs) const{
			return (_ptr != rhs._ptr);
		}
		bool operator>(const RandomAccessIterator & rhs) const{
			return (_ptr > rhs._ptr);
		}
		bool operator<(const RandomAccessIterator & rhs) const{
			return (_ptr < rhs._ptr);
		}
		bool operator<=(const RandomAccessIterator & rhs) const{
			return (_ptr <= rhs._ptr);
		}
		bool operator>=(const RandomAccessIterator & rhs) const{
			return (_ptr >= rhs._ptr);
		}
		//OPERATORS
		RandomAccessIterator & operator++(){
			++_ptr;
			return (*this);
		}
		RandomAccessIterator & operator++(int){
			RandomAccessIterator tmp = *this;
			++_ptr;
			return(tmp);
		}
		RandomAccessIterator & operator--(){
			--_ptr;
			return (*this);

		}
		RandomAccessIterator & operator--(int){
			RandomAccessIterator tmp = *this;
			--_ptr;
			return(tmp);
		}
		RandomAccessIterator operator+(const difference_type & a){
			return (_ptr + a);
		}
		template<typename L>
		friend RandomAccessIterator<L> operator +(const typename RandomAccessIterator<L>::difference_type & a, const RandomAccessIterator<L> & iter){


		}
	
		RandomAccessIterator operator-(const difference_type & a){
			return(_ptr - a);
		}
		difference_type operator-(const RandomAccessIterator & b){
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


//template<typename T>class ConstRandomAccessIterator
//{
//	public:
//		typedef T				value_type;
//		typedef std::ptrdiff_t	difference_type;
//		typedef T*				pointer;
//		typedef T&				reference;
//		//this is for std::functions
//		typedef	std::random_access_iterator_tag iterator_category;
//		//this is for vector, delete later
//		template <class _Tp, class _Alloc> friend class vector;
//	private:
//		pointer					_ptr;
//		//CONSTRUCTORS
//		ConstRandomAccessIterator(pointer a){
//			_ptr = a;
//		}
//	public:
//		ConstRandomAccessIterator(){
//			_ptr = 0;
//		}
//		ConstRandomAccessIterator(const ConstRandomAccessIterator<T> & src){
//			*this = src;
//		}
//		
//		ConstRandomAccessIterator & operator=(const ConstRandomAccessIterator & src){
//			_ptr = src.ptr;
//			return (*this);
//		}
//
//		ConstRandomAccessIterator & operator=(const RandomAccessIterator<T> & src){
//			_ptr = src.ptr;
//			return (*this);
//		}
//		~ConstRandomAccessIterator(){};
//
//		//COMPARISON OPERATORS
//		bool operator==(const RandomAccessIterator<T> & rhs) const{
//			return (_ptr == rhs.ptr);
//		}
//		bool operator==(const ConstRandomAccessIterator<T> &rhs) const{
//			return (_ptr == rhs.ptr);
//		}
//		bool operator!=(const ConstRandomAccessIterator & rhs) const{
//			return (_ptr != rhs.ptr);
//		}
//		bool operator!=(const RandomAccessIterator<T> &rhs) const{
//			return (_ptr != rhs.ptr);
//		}
//		bool operator>(const ConstRandomAccessIterator<T> & rhs) const{
//			return (_ptr > rhs.ptr);
//		}
//		bool operator>(const RandomAccessIterator<T> &rhs) const{
//			return (_ptr > rhs.ptr);
//		}
//		bool operator<(const RandomAccessIterator<T> & rhs) const{
//			return (_ptr < rhs.ptr);
//		}
//		bool operator<(const ConstRandomAccessIterator<T> &rhs) const{
//			return (_ptr < rhs.ptr);
//		}
//		bool operator<=(const RandomAccessIterator<T> & rhs) const{
//			return (_ptr <= rhs.ptr);
//		}
//		bool operator<=(const ConstRandomAccessIterator<T> &rhs) const{
//			return (_ptr <= rhs.ptr);
//		}
//		bool operator>=(const ConstRandomAccessIterator<T> & rhs) const{
//			return (_ptr >= rhs.ptr);
//		}
//		bool operator>=(const RandomAccessIterator<T> &rhs) const{
//			return (_ptr >= rhs.ptr);
//		}
//		//OPERATORS
//		ConstRandomAccessIterator & operator++(){
//			++_ptr;
//			return (*this);
//		}
//		ConstRandomAccessIterator & operator++(int){
//			ConstRandomAccessIterator tmp = *this;
//			++_ptr;
//			return(tmp);
//		}
//		ConstRandomAccessIterator & operator--(){
//			--_ptr;
//			return (*this);
//
//		}
//		ConstRandomAccessIterator & operator--(int){
//			ConstRandomAccessIterator tmp = *this;
//			--_ptr;
//			return(tmp);
//		}
//		ConstRandomAccessIterator operator+(const difference_type & a){
//			return (_ptr + a);
//		}
//		template<typename L>
//		friend ConstRandomAccessIterator<L> operator +(const typename ConstRandomAccessIterator<L>::difference_type & a, const ConstRandomAccessIterator<L> & iter);
//	
//		ConstRandomAccessIterator operator-(const difference_type & a){
//			return(_ptr - a);
//		}
//		difference_type operator-(const ConstRandomAccessIterator<T> & b){
//			return(_ptr - b._ptr);
//		}
//		difference_type operator-(const RandomAccessIterator<T> & b){
//			return(_ptr - b._ptr);
//		}
//		ConstRandomAccessIterator & operator+=(const difference_type & a){
//			_ptr += a;
//			return (*this);
//		}
//		ConstRandomAccessIterator & operator-=(const difference_type & a){
//			_ptr -= a;
//			return (*this);
//		}
//		pointer operator->(){
//			return(_ptr);
//		}
//		value_type & operator*(){
//			return(*_ptr);
//		}
//		reference operator[](difference_type n) const{
//			return(*(_ptr + n));
//		}
//};

};
#endif
