#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
//#include <iterator>
#include "../utility/utility.hpp"
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
		typedef ft::RandomAccessIterator<T, false> iterator;
		typedef ft::RandomAccessIterator<T, true> const_iterator;
		//typedef ft::reverse_iterator<T> reverse_iterator;
		//typedef ft::const_reverse_iterator<T> const_reverse_iterator;
	private:
		pointer		_first;
		size_type 	_size, _capacity;
		allocator_type	_allocator;
		
		template<class InputIt>
		void Ucopy(InputIt first, InputIt last, InputIt dist){
			dist += last - first - 1;
			last--;
			while (last >= first)
			{
				_allocator.destroy(dist.base());
				_allocator.construct(dist.base(), *last);
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
			_first = _allocator.allocate(n);
			for(size_type i = 0; i < n; i++)
				_allocator.construct(_first + i, val);
		}

		//range
		template <class InputIterator>
        	 vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<InputIterator>::value>::type* = 0){
			if (first > last)
				throw std::length_error("vector");
			_size = last - first;
			_capacity = _size;
			_first = _allocator.allocate(_capacity);
			for (difference_type i = 0; i < _size; i++)
				_allocator.construct(_first + i, *(first + i));
		 }

		//OPERATOR=
		vector& operator= (const vector& x){
			if (_capacity != 0)
				_allocator.deallocate(_first, _capacity);
			_capacity = x._capacity;
			_size = x._size;
			_allocator = x._allocator;
			_first = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_first + i, x[i]);
			return (*this);
		}

		//copy
		vector (const vector& x){
			*this = x;
		}
		
		//DESTRUCTOR
		~vector()
		{
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_first + i);
			if(_capacity)
				_allocator.deallocate(_first, _capacity);
		}

		

		//ITERATORS
		iterator begin(){
			return (iterator(_first));
		}
		const_iterator begin() const{
			return (const_iterator(_first));
		}
		iterator end(){
			return (iterator(_first + _size));
		}
		const_iterator end() const{
			return (const_iterator(_first + _size));
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
			pointer newarr = _allocator.allocate(n);
			try{
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(newarr + i, *(_first + i));
			} catch (std::exception &e){
				size_type i = 0;
				while (newarr + i != NULL && i < _size){
					_allocator.destroy(newarr + i);
					i++;
				}
				_allocator.deallocate(newarr, n);
				throw;
			}
			for(int i = 0; i < _size; i++)
				_allocator.destroy(_first + i);
			if(_capacity)
				_allocator.deallocate(_first, _capacity);
			_capacity = n;
			_first = newarr;
		}

		void resize (size_type n, value_type val = value_type()){
			if(n < _size){
				for(size_type i = n; i < _size; i++)
					_allocator.destroy(_first + i);
				_size = n;
			}
			else if (n > _size){
				if (_capacity < n)
					this->reserve(_capacity * 2 > n ? _capacity * 2 : n);
				for (size_type i = _size; i < n; i++){
					_allocator.construct(_first + i, val);
					_size++;
				}
			}
				
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
  			void assign (InputIterator first, InputIterator last){
				if(first > last)
					throw std::logic_error("vector");
				difference_type count = last - first;
				clear();
				if (count > static_cast<difference_type>(capacity())){
					_allocator.deallocate(_first, _capacity);
					_first = _allocator.allocate(count);
					_capacity = count;
				}
				iterator pos = begin();
				while (first < last)
				{
					_allocator.construct(pos.base(), *first);
					pos++;
					first++;
				}
				_size = count;
			}

		void assign (size_type n, const value_type& val){
			clear();
			if (n > _capacity){
				_allocator.deallocate(_first, _capacity);
				_first = _allocator.allocate(n);
				_capacity = n;
			}
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_first + i, val);
			_size = n;
		}
		
		void push_back (const value_type& val){
			if(_size == _capacity)
				reserve(_capacity == 0 ? 1 : _capacity * 2);
			_allocator.construct(_first + _size, val);
			_size++;
		}

		void pop_back(){
			_allocator.destroy(_first + _size - 1);
			_size--;
		}

		//single element
		iterator insert (iterator position, const value_type& val){
			if (position < begin() || position > end())
				throw std::logic_error("vector");
			difference_type start = position - begin();
			if (_size + 1 > _capacity)
				reserve(_capacity == 0 ? 1 : _capacity * 2);
			position = begin() + start;
			Ucopy(position, end(), position + 1);
			if (position.base())
				_allocator.destroy(position.base());
			_allocator.construct(position.base(), val);
			_size++;
		}

		//fill
		void insert (iterator position, size_type n, const value_type& val){
			if (n == 0)
				return ;
			else if (max_size() - _size < n || position < begin())
				throw std::length_error("vector");
			difference_type start = position - begin();
			if (_size + n > _capacity)
				reserve(_capacity * 2 >= _size + n ? _capacity * 2 : _size + n);
			position = _first + start;
			//Ucopy(position, end(), position + n);
			std::uninitialized_copy(position, end(), position + n);
			for (size_type i = 0; i < n; i++){
				if ((position + i).base())
					_allocator.destroy((position + i).base());
				_allocator.construct((position + i).base(), val);
			}
			_size += n;
		}

		//range
		template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type* = 0){
				if (position < begin() || position > end() || first > last)
					throw std::logic_error("vector");
				difference_type start = position - begin();
				difference_type count = last - first;
				if (_size + count > _capacity)
					reserve(_capacity * 2 >= _size + count ? _capacity * 2 : _size + count);
				position = begin() + start;
				Ucopy(position, end(), position + count);
				while (first < last){
					if (position.base())
						_allocator.destroy(position.base());
					_allocator.construct(position.base(), *first);
					position++;
					first++;
				}
				_size += count;
			}

		//single element
		iterator erase (iterator position){
			difference_type d = std::distance(begin(), position);
			std::copy(position + 1, end(), position);
			_size--;
			_allocator.destroy(_first + _size - 1);
			return (d == _size ? end() : iterator(_first + d));
		}

		//range
		iterator erase (iterator first, iterator last){
			difference_type start = std::distance(begin(), first);
			difference_type need_to_copy = std::distance(last, end());
			bool last_is_end = (last == end());
			while (first != last){
				_allocator.destroy(first.base());
				first++;
			}
			size_type i = start;
			while (last < end()){
				if (this->_first + start)
					_allocator.destroy(_first + i);
				_allocator.construct(_first + i, *last);
				i++;
				last++;
			}
			for (size_type i = start + need_to_copy; i < _size; i++)
				_allocator.destroy(_first + i);
			_size = start + need_to_copy;
			return last_is_end ? end() : iterator(_first + start);
		}
		
		void swap (vector& x){
			pointer tmp = _first;
			_first = x._first;
			x._first = tmp;
		}

		void clear(){
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(_first + i);
			_size = 0;
		}

		//ALLOCATOR
		allocator_type get_allocator() const{
			return(_allocator);
		}
};

	template< class T, class Alloc >
	bool operator==( const vector<T,Alloc>& lhs,
			                 const vector<T,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < rhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	}

	template< class T, class Alloc >
	bool operator!=( const vector<T,Alloc>& lhs,
		                 const vector<T,Alloc>& rhs ){
		return !(lhs == rhs);
	}

	template< class T, class Alloc >
	bool operator<( const vector<T,Alloc>& lhs,
		                const vector<T,Alloc>& rhs ){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	
	template< class T, class Alloc >
	bool operator<=( const vector<T,Alloc>& lhs,
		                 const vector<T,Alloc>& rhs ){
		return !(lhs > rhs);
	}
	
	template< class T, class Alloc >
	bool operator>( const vector<T,Alloc>& lhs,
		                const vector<T,Alloc>& rhs ){
		return rhs < lhs;
	}

	template< class T, class Alloc >
	bool operator>=( const vector<T,Alloc>& lhs,
		                 const vector<T,Alloc>& rhs ){
		return !(lhs < rhs);
	}

	
	template< class T, class Alloc >
	void swap( vector<T,Alloc>& lhs, vector<T,Alloc>& rhs ) {
		lhs.swap(rhs);
	}

};
#endif
