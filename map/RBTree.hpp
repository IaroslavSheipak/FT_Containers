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
			                rebind<Node<Value> >::other            node_allocator_type;
		//typedef Node_Alloc node_allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef std:size_t size_type;
		//typedef iterator;
		//typedef const_iterator;
		//typedef	reverse_iterator;
	   	//typedef const_reverse_iterator;
		//typedef difference_type;	
	private:
		typedef Node<value_type> Node;
		typedef Node* link_type;
		Node	*_nil;
		Node	*_header;
		Node 	*root;
		
		//HELPER FUNCTIONS
		void 	_rotate_right(Node *node){
			link_type y;

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
		void 	_rotate_left(Node *node){
			link_type y;

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


}


