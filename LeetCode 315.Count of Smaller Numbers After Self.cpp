#include <stdio.h>

#include <vector>
struct BSTNode {
	int val;
	int cnt;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int x): val(x), cnt(0), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> countSmaller(std::vector<int>& nums) {
		std::vector<int> ret, reverse; 
		std::vector<BSTNode*> node_vec;
		for(int i = nums.size() - 1; i >= 0; i--) {
			node_vec.push_back(new BSTNode(nums[i]));
		}
		reverse.push_back(0);
		for(int i = 1; i < node_vec.size(); i++) {
			int sum = 0;
			BST_insert(node_vec[0], node_vec[i], sum);
			reverse.push_back(sum);
		}
		for(int i = node_vec.size() - 1; i >= 0; i--) {
			delete node_vec[i];
			ret.push_back(reverse[i]);
		}
		return ret;
    }
private:
	void BST_insert(BSTNode* root, BSTNode* node, int &record) {
		if(node->val <= root->val) {
			root->cnt++;
			if(root->left == NULL) {
				root->left = node;
			}
			else {
				BST_insert(root->left, node, record);
			}
		}
		else {
			record += root->cnt + 1;
			if(root->right == NULL) {
				root->right = node;
			}
			else {
				BST_insert(root->right, node, record);
			}
		}
	}
};

int main(){
	int test[] = {5, -7, 9, 1, 3, 5, -2, 1};
	std::vector<int> nums;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	Solution solve;
	std::vector<int> result = solve.countSmaller(nums);
	for (int i = 0; i < result.size(); i++){
		printf("[%d]", result[i]);
	}
	printf("\n");
	return 0;
}
