// https://leetcode.com/problems/fibonacci-number/submissions/

//  Dynamic Programming Approach
// Use memoization to store perviously computed fibonacci values.
// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    int dp[31]={0};
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        dp[0]=0;dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// Imperative Approach (Bottom Up DP)
// With Imperative approach, we step through the loop and optimize the space by storing only two previous fibonacci values in two variables.
// Time Complexity - O(N)
// Space Complexity - O(1)

    int fib(int N) {
        if(N < 2) 
            return N;
    	int a = 0, b = 1, c = 0;
        for(int i = 1; i < N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }