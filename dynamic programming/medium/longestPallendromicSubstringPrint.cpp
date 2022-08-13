/* https://leetcode.com/problems/longest-palindromic-substring/

for abccba to be pallindromic, bccb should be p.d. and cc should be p.d.
so if s[i]==s[j] i=0,j=n-1 and dp[i+1][j-1]=1 therefore whole string will be p.d. and we do it recursively and store in dp array */

class Solution {
public:
    
    string longestPalindrome(string s) {
       int len = s.size();
    int dp[len][len];
    memset(dp,0,sizeof(dp));
    int end=1;
    int start=0;
	
    for(int i=0;i<len;i++)
    {
        dp[i][i] = 1;// string of 1 char will always be pallindrome
    }
    for(int i=0;i<len-1;i++)
    {
        if(s[i]==s[i+1])// 2 char ke liye bhi dekhna padega
        { dp[i][i+1]=1;start=i;end=2;}//start end to print the string
    }
    
    for(int j=2;j<len;j++)
    {
        for(int i=0;i< len-j;i++)
        {  
            int left=i; //start point
            int right = i+j;  //ending point
            
            if(dp[left+1][right-1]==1 && s[left]==s[right]) 
            {
                dp[left][right]=1; start=i; end=j+1; 
            }        
        }
    }
   return s.substr(start, end);
}
    
};