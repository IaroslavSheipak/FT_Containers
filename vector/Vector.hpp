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
		typedef ft::RandomAccessIterator<const T> const_iterator;
		//typedef ft::reverse_iterator<T> reverse_iterator;
		//typedef ft::const_reverse_iterator<T> const_reverse_iterator;
	private:
		pointer		_first;
		size_type 	_size, _capacity;
		allocator_type	_allocator;
		
		template<class InputIt>
		void Ucopy(InputIt first, InputIt last, InputIt dist){
			dist += (last - first);
			last--;
			while (first < last && dist.base() != NULL)
			{
				_allocator.construct(dist.base(), *last);
				last--;
				dist--;
			}
			while (first < last)
			{
				*dist = *last;
				last--;
				dist--;
			}
		}

	public:
		//CONSTRUCTORS
		
		//default		
		explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _allocator(alloc){}

		//fill
		explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _allocator(alloc)
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

		//OPERATOR=
		vector& operator= (const vector& x){
			_capacity = x._capacity;
			_size = x._size;
			_allocator = x._allocator;
			_first = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				*(_first + i) = _allocator.construct(_first + i, x[i]);
			return (*this);
		}

		//copy
		vector (const vector& x){
			*this = x;
		}
		
		//DESTRUCTOR
		~vector()
		{
			if(_first != 0)
			{
				for(size_type i = 0; i < _size; i++)
					_allocator.destroy(_first + i);
				if(_capacity != 0)
					_allocator.deallocate(_first, _capacity);
			}
		}

		

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
	
	

		void reserve (size_type n){
			if (n < _capacity)
				return;
			T* newarr = _allocator.allocate(n);
			try{
				std::uninitialized_copy(_first, _first + _size, newarr);
			} catch (...){
				_allocator.deallocate(newarr, n);
				throw;
			}
			for(int i = 0; i < _size; i++){
				_allocator.destroy(_first + i);
			}
			//without this if free error
			if(_capacity != 0)
				_allocator.deallocate(_first, _capacity);
			_first = newarr;
			_capacity = n;
		}

		void resize (size_type n, value_type val = value_type()){
			if(n > _capacity)
				reserve(n);
			for(size_t i = 0; i < _size; i++)
				new (_first + i) T(val);
			if (n < _size)
				_size = n;
				
		}
		
		size_type capacity() const{
			return (_capacity);
		}
		bool empty() const{
			return(_size == 0);
		}
		
		
		//ELEMENT ACCESS
		
		
		reference operator[] (size_type n){
			return(*(_first + n));
		}
		const_reference operator[] (size_type n) const{
			return(*(_first + n));
		}
		
		reference at (size_type n){
			if(n > _capacity)
				throw std::out_of_range("vector at out of range");
			return(*(_first + n));
		}
		
		const_reference at (size_type n) const{
			if(n > _capacity)
				throw std::out_of_range("vector at out of range");
			return(*(_first + n));
		}
		
		reference front(){
			return(*_first);
		}
		
		const_reference front() const{
			return(*_first);
		}
		
		reference back(){
			return(*(_first + _size - 1));
		}
		
		const_reference back() const{
			return(*(_first + _size - 1));
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
		iterator insert (iterator position, const value_type& val){
			T* newarr = _allocator.allocate(_size); 
			size_t i;

			for(i = 0; i < position - begin(); i++)
				_allocator.construct(newarr + i, *(_first + i));  
			_allocator.construct(newarr + (position - begin()), val);
			for(i = (position - begin()) + 1; i < _size; i++)
				_allocator.construct(newarr + i, *(_first + i));  
			for(int i = 0; i < _size; i++){
				_allocator.destroy(_first + i);
			}	
			//if(_capacity != 0)
			//	_allocator.deallocate(_first, _capacity);
			_first = newarr;
			_size++;
			return begin();
		}

		//fill
		void insert (iterator position, size_type n, const value_type& val){
			if (n == 0)
				return ;
			else if (max_size() - _size < n || position < begin())
				throw std::length_error("vector");
			if ((_size + n <= _capacity && position <= end()) || (position > end() && position - begin() + n <= _capacity))
			{
				Ucopy(position, end(), end() + n);
				iterator tmp_end = position + n;
				_size = position <= end() ? _size + n : position - begin() + n;
				while (position != tmp_end)
				{
					*position = val;
					position++;
				}
			}
		}

		//range
		template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last);

		//single element
		iterator erase (iterator position){
			difference_type d = std::distance(begin(), position);
			std::copy(position + 1, end(), position);
			_size--;
			_allocator.destroy(_first + _size - 1);
			return (d == _size ? end() : iterator(_first + d));
		}

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
