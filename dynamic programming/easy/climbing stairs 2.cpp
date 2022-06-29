// https://leetcode.com/problems/min-cost-climbing-stairs/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int s=0,n=cost.size();
        int a=cost[0];
        int b=cost[1];
        if(n<=2)return min(a,b);
        for(int i=2;i<n;i++)
        {
            s=cost[i]+min(a,b);
            a=b;
            b=s;
        }
        return min(a,b);
    }
};