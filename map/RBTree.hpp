#pragma once
#include <memory>
#include "../iterator/reverse_iterator.hpp"
#include "../iterator/tree_iterator.hpp"
#include "../utility/utility.hpp"


template<class Value, class Compare = std::less<Value>, class Alloc = std::allocator<Value> >
class RBTree{
	public:
		typedef Value value_type;
		typedef Compare value_compare;
		typedef Alloc	allocator_type;
		typedef typename Alloc::template
			                rebind<Node<Value> >::other            node_allocator;
		//typedef Node_Alloc node_allocator_type;
		typedef	typename node_allocator::pointer node_pointer;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef std::ptrdiff_t	difference_type;
		typedef std::size_t	size_type;
		typedef TreeIter<Value>			iterator;
		typedef TreeIter<const Value>	const_iterator;
		typedef	ft::reverse_iterator<iterator> reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator> const_reverse_iterator;
	private:
		allocator_type				_val_alloc;
		node_allocator				_node_alloc;
		value_compare 				_compare;
		node_pointer				_nil;
		node_pointer				_header;
		node_pointer				_root;
		size_type					_size;
		
		//HELPER FUNCTIONS
		node_pointer	tree_min(node_pointer n) const{
			while (n != NULL && !is_nil(n->left))
				n = n->left;
			return n;
		}
		
		node_pointer	tree_max(node_pointer n) const{
			while (n != NULL && !is_nil(n->right))
				n = n->right;
			return n;
		}
		
		void 	_rotate_right(node_pointer	node){
			node_pointer y;

			y = node->left;
			node->left = y->right;
			if (!is_nil(y->right))
				y->right->parent = node;
			y->parent = node->parent;
			if (node->parent == NULL)
				_root = y;
			else if (node == node->parent->left)
				node->parent->left = y;
			else
				node->parent->right = y;
			y->right = node;
			node->parent = y;
		}
		void 	_rotate_left(node_pointer	node){
			node_pointer y;

			y = node->right;
			node->right = y->left;
			if (!is_nil(y->left))
				y->left->parent = node;
			y->parent = node->parent;
			if (node->parent == NULL)
				_root = y;
			else if (node == node->parent->left)
				node->parent->left = y;
			else
				node->parent->right = y;
			y->left = node;
			node->parent = y;
		}
		node_pointer	_insert(node_pointer new_node){
			if (_root == _header)
				_root = new_node;
			else
				_insert_to_node(_root, new_node);
		   return new_node;	
		}

		node_pointer	_insert_to_node(node_pointer root, node_pointer new_node){
			if (_compare(*new_node->value, *root->value)){
				if (!is_nil(root->left))
					return (_insert_to_node(root->left, new_node));
				root->left = new_node;
			}
			else{
				if (!is_nil(root->right))
					return (_insert_to_node(root->right, new_node));
				root->right = new_node;
			}
			new_node->parent = root;
			return (new_node);
		}
		
		node_pointer _insert_into_tree(node_pointer new_node, node_pointer where){
			if (_root == _header)
				_root = new_node;
			else
				_insert_to_node(where, new_node);
			return (new_node);
		}

		void _insert_fixup(node_pointer node){
			if (node != _root && node->parent != _root){
				while (node != _root && !node->parent->is_black){
					if (node->parent == node->parent->parent->left){
						node_pointer uncle = node->parent->parent->right;
						if (!uncle->is_black){
							node->parent->is_black = true;
							uncle->is_black = true;
							node->parent->parent->is_black = false;
							node = node->parent->parent;
						}
						else {
							if (node == node->parent->right){
								node = node->parent;
								_rotate_left(node);
							}
							node->parent->is_black = true;
							node->parent->parent->is_black = false;
							_rotate_right(node->parent->parent);
						}
					}
					else{
						node_pointer uncle = node->parent->parent->left;
						if (!uncle->is_black){
							node->parent->is_black = true;
							uncle->is_black = true;
							node->parent->parent->is_black = false;
							node = node->parent->parent;
						}
						else{
							if (node == node->parent->left){
								node = node->parent;
								_rotate_right(node);
							}
							node->parent->is_black = true;
							node->parent->parent->is_black = false;
							_rotate_left(node->parent->parent);
						}
					}
				}
			}
			_root->is_black = true;
		}

		bool is_nil(node_pointer node) const {
			return node == _nil || node == _header;
		}

		void clear_node(node_pointer node){
			if (node && !is_nil(node)) {
				clear_node(node->right);
				clear_node(node->left);
				_val_alloc.destroy(node->value);
				_val_alloc.deallocate(node->value, 1);
				_node_alloc.deallocate(node, 1);
				
			}
		}
	
