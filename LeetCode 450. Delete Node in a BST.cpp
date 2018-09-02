#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* BST_search(TreeNode *node, int value, TreeNode *&parent){
	TreeNode* ptr = node;
	while(ptr != NULL) {
		if(value == ptr->val) {
			break;
		}
		parent = ptr;
		if(value < ptr->val) {
			ptr = ptr->left;
		}
		else {
			ptr = ptr->right;
		}
	}
	return ptr;
}

void delete_node(TreeNode *parent, TreeNode *child){
	if(parent->left == child) {
		// parent->left
		if(child->left != NULL) {
			parent->left = child->left;
		}
		else if(child->right != NULL) {
			parent->left = child->right;
		}
		else {
			parent->left = NULL;
		}
	}
	else {
		// parent->right
		if(child->left != NULL) {
			parent->right = child->left;
		}
		else if(child->right != NULL) {
			parent->right = child->right;
		}
		else {
			parent->right = NULL;
		}
	}
}

TreeNode* find_successor(TreeNode *node, TreeNode *&parent){
	parent = node;
	TreeNode* ptr = node->right;
	while(ptr->left != NULL) {
		parent = ptr;
		ptr = ptr->left;
	}
	return ptr;
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
<<<<<<< HEAD
		TreeNode* parent = NULL;
		TreeNode* node = NULL;
=======
		TreeNode* parent;
		TreeNode* node;
>>>>>>> add leetcode 450
		if(NULL == (node = BST_search(root, key, parent))) {
			return root;
		}
		if(node->left != NULL && node->right != NULL) {
			TreeNode* suc = find_successor(node, parent);
			delete_node(parent, suc);
			node->val = suc->val;
		}
		else if(parent != NULL) {
				delete_node(parent, node);
		}
		else
		{
			// delete root node
			if (node->left != NULL) {
				root = node->left;
			}
			else {
				root = node->right;
			}
		}
		return root;
    }
};

void preorder_print(TreeNode *node,int layer){
	if (!node){
		return;
	}
	for (int i = 0; i < layer; i++){
		printf("-----");
	}
	printf("[%d]\n", node->val);
	preorder_print(node->left, layer + 1);
	preorder_print(node->right, layer + 1);
}

int main(){
	for (int i = 1; i <= 7; i++){
		printf("key = %d\n", i);
		TreeNode a(5);
		TreeNode b(3);
		TreeNode c(6);
		TreeNode d(2);
		TreeNode e(4);
		TreeNode f(7);
		a.left = &b;
		a.right = &c;
		b.left = &d;
		b.right = &e;
		c.right = &f;
		Solution solve;
		TreeNode *root = solve.deleteNode(&a, i);
		preorder_print(root, 0);
		printf("\n");
	}
	return 0;
}

