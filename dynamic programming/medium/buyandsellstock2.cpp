// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=prices[0],s=prices[0],m=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]>b)
                m+=(prices[i]-b);
            b=prices[i];
        }
        return  m;
    }
};