		void	init_nil_head(){
			_nil = _node_alloc.allocate(1);
			_node_alloc.construct(_nil, Node<Value>());
			_nil->is_black = true;
			_nil->is_nil = true;
			_header = _node_alloc.allocate(1);
			_node_alloc.construct(_header, Node<Value>());
			_header->value = _val_alloc.allocate(1);
			_val_alloc.construct(_header->value, Value());
			_header->is_black = true;
		}
		void transplant(node_pointer where, node_pointer what) {
			if (where == _root)
				_root = what;
			else if (where == where->parent->left)
				where->parent->left = what;
			else
				where->parent->right = what;
			what->parent = where->parent;
		}
		
		void 	free_node(node_pointer node){
			_val_alloc.destroy(node->value);
			_val_alloc.deallocate(node->value, 1);
			_node_alloc.deallocate(node, 1);
		}

		//void _visualize(int tabs , node_pointer root, bool new_str){
		//	if (root == _nil)
		//		return;
		//	std::string color = root->is_black == true ? "\x1b[m" : "\x1b[31;1m" ;
		//	for(int i = 0; i < tabs; i++)
		//		std::cout << '\t';
		//	std::cout << color << *root->value << "\x1b[31;1m" << std::endl;
		//	_visualize(tabs-1, root->left, false);
		//	_visualize(2, root->right, true);
		//	
		//
		//}	

		//PUBLIC FUNCTIONS
	public:
		iterator	end(){
			return (iterator(_header));
		}

		const_iterator	end() const{
			return (const_iterator(_header));
		}

		iterator	begin(){
			return (iterator(_size == 0 ? _header : iterator(tree_min(_root))));
		}
		const_iterator	begin() const{
			return (const_iterator(_size == 0 ? _header : const_iterator(tree_min(_root))));
		}

		reverse_iterator rbegin(){
			return (reverse_iterator(end()));
		}	
		const_reverse_iterator rbegin() const{
			return (const_reverse_iterator(end()));
		}	

		reverse_iterator rend(){
			return (reverse_iterator(begin()));
		}	

		const_reverse_iterator rend() const{
			return (const_reverse_iterator(begin()));
		}	

		pointer	create_value(const value_type &value){
			pointer new_val = _val_alloc.allocate(1);
			_val_alloc.construct(new_val, value);
			return new_val;
		}	
		node_pointer copy_node(node_pointer other){
			node_pointer new_node = _node_alloc.allocate(1);
			_node_alloc.construct(new_node, Node<Value>());
			new_node->is_black = other->is_black;
			new_node->is_nil = other->is_nil;
			if (other->value){
				new_node->value = _val_alloc.allocate(1);
				_val_alloc.construct(new_node->value, *other->value);
			}
			return (new_node);
		}
	
		void	copy_child(node_pointer my_node, node_pointer other){
			if (other->left->is_nil)
				my_node->left = _nil;
			else {
				my_node->left = copy_node(other->left);
				my_node->left->parent = my_node;
				copy_child(my_node->left, other->left);
			}
			if (other->right->is_nil)
				my_node->right = _nil;
			else if (other->right->right == NULL){
				my_node->right = _header;
				_header->parent = my_node;
			}
			else{
				my_node->right = copy_node(other->right);
				my_node->right->parent = my_node;
				copy_child(my_node->right, other->right);
			}
		}

		node_pointer	search(const value_type &value, node_pointer node) const
		{
			if(!node || is_nil(node))
				return NULL;
			if (_compare(value, *node->value))
				return search(value, node->left);
			if (_compare(*node->value, value))
				return search(value, node->right);
			return node;
		}

		iterator	find(const value_type& value){
			node_pointer find_res = search(value, _root);
			return (find_res == NULL ? end() : iterator(find_res));
		}

		const_iterator	find(const value_type& value) const{
			node_pointer find_res = search(value, _root);
			return (find_res == NULL ? end() : const_iterator(find_res));
		}
		
		ft::pair<iterator, bool> /*pohui*/ insert(value_type const &value){
			node_pointer find_val = search(value, _root);
			if (find_val)
				return ft::pair<iterator, bool>(iterator(find_val), false);
			node_pointer new_node = _node_alloc.allocate(1);
			_node_alloc.construct(new_node, Node<value_type>(create_value(value)));
			new_node->left = _nil;
			new_node->right = _nil;
			_insert_into_tree(new_node, _root);
			ft::pair<iterator, bool> res(iterator(new_node), true);
			_insert_fixup(new_node);
			_size++;
			new_node = tree_max(_root);
			new_node->right = _header;
			_header->parent = new_node;
			return res;
		} 

