// https://leetcode.com/problems/longest-palindromic-subsequence/

// sol : string ko reverse kareke unn dono ke bich ka LCS nikal lo wahi longest pallindromic subsequence hoga

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t="";
        int n= s.length();
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(i==0||j==0)dp[i][j]=0;
        for(int i=n-1;i>=0;i--)
        {
            t+=s[i];
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]= 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
    }
};