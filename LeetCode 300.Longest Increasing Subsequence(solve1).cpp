#include <stdio.h>
#include <vector>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		std::vector<int> dp(nums.size(), 1);
		int ret = 1;
		for(size_t i = 0; i < dp.size(); i++) {
			for(size_t j = 0; j < i; j++) {
				if (nums[j] < nums[i] && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
			if (ret < dp[i]) {
				ret = dp[i];
			}
		}
		return ret;
	}
};

int main(){
	int test[] = {10, 9, 2, 5, 3, 7, 101, 18};
	std::vector<int> nums;
	for (int i = 0; i < 8; i++){
		nums.push_back(test[i]);
	}
	Solution solve;
	printf("%d\n", solve.lengthOfLIS(nums));
	return 0;
}
