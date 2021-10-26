#include "RBTree.hpp"

Node * grandparent(Node *n)
{
	if ((n != 0) && (n->parent != 0))
		return n->parent->parent;
	else
		return 0;
}

Node * uncle(Node *n)
{
	Node *g = grandparent(n);
	if (g == 0)
		return 0;
	if(n->parent == g->left)
		return g->right;
}


void rotate_left{


}

