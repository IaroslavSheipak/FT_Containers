#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>

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
		//typedef ft::iterator<T> iterator;
		//typedef ft::const_iterator<T> const_iterator;
		//typedef ft::reverse_iterator<T> reverse_iterator;
		//typedef ft::const_reverse_iterator<T> const_reverse_iterator;
	private:
		pointer		_first;
		size_type 	_size, _capacity;
		allocator_type	_allocator;


	public:
		//CONSTRUCTOR
		explicit vector (const allocator_type& alloc = allocator_type()) {}


		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n)
		{
			_first = _allocator.allocate();

		}


		template <class InputIterator>
        	 vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
		 {
			difference_type dist = std::distance(first, last);
			_first = _allocator.allocate(dist);

			for(difference_type i = 0; i < dist; i++)
				_allocator.construct(_first + i, *(first + i));

		 }


		vector (const vector& x) : _allocator(x._allocator), _size(x._size()), _capacity(x._capacity)
		{
			for(size_type i = 0; i < _size; i++)
				_allocator.construct(_first + i, *(x._first + i));
		}




};


};
#endif
