// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b=prices[0],s=prices[0],m=0;
        for(int i=1;i<prices.size();i++){      
        if(prices[i]<b)
            b= prices[i];
            s = prices[i];
            m = max(m,s-b);
    }
        return m;
    }
};