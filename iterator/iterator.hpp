#include <iostream>
//TESTING GIT (THIS IS MASTER ONLY MESSAGE)

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
		friend iterator<L> operator +(const typename iterator<L>::difference_type & a, const iterator<L> & iter);
	

		//template<typename L>
		//friend iterator<L> operator+(const typename iteraror<L>::difference_type & a, const iterator<L> & iter);
	
		iterator operator-(const difference_type & a){
			return(_ptr - a);
		}
		difference_type operator-(const iterator & b){
			return(_ptr - b._ptr);
		}
		difference_type operator-(const const_iterator<T> & b){
			return(_ptr - b._ptr);
		}
		iterator & operator+=(const difference_type & a){
			_ptr += a;
			return (*this);
		}
		iterator & operator-=(const difference_type & a){
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


template<typename T>class const_iterator
{
	public:
		typedef T				value_type;
		typedef std::ptrdiff_t	difference_type;
		typedef T*				pointer;
		typedef T&				reference;
		pointer					_ptr;

		const_iterator(){
			_ptr = 0;
		}
		const_iterator(const const_iterator & src){
			*this = src;
		}
		const_iterator(const iterator<T> & src){
			*this = src;
		}
		const_iterator(pointer rhs)
		{
			this->ptr = rhs;
		}
		const_iterator & operator=(const const_iterator & src){
			_ptr = src.ptr;
			return (*this);
		}
		const_iterator & operator=(const iterator<T> & src){
			_ptr = src.ptr;
			return (*this);
		}
		~const_iterator(){};

		//COMPARSION OPERATORS
		bool operator==(const const_iterator & rhs) const{
			return (_ptr == rhs.ptr);
		}
		bool operator!=(const const_iterator & rhs) const{
			return (_ptr != rhs.ptr);
		}
		bool operator>(const const_iterator & rhs) const{
			return (_ptr > rhs.ptr);
		}
		bool operator<(const const_iterator & rhs) const{
			return (_ptr < rhs.ptr);
		}
		bool operator<=(const const_iterator & rhs) const{
			return (_ptr <= rhs.ptr);
		}
		bool operator>=(const const_iterator & rhs) const{
			return (_ptr >= rhs.ptr);
		}
		const_iterator & operator++(){
			++_ptr;
			return (*this);
		}
		const_iterator & operator++(int){
			const_iterator tmp = *this;
			++_ptr;
			return(tmp);
		}
		const_iterator & operator--(){
			--_ptr;
			return (*this);
		}
		const_iterator & operator--(int){
			const_iterator tmp = *this;
			--_ptr;
			return(tmp);
		}
		const_iterator operator+(const difference_type & a){
			return (_ptr + a);
		}
		template<typename L>
		friend const_iterator<L> operator +(const typename const_iterator<L>::difference_type & a, const const_iterator<L> & iter);
	

		//template<typename L>
		//friend const_iterator<L> operator+(const typename iteraror<L>::difference_type & a, const const_iterator<L> & iter);
	
		const_iterator operator-(const difference_type & a){
			return(_ptr - a);
		}
		difference_type operator-(const const_iterator & b){
			return(_ptr - b._ptr);
		}
		const_iterator & operator+=(const difference_type & a){
			_ptr += a;
			return (*this);
		}
		const_iterator & operator-=(const difference_type & a){
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

template<typename T>class const_reverse_iterator;
template<typename T>class reverse_iterator;

};

