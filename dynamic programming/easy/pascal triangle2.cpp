// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int n) {
        if(n==0)return {1};
        vector<vector<int>> v;
        
        for(int i=0;i<=n;i++)
        {
            vector<int>k;
            for(int j=0;j<=i;j++)
            {
                if(j==0||j==i)
                    k.push_back(1);
                else
                    k.push_back(v[i-1][j-1]+v[i-1][j]);
            }
            v.push_back(k);
        }
        return v[n];
    }
};