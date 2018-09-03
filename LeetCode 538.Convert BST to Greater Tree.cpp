#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode *root) {
		int sum = 0;
		travelTree(root, sum);
		return root;
    }
private:
	void travelTree(TreeNode *node, int &sum) {
		if(node == NULL) {
			return;
		}
		travelTree(node->right, sum);
		sum += node->val;
		node->val = sum;
		travelTree(node->left, sum);
	}
};

void preorder_print(TreeNode *node, int layer){
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
	TreeNode *root = solve.convertBST(&a);
	preorder_print(&a, 0);
	return 0;
}

