// https://leetcode.com/problems/longest-increasing-subsequence/

/*dynamic programming: For each element nums[i], if there's an smaller element nums[j] before it, 
the result will be maximum of current LIS length ending at i: dp[i], and LIS ending at that j + 1: dp[j] + 1.
 +1 because we are including the current element and extending the LIS ending at j.
    
tc: O(N^2) sc: O(N) [can be better - binary search]
*/

class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int ans=0,n=nums.size(),dp[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};

// binary search: tc-O(NlogN) sc-O(N)[can be O(1) if same array is modified]

/*Let's construct the idea from following example.
Consider the example nums = [2, 6, 8, 3, 4, 5, 1], let's try to build the increasing subsequences starting with an empty one: sub1 = [].
Let pick the first element, sub1 = [2].
6 is greater than previous number, sub1 = [2, 6]
8 is greater than previous number, sub1 = [2, 6, 8]
3 is less than previous number, we can't extend the subsequence sub1, but we must keep 3 because in the future there may have the longest subsequence start with [2, 3], sub1 = [2, 6, 8], sub2 = [2, 3].
With 4, we can't extend sub1, but we can extend sub2, so sub1 = [2, 6, 8], sub2 = [2, 3, 4].
With 5, we can't extend sub1, but we can extend sub2, so sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5].
With 1, we can't extend neighter sub1 nor sub2, but we need to keep 1, so sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5], sub3 = [1].
Finally, length of longest increase subsequence = len(sub2) = 4.
In the above steps, we need to keep different sub arrays (sub1, sub2..., subk) which causes poor performance.
But we notice that we can just keep one sub array, when new number x is not greater than the last element of the subsequence sub, 
we do binary search to find the smallest element >= x in sub, and replace with number x.
Let's run that example nums = [2, 6, 8, 3, 4, 5, 1] again:
Let pick the first element, sub = [2].
6 is greater than previous number, sub = [2, 6]
8 is greater than previous number, sub = [2, 6, 8]
3 is less than previous number, so we can't extend the subsequence sub. We need to find the smallest number >= 3 in sub, it's 6. Then we overwrite it, now sub = [2, 3, 8].
4 is less than previous number, so we can't extend the subsequence sub. We overwrite 8 by 4, so sub = [2, 3, 4].
5 is greater than previous number, sub = [2, 3, 4, 5].
1 is less than previous number, so we can't extend the subsequence sub. We overwrite 2 by 1, so sub = [1, 3, 4, 5].
Finally, length of longest increase subsequence = len(sub) = 4.
*/


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> LIS;
        for(int i=0;i<nums.size();i++)
        {
            if (LIS.size() == 0 || LIS[LIS.size() - 1] < nums[i]) {
                LIS.push_back(nums[i]);
            }
            else{
                auto it = lower_bound(LIS.begin(), LIS.end(), nums[i]); // Find the index of the smallest number >= x
                *it = nums[i]; // Replace that number with x
            }
        }
        return LIS.size();
    }
};