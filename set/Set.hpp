#pragma once

#include "../map/RBTree.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace ft{
	template<
			class Key,
			class Compare = std::less<Key>,
			class Allocator = std::allocator<Key> >

	class set{

	public:
		typedef Key key_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef key_compare value_compare;
		typedef key_type value_type;
		typedef Allocator allocator_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef RBTree<value_type, key_compare, allocator_type> tree_type;
		typedef typename tree_type::iterator iterator;
		typedef typename tree_type::const_iterator const_iterator;
		typedef typename tree_type::reverse_iterator reverse_iterator;
		typedef typename tree_type::const_reverse_iterator const_reverse_iterator;

	private:
		tree_type _tree;

	public:

		explicit set(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : _tree(tree_type(comp, alloc)) {}
		
		template< class InputIt >
		set(InputIt first, InputIt last, const Compare & comp = Compare(), const Allocator &alloc = Allocator()): _tree(tree_type(first, last, comp, alloc)) {}

		set(const set& other): _tree(tree_type(other._tree)) {}


		set operator=(const set & other){
			this->_tree = other._tree;
			return (*this);
		}

		allocator_type get_allocator() const{
			return _tree.get_allocator();
		}

		size_type size() const{
			return (_tree.size());
		}

		size_type max_size() const{
			return (_tree.max_size());
		}

		bool empty() const{
			return (_tree.empty());
		}

		value_compare value_comp() const{
			return (_tree.value_comp());
		}

		key_compare key_comp() const{
			return (value_comp());
		}

		iterator begin() {
			return (_tree.begin());
		}

		const_iterator begin() const {
			return (_tree.begin());
		}

		iterator end() {
			return (_tree.end());
		}

		const_iterator end() const {
			return (_tree.end());
		}

		reverse_iterator rbegin() {
			return (_tree.rbegin());
		}

		const_reverse_iterator rbegin() const {
			return (_tree.rbegin());
		}

		reverse_iterator rend() {
			return (_tree.rend());
		}

		const_reverse_iterator rend() const{
			return (_tree.rend());
		}
       
	   	void clear(){
			_tree.clear();
		}	

		void swap(set & other) {
			_tree.swap(other._tree);
		}

		iterator find(const Key& key) {
			return _tree.find(key);
		}
		
		const_iterator find(const Key& key) const {
			return _tree.find(key);
		}

		size_type count(const Key &key) const{
			return _tree.count(key);
		}

		iterator lower_bound(const key_type& k){
			return _tree.lower_bound(k);
		}

		const_iterator lower_bound(const key_type& k) const{
			return _tree.lower_bound(k);
		}

		iterator upper_bound(const key_type& k){
			return _tree.lower_bound(k);
		}

		const_iterator upper_bound(const key_type& k) const{
			return _tree.lower_bound(k);
		}
		
		pair<iterator, iterator> equal_range(const key_type & k){
			return _tree.equal_range(k);
		}

		pair<const_iterator, const_iterator> equal_range(const key_type & k) const{
			return _tree.equal_range(k);
		}

		ft::pair<iterator, bool> insert( const value_type& value ){
			return _tree.insert(value);
		}

		iterator insert( iterator hint, const value_type& value) {
			return _tree.insert(hint, value);
		}

		template<class InputIt>
		void insert(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt>::type first, InputIt last){
			_tree.insert(first, last);
		}

		void erase(iterator pos){
			_tree.erase(pos);
		}

		size_type erase(const Key & key){
			return _tree.erase(key);
		}

		void erase(iterator first, iterator last){
			_tree.erase(first, last);
		}

		template<class K, class Com, class Al>
		friend bool operator==(const set<K, Com, Al>& lhs, const set<K, Com, Al>& rhs);

		template<class K, class Com, class Al>
		friend bool operator<(const set<K, Com, Al>& lhs, const set<K, Com, Al>& rhs);

	};

	template<class Key, class Compare, class Alloc>
	bool operator==(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs){
		return lhs._tree == rhs._tree;
	}

	template<class Key, class Compare, class Alloc>
	bool operator!=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs){
		return !(lhs == rhs);
	}

	template<class Key, class Compare, class Alloc>
	bool operator<(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs){
		return lhs._tree < rhs._tree;
	}

	template<class Key, class Compare, class Alloc>
	bool operator>(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs){
		return rhs < lhs;
	}

	template<class Key, class Compare, class Alloc>
	bool operator<=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs){
		return !(lhs > rhs);
	}

	template<class Key, class Compare, class Alloc>
	bool operator>=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs){
		return !(lhs < rhs);
	}

		
};

namespace std {
	template<class Key,class Compare, class Alloc>
	void swap(const ft::set<Key, Compare, Alloc>& lhs,
			  const ft::set<Key, Compare, Alloc>& rhs) {
		lhs.swap(rhs);
	}
}
