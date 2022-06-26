// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        vector<int> t(n+1,0);
        t[0]=1;
        t[1]=2;
        int i=2;
        while(i<n)
        {
            t[i]=t[i-1]+t[i-2];
            i++;
        }
        return t[n-1];
    }
};

// at n=1,n=2 no. of soltions are fixed so they are the base conditions;
/* The key intuition to solve the problem is that given a number of stairs n,
 if we know the number ways to get to the points [n-1] and [n-2] respectively, denoted as n1 and n2 
 then the total ways to get to the point [n] is n1 + n2. Because from the [n-1] point, 
 we can take one single step to reach [n]. And from the [n-2] point, we could take two steps to get there. */
