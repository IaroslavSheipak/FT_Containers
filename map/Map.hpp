#pragma once

#include "RBTree.hpp"

namespace ft {

	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >

	class map{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef ft::pair<const Key, T> value_type;
		typedef Allocator allocator_type;
		typedef const value_type & reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

	private:
		class pair_compare {
			key_compare _compare;

			public:
				pair_compare(const key_compare & compare) : _compare(compare) {}

				bool operator()(const value_type & x, const value_type & y) const{
					return (_compare(x.first, y.first));
				}
		};
	public:
		typedef RBTree<value_type, pair_compare, allocator_type> tree_type;
		typedef typename tree_type::iterator iterator;
	
	private:
		allocator_type	_alloc;
		tree_type		_tree;
		key_compare		_compare;
	
	public:

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):
			_alloc(alloc), _tree(tree_type(comp, alloc)), _compare(compare) {}

		template< class InputIt >
		map(InputIt first, InputIt last, const Compare& compare = Compare(), const Allocator& alloc = Allocator()):
			_alloc(alloc), _tree(first, last, compare, _alloc), _compare(compare) {}
	
		mapped_type& operator[](const key_type& key){
			return (_tree.insert(ft::make_pair(key, mapped_type())).first->second);
		}

		allocator_type get_allocator() const{
			return (_tree.get_allocator());
		}

		size_type size() const {
			return (_tree.size());
		}

		size_type max_size() const{
			return (_tree.max_size());
		}

		bool empty() const{
			return (_tree.empty());
		}

		iterator begin(){
			return (_tree.begin());
		}

		iterator end() {
			return (_tree.end());
		}

		void clear() {
			_tree.clear();
		}

		T& at(const Key & key){
			if(key > _tree.end())
				throw std::exception("map");
		}

		ft::pair<iterator, bool> insert(const value_type& value){
			return (_tree.insert(value));
		}

		void erase(iterator pos){
			_tree.erase(pos);
		}
		
	};

};
