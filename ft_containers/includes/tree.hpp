#ifndef TREE_HPP
# define TREE_HPP

# define NULL 0

#include "iterator.hpp"

namespace ft
{
typedef bool RB_tree_color_type;
const RB_tree_color_type rb_tree_red = false; // RED
const RB_tree_color_type rb_tree_black = true; // BLACK

template <typename T>
struct Node {
	// Type definitions
	typedef RB_tree_color_type Color_type;
	typedef T value_type;
	typedef Node<value_type>* Link_type;

	// Member variables
	Color_type color;
	Link_type parent;
	Link_type left;
	Link_type right;
	value_type data;

	// Member functions
	bool is_left_child() const { return (parent != NULL) && (parent->left == this); }
	bool is_right_child() const { return (parent != NULL) && (parent->right == this); }

	/**
	 * @brief minimum
	 * x의 서브 트리중 key값이 가장 작은 노드를 찾아서 그 주소를 반환한다.
	 * 왼쪽 서브 트리가 없다면 NULL을 반환한다.
	 * @param x 
	 * @return Link_type
	 */
	static Link_type mininum(Link_type x) {
		while (x->left != NULL)
			x = x->left;
		return x;
	}

	/**
	 * @brief maximum
	 * x의 서브 트리중 key값이 가장 큰 노드를 찾아서 그 주소를 반환한다.
	 * 오른쪽 서브 트리가 없다면 NULL을 반환한다.
	 * @param x 
	 * @return Link_type 
	 */
	static Link_type maximum(Link_type x) {
		while (x->right != NULL)
			x = x->right;
		return x;
	}

	/**
	 * @brief successor
	 * 현재 트리에서 본인 다음으로 큰 key값을 가진 노드를 찾아서 반환한다.
	 * 1) 오른쪽 서브 트리가 존재한다면 오른쪽 서브트리의 최솟값을 반환
	 * 2) 부모 노드의 왼쪽 자식인 경우 (부모보다 작은 값을 가지는 경우) 부모 노드를 반환한다.
	 * 3) 오른쪽 서브 트리가 존재하지 않고 부모 노드의 오른쪽 자식인 경우,
	 * 부모 노드가 right_child가 아닐때까지 계속 부모 노드로 이동하고, 왼쪽 자식인 노드를 만나면
	 * 2)의 경우로 넘어간다. 본인보다 큰 노드가 없다면 NULL을 반환한다. (ex) 트리의 가장 오른쪽 Node
	 * @return Link_type
	 */
	Link_type successor() {
		if (right != NULL)
			return right->mininum();
		if (is_left_child())
			return parent;
		Link_type succ = this;
		while (succ != NULL && succ->is_right_child()) {
			succ = succ->parent;
		}
		return succ->parent;
	}

	/**
	 * @brief sibling
	 * 현재 Node의 Sibling Node를 반환한다.
	 * Left Child => Parent -> Right Child
	 * Right Child => Parent -> Left Child
	 * @return Link_type 
	 */
	Link_type sibling() {
		if (parent == NULL)
			return NULL;
		return is_left_child() ? parent->right : parent->left;
	}

	/**
	 * @brief  Predecessor
	 * 현재 Node 다음으로 작은 Node를 반환한다.
	 * 1) Left Sub Tree가 존재하는 경우 Left Sub Tree에서 가장 큰 Node를 반환한다.
	 * 2) Right Child인 경우(Parent Node보다 큰 값) Parent Node를 반환한다.
	 * 3) Left Sub Tree가 없고, Left Child인 경우 (Parent Node보다 작은 값을 가지고 있음)
	 * Parent Node가 Left Child가 아닐때까지 Parent Node로 이동하고, 그 부모 노드를 반환한다.
	 * Tree의 가장 작은 Node의 경우 NULL을 반환한다.
	 * @return Link_type 
	 */
	Link_type predecessor() {
		if (left != NULL) // Case 1)
			return left->maximum();
		if (is_right_child()) // Case 2)
			return parent;
		Link_type pred = this; // Case 3)
		while (pred != NULL && is_left_child()) {
			pred = pred->parent;
		}
		return pred->parent;
	}
};
} // namespace ft
#endif
