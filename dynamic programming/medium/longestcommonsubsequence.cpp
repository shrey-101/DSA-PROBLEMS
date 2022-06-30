//https://leetcode.com/problems/longest-common-subsequence/

class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n=t1.size(),m=t2.size();
        int t[n+1][m+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(i==0||j==0)t[i][j]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(t1[i-1]==t2[j-1])
                {
                    t[i][j]= 1 + t[i-1][j-1];
                }
                else
                {
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        return t[n][m];
    }
};