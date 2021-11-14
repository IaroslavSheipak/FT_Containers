template<class Value>
struct Node{
	typedef Value				value_type;
	typedef value_type*			pointer;
	typedef const value_type*	const_pointer;
	typedef value_type&			reference;
	typedef const_value_type&	const_reference;

	pointer	data;
	Node*	parent;
	Node*	left;
	Node*	right;	
	bool	red;
	
	Node(pointer value, Node* node = NULL, Node* parent = NULL) :
	   value(value), left(node), right(node), parent(parent), color(true) {}	
};

template<class Value, class Compare = std::less<value>, class Alloc = std::allocator<Value> >
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
		typedef ptrdiff_t	difference_type;
		typedef std:size_t	size_type;
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
		void 	_rotate_right(link	node){
			node_pointer y;

			y = left(node);
			if (right(y) != _nil)
				parent(y->right) = node;
			if (node == _root)
				_root = tmp;
			else if (node == right(node->parent))
				right(node->parent) = tmp;
			else
				left(node->parent) = tmp;
		}
		void 	_rotate_left(link	node){
			node_pointer y;

			y = right(node);
			if (left(y) != _nil)
				parent(y->left) = node;
			if (node == _root)
				_root = tmp;
			else if (node == left(node->parent))
				left(node->parent) = tmp;
			else
				right(node->parent) = tmp;
		}
		node_pointer	_insert(link	z){
			if (!_root)
				return(_root = new_node);
			if (_compare(*new_node->content, *root->content)){
				if (!is_nil(root->left))
					return (_insert(root->left, new_node);
				root->left = new_node;
			}
			else{
				if (!is_nil(root->right))
					return (_insert(root->right, new_node);
				root->right = new_node;
			}
			new_node->father = root;
			return (new_node);
		}

		void _insert_fixup(node_pointer node){
			if (node != _root && cur_node->father != _root){
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
		//PUBLIC FUNCTIONS
	public:
		node_pointer	search(const value_type &val) const
		{
			node_pointer x;
			x = _root;
			while (x != _nil){
				if (!_compare(value(x), val) && !_compare(val, value(x)))
					break;
				else if (_compare(val, value(x))
					x = left(x);
				else
					x = right(x);
			}
			return (x);
		}
		//CONSTRUCTORS
		RBTree(const Compare& compare, const allocator_type& a = allocator_type()):
			_root(0), _val_alloc(a), _node_alloc(node_allocator()), _compare(compare), _size(0){
			_nil = _node_alloc.allocate(1);
			_node_alloc.construct(_nil, node<Content>());
			_nil->is_black = true;
			_nil->is_nil = true;
			_header = _node_alloc.allocate(1);
			_node_alloc.construct(_header, node<Value>());
			_header->content = _con_alloc.allocate(1);
			_val_alloc.construct(_header->content, Value());
			}	



}


