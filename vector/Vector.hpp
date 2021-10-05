#ifndef VECTOR_HPP
#define VECTOR_HPP


template < class T, class Alloc = allocator<T> > class vector{


		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::iterator<T> iterator;
		typedef ft::const_iterator<T> const_iterator;
		typedef ft::reverse_iterator<T> reverse_iterator;
		typedef ft::const_reverse_iterator<T> const_reverse_iterator;	



};


#endif