		iterator insert(iterator position, const value_type& value){
			node_pointer new_node = search(value,_root);
			if (new_node)
				return (iterator(new_node));
			new_node = _node_alloc.allocate(1);
			_node_alloc.construct(new_node, Node<value_type>(create_value(value)));
			new_node->left = _nil;
			new_node->right = _nil;
			if (position == begin()){
				if (position != end() && _compare(value, *position))
					_insert_into_tree(new_node, tree_min(_root));
				else
					_insert_into_tree(new_node, _root);
			}
			else if (position == end()){
				if (position != begin() && _compare(*(--position), value))
					_insert_into_tree(new_node, _header->parent);
				else
					_insert_into_tree(new_node, _root);
			}
			else
				_insert_into_tree(new_node, _root);
			_insert_fixup(new_node);
			_size++;
			node_pointer max_of_tree = tree_max(_root);
			max_of_tree->right = _header;
			_header->parent = max_of_tree;
			return (iterator(new_node));
		}
		
		template<class InputIt>
		void insert(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first,
				InputIt last) {
		for (; first != last; ++first)
			insert(*first);
		}


		void erase(iterator pos){
			node_pointer y = pos.node(), x, for_free = y;
			bool y_original_is_black = y->is_black;
			if (is_nil(y->left)){
				x = y->right;
				transplant(y, y->right);
			}
			else if (is_nil(y->right)){
				x = y->left;
				transplant(y, y->left);
			}
			else {
				node_pointer z = y;
				y = tree_min(z->right);
				y_original_is_black = y->is_black;
				x = y->right;
				if (y->parent != z){
					transplant(y, y->right);
					y->right = z->right;
					z->right->parent = y;
				}
				transplant(z, y);
				y->left = z->left;
				y->left->parent = y;
				y->is_black = z->is_black;
			}
			free_node(for_free);
			if (y_original_is_black)
				erase_fixup(x);
			_size--;
			_nil->parent = NULL;
			if (_size == 0)
				_root = _header;
			else{
				if (_size != 1)
					x = tree_max(_root);
				else
					x = _root;
				x->right = _header;
				_header->parent = x;
			}
		}

		size_type erase(const value_type& value){
			node_pointer res = search(value, _root);
			if (res)
				erase(iterator(res));
			return (res != NULL);
		}

		void erase(iterator first, iterator last){
			while (first != last)
				erase(first++);
		}

		void erase_fixup(node_pointer x){
			node_pointer brother;
			while (x != _root && x->is_black){
				if (x == x->parent->left){
					brother = x->parent->right;
					//case 1
					if (!brother->is_black){
						brother->is_black = true;
						x->parent->is_black = false;
						_rotate_left(x->parent);
						brother = x->parent->right;
					}
					//case 2
					if (brother->left->is_black && brother->right->is_black){
						brother->is_black = false;
						x = x->parent;
					}
					else{
					//case 3
						if (brother->right->is_black){
							brother->left->is_black = true;
							brother->is_black = false;
							_rotate_right(brother);
							brother = x->parent->right;
						}
					//case 4
						brother->is_black = x->parent->is_black;
						x->parent->is_black = true;
						brother->right->is_black = true;
						_rotate_left(x->parent);
						x = _root;
					}
				}
				else{
					brother = x->parent->left;
					//case 1
					if (!brother->is_black){
						brother->is_black = true;
						x->parent->is_black = false;
						_rotate_right(x->parent);
						brother = x->parent->left;
					}
					//case 2
					if (brother->right->is_black && brother->left->is_black){
						brother->is_black = false;
						x = x->parent;
					}
					else{
					//case 3
						if (brother->left->is_black){
							brother->right->is_black = true;
							brother->is_black = false;
							_rotate_left(brother);
							brother = x->parent->left;
						}
					//case 4
						brother->is_black = x->parent->is_black;
						x->parent->is_black = true;
						brother->left->is_black = true;
						_rotate_right(x->parent);
						x = _root;
					}
				}
			}
		}
		//CONSTRUCTORS
		RBTree(const Compare &comp, const allocator_type& a = allocator_type()):
				 _val_alloc(a), _node_alloc(node_allocator()), _compare(comp), _root(0), _size(0){
			init_nil_head();
			_root = _header;
		}

		RBTree() : _root(0), _val_alloc(allocator_type()), _node_alloc(node_allocator()), _compare(value_compare()), _size(0){
			init_nil_head();
			_root = _header;
		}

