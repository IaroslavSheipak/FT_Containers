#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include "../iterator/iterator.hpp"

namespace ft{



template < class T, class Allocator = std::allocator<T> > class vector{

	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::RandomAccessIterator<T> iterator;
		typedef ft::ConstRandomAccessIterator<T> const_iterator;
		//typedef ft::reverse_iterator<T> reverse_iterator;
		//typedef ft::const_reverse_iterator<T> const_reverse_iterator;
	private:
		pointer		_first;
		size_type 	_size, _capacity;
		allocator_type	_allocator;


	public:
		//CONSTRUCTORS
		
		//default		
		explicit vector (const allocator_type& alloc = allocator_type()) {}

		//fill
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n)
		{
			_first = _allocator.allocate(_capacity);
			for(size_type i = 0; i < n; i++)
				_allocator.construct(_first + i, val);
		}

		//range
		template <class InputIterator>
        	 vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
		 {
			difference_type dist = std::distance(first, last);
			_first = _allocator.allocate(dist);

			for(difference_type i = 0; i < dist; i++)
				_allocator.construct(_first + i, *(first + i));

		 }

		//copy
		vector (const vector& x) : _allocator(x._allocator), _size(x._size()), _capacity(x._capacity)
		{
			for(size_type i = 0; i < _size; i++)
				_allocator.construct(_first + i, *(x._first + i));
		}
		
		//DESTRUCTOR
		~vector()
		{
			if(_first != 0)
			{
				//for(size_type i = 0; i < _size; i++)
				//	_allocator.destroy(_first + i);
				_allocator.deallocate(_first, _capacity);
			}
		}

		
		//OPERATOR=
		vector& operator= (const vector& x);

		//ITERATORS
		iterator begin(){
			return (iterator(_first));
		}
		const_iterator begin() const{
			return (iterator(_first));
		}
		iterator end(){
			return (iterator(_first + _size));
		}
		const_iterator end() const{
			return (iterator(_first + _size));
		}
		/*reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;*/
		
		//CAPACITY
		
		
		size_type size() const{
			return(_size);
		}
		size_type max_size() const{
			return(_allocator.max_size());
		}
		
		void resize (size_type n, value_type val = value_type());
		
		size_type capacity() const{
			return (_capacity);
		}
		bool empty() const{
			return(_size == 0);
		}
		
		void reserve (size_type n);
		
		//ELEMENT ACCESS
		
		
		reference operator[] (size_type n){
			return(*(_first + n));
		}
		const_reference operator[] (size_type n) const{
			return(*(_first + n));
		}
		
		reference at (size_type n){
			return(*this[n]);
		}
		
		const_reference at (size_type n) const{
			return(*this[n]);
		}
		
		reference front(){
			return(*this[0]);
		}
		
		const_reference front() const{
			return(*this[0]);
		}
		
		reference back(){
			return(*this[_size - 1]);
		}
		
		const_reference back() const{
			return(*this[_size - 1]);
		}

		//MODIFIERS
		template <class InputIterator>
  			void assign (InputIterator first, InputIterator last);

		void assign (size_type n, const value_type& val);
		
		void push_back (const value_type& val){
			*this->insert(end() - 1, val);
		}

		void pop_back(){
			*this->erase(end() - 1);
		}

		//single element
		iterator insert (iterator position, const value_type& val);

		//fill
		void insert (iterator position, size_type n, const value_type& val);

		//range
		template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last);

		//single element
		iterator erase (iterator position);

		//range
		iterator erase (iterator first, iterator last);
		
		void swap (vector& x);

		void clear(){
			erase(front(), back());
		}

		//ALLOCATOR
		allocator_type get_allocator() const{
			return(_allocator);
		}
};


};
#endif
