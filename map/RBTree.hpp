#pragma once
#include <memory>

template<class Value>
struct Node{
	typedef Node*			pointer;

	explicit Node(Value *srcval = 0) :	value(srcval),
										parent(0),
										left(0),
										right(0),
										is_black(false),
										is_nil(0){}
	
	Value	*value;
	Node*	parent;
	Node*	left;
	Node*	right;	
	bool	is_black;
	bool	is_nil;
	
	Node(pointer value, Node* node = NULL, Node* parent = NULL) :
	   value(value), left(node), right(node), parent(parent), is_black(false) {}	
};

template<class Value, class Compare = std::less<Value>, class Alloc = std::allocator<Value> >
class RBTree{
	public:
		typedef Value value_type;
		typedef Compare key_compare;
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
		//typedef iterator;
		//typedef const_iterator;
		//typedef	reverse_iterator;
	   	//typedef const_reverse_iterator;
		//typedef difference_type;	
	private:
		allocator_type				_val_alloc;
		node_allocator				_node_alloc;
		key_compare 				_compare;
		node_pointer				_nil;
		node_pointer				_header;
		node_pointer				_root;
		size_type					_size;
		
		//HELPER FUNCTIONS
		void 	_rotate_right(node_pointer	node){
			node_pointer y;

			y = left(node);
			if (right(y) != _nil)
				parent(y->right) = node;
			if (node == _root)
				_root = y;
			else if (node == right(node->parent))
				right(node->parent) = y;
			else
				left(node->parent) = y;
		}
		void 	_rotate_left(node_pointer	node){
			node_pointer y;

			y = right(node);
			if (left(y) != _nil)
				parent(y->left) = node;
			if (node == _root)
				_root = y;
			else if (node == left(node->parent))
				left(node->parent) = y;
			else
				right(node->parent) = y;
		}
		node_pointer	_insert(node_pointer new_node){
			if (!_root)
				return(_root = new_node);
			if (_compare(*new_node->content, *_root->content)){
				if (!is_nil(_root->left))
					return (_insert(_root->left, new_node));
				_root->left = new_node;
			}
			else{
				if (!is_nil(_root->right))
					return (_insert(_root->right, new_node));
				_root->right = new_node;
			}
			new_node->father = _root;
			return (new_node);
		}

		void _insert_fixup(node_pointer node){
			if (node != _root && node->father != _root){
				while (!node->father->is_black){
					if (node->father == node->father->father->left){
						node_pointer uncle = node->father->father->right;
						if (!uncle->is_black){
							node->father->is_black = true;
							uncle->is_black = true;
							node->father->father->is_black = false;
							node = node->father->father;
						}
						else {
							if (node == node->father->left){
								node = node->father;
								_rotate_right(node);
							}
							node->father->is_black = true;
							node->father->father->is_black = false;
							_rotate_left(node->father->father);
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
			}
				_val_alloc.destroy(node->value);
				_val_alloc.deallocate(node->value, 1);
				_node_alloc.deallocate(node, 1);
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


		//PUBLIC FUNCTIONS
	public:
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
		
		void /*pohui*/ insert(value_type *value){
			node_pointer find_val = search(*value, _root);
		} 
		//CONSTRUCTORS
		RBTree(const Compare &comp, const allocator_type& a = allocator_type()):
				_root(0), _val_alloc(a), _node_alloc(node_allocator()), _compare(comp), _size(0){
			init_nil_head();
			_root = _header;
		}

		RBTree() : _root(0), _val_alloc(allocator_type()), _node_alloc(node_allocator()), _compare(key_compare()), _size(0){
			init_nil_head();
			_root = _header;
		}

		RBTree(const RBTree& src){
			*this = src;
		}
		
		RBTree& operator=(const RBTree & src){
			this->_node_alloc = src._node_alloc;
			this->_val_alloc = src._val_alloc;
			this->_cmp = src._cmp;
			clear_node(_root);
			if (this->_nil == NULL)
			init_nil_head();
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

};