		RBTree(const RBTree& src) :  _compare(src._compare), _root(NULL) {
			*this = src;
		}
		template<class InputIt>
		RBTree(typename ft::enable_if< !ft::is_integral<InputIt>::value, InputIt >::type first, InputIt last,
		   const value_compare& comp, const allocator_type& alloc = allocator_type()):	_val_alloc(alloc),
		   																				_node_alloc(node_allocator()),
																						_compare(comp) {
			init_nil_head();
			_root = _header;
			for (; first != last; ++first)
				insert(*first);
		}

	
		RBTree& operator=(const RBTree & src){
			if (this == &src)
				return *this;
			this->_node_alloc = src._node_alloc;
			this->_val_alloc = src._val_alloc;
			this->_compare = src._compare;
			if (this->_root == NULL)
				init_nil_head();
			else
				clear_node(_root);
			if (src._size == 0)
				this->_root = this->_header;
			else {
				this->_root = copy_node(src._root);
				copy_child(this->_root, src._root);
			}
			this->_size = src._size;
			return *this;
		}

		~RBTree(){
			clear_node(_root);
			_val_alloc.destroy(_header->value);
			_val_alloc.deallocate(_header->value, 1);
			_node_alloc.deallocate(_nil, 1);
			_node_alloc.deallocate(_header, 1);
		}

		size_type size() const{
			return (_size);
		}

		size_type max_size() const{
			return (_val_alloc.max_size());
		}
		
		bool empty() const{
			return (_size == 0);
		}

		value_compare value_comp() const {
			return (_compare);
		}
		
		void clear() {
			clear_node(_root);
			_root = _header;
			_header->parent = NULL;
			_size = 0;
		}
		
		size_type count(const value_type& value) const{
			return (find(value) != end());
		}

		iterator lower_bound(const value_type& value){
			iterator last = end();
			for (iterator first = begin(); first != last; ++first){
				if(!_compare(*first, value))
					return (first);
			}
			return (last);
		}

		const_iterator lower_bound(const value_type& value) const{
			const_iterator last = end();
			for (const_iterator first = begin(); first != last; ++first){
				if(!_compare(*first, value))
					return (first);
			}
			return (last);
		}

		iterator upper_bound(const value_type& value){
			iterator last = end();
			for (iterator first = begin(); first != last; ++first){
				if(_compare(value, *first))
					return (first);
			}
			return (last);
		}

		const_iterator upper_bound(const value_type& value) const{
			const_iterator last = end();
			for (const_iterator first = begin(); first != last; ++first){
				if(_compare(value, *first))
					return (first);
			}
			return (last);
		}

		void swap(RBTree &other){
			std::swap(this->_root, other._root);
			std::swap(this->_nil, other._nil);
			std::swap(this->_header, other._header);
			std::swap(this->_size, other._size);
			std::swap(this->_node_alloc, other._node_alloc);
			std::swap(this->_val_alloc, other._val_alloc);
			std::swap(this->_compare, other._compare);
		}

		ft::pair<iterator, iterator> equal_range(const value_type &value){
			return (ft::make_pair(lower_bound(value), upper_bound(value)));
		}

		//pair<const_iterator, const_iterator> equal_range(const value_type &value) const{
		//	return (make_pair(lower_bound(value), upper_bound(value)));
		//}
		
		allocator_type get_allocator() const{
			return (_val_alloc);
		}
		

		//template<typename A, typename B>
		//friend bool operator==(const RBTree::template TreeIter<A> & lhs, const RBTree::template TreeIter<B> & rhs){
		//	return (lhs.node() == rhs.node());
		//}

		//template<typename A, typename B>
		//friend bool operator!=(const RBTree::template TreeIter<A> & lhs, const RBTree::template TreeIter<B> & rhs){
		//	return (lhs.node() != rhs.node());
		//}

};

template<class Content, class Compare, class Alloc>
bool operator<(const RBTree<Content, Compare, Alloc>& lhs,  const RBTree<Content, Compare, Alloc>& rhs){
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<class Content, class Compare, class Alloc>
bool operator>(const RBTree<Content, Compare, Alloc>& lhs,  const RBTree<Content, Compare, Alloc>& rhs){
	return (lhs < rhs);
}


template<class Content, class Compare, class Alloc>
bool operator==(const RBTree<Content, Compare, Alloc>& lhs, const RBTree<Content, Compare, Alloc>& rhs){
	return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}

template<class Content, class Compare, class Alloc>
void swap(const  RBTree<Content, Compare, Alloc>& lhs, const  RBTree<Content, Compare, Alloc>& rhs){
	lhs.swap(rhs);
}
