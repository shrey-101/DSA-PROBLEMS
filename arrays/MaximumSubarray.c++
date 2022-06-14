// https://leetcode.com/problems/maximum-subarray/

/* Initialise: currMaxSum and globalMaxSum as nums[0] since, for i = 0, we only have 1 choice i.e to include it into the maxSum SubArray.

For any index i [ 1 <= i <= n [:= nums.size()] - 1 ], we have two choices for maxSum SubArray:

It expands itself by including nums[i] (or ith index).
It discards itself and starts fresh from nums[i] (or ith index).
At each step, we choose max of above two choices for ith index and update our currMaxSum.
At each step, we update globalMaxSum to store the global maxSum SubArray.*/

// Method1: Recursive [T(n) = O(n) and S(n) = O(n) [recursion stack space]]
class Solution {
public:
	int globalMaxSum;
	int maxSubArray(vector<int> &nums, int n) {
		if (n == 1) return nums[0];
		int currMaxSum = max(nums[n - 1], maxSubArray(nums, n - 1) + nums[n - 1]);
		globalMaxSum = max(globalMaxSum, currMaxSum);
		return currMaxSum;
	}
    int maxSubArray(vector<int> &nums) {
        globalMaxSum = nums[0];
		maxSubArray(nums, nums.size());
        return globalMaxSum;
    }
};

// Method2: Iterative [T(n) = O(n) and S(n) = O(1)]
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int globalMaxSum = nums[0], currMaxSum = nums[0];
        for (int ind = 1; ind < nums.size(); ind++) {
            currMaxSum = max(currMaxSum + nums[ind], nums[ind]);
            globalMaxSum = max(globalMaxSum, currMaxSum);
        }
        return globalMaxSum;
    }
};