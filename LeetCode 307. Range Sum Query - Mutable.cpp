#include <stdio.h>

#include <vector>

void build_sum_tree(
	std::vector<int> &nums,
	std::vector<int> &tree,
	int pos, int left, int right)
{
	if (left == right)
	{
		tree[pos] = nums[left];
		return;
	}
	int mid = (left + right) / 2;
	build_sum_tree(nums, tree, 2 * pos + 1, left, mid);
	build_sum_tree(nums, tree, 2 * pos + 2, mid + 1, right);
	tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
}

void update_sum_tree(
	std::vector<int> &tree,
	int pos, int left, int right,
	int index, int value)
{
	if(left == right && left == index)
	{
		tree[pos] = value;
		return;
	}
	int mid = (left + right) / 2;
	if(index > mid)
	{
		update_sum_tree(tree, 2*pos+2, mid+1, right, index, value);
	}
	else
	{
		update_sum_tree(tree, 2*pos+1, left, mid, index, value);
	}
	tree[pos] = tree[2 * pos + 1] + tree[2 * pos + 2];
}

int calc_sum_tree(
	std::vector<int> &tree,
	int pos, int left, int right,
	int calc_left, int calc_right
)
{
	if (calc_left > right || calc_right < left)
	{
		return 0;
	}
	if (calc_left <= left && calc_right >= right)
	{
		return tree[pos];
	}
	int mid = (left + right) / 2;
	return calc_sum_tree(tree, 2 * pos + 1, left, mid, calc_left, calc_right) + calc_sum_tree(tree, 2 * pos + 2, mid + 1, right, calc_left, calc_right);
}

class NumArray {
public:
    NumArray(std::vector<int> nums) {
		if(nums.size() == 0)
		{
			return;
		}
		// initial _tree
		int n = nums.size() * 4;
		for(int i = 0; i < n; i++)
		{
			_tree.push_back(0);
		}
		_size_id = nums.size() - 1;
		build_sum_tree(nums, _tree, 0, 0, _size_id);
    }    
    void update(int i, int val) {
		update_sum_tree(_tree, 0, 0, _size_id, i, val);
    }    
    int sumRange(int i, int j) {
		return calc_sum_tree(_tree, 0, 0, _size_id, i, j);
    }
private:
	std::vector<int> _tree;
	int _size_id;
};

int main(){
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(5);
	NumArray num_array(nums);
	printf("%d\n", num_array.sumRange(0, 2));
	num_array.update(1, 2);
	printf("%d\n", num_array.sumRange(0, 2));	
	return 0;
}
