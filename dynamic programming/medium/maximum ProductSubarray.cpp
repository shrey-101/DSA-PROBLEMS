https://leetcode.com/problems/maximum-product-subarray/submissions/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=1,mn=1,ans=0,n=nums.size();
        if(n==1)return nums[0];
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)swap(mx,mn);
            mx=max(mx*nums[i],nums[i]);
            mn=min(mn*nums[i],nums[i]);
            ans=max(ans,mx);
        }
        return ans;
    }
};

/* Kadens modified
Consider the array 1, -2, -3, 4. 
When we are at the second element, our runningProduct becomes -2.
But at the third element it becomes 6. So, as we encounter negative numbers they change the sign of our product.
Our product can become really small but then really big depending on the sign of the current number. 
To accomodate for this, we can have two running products: maxProd and minProd. 
maxProd will track the maximum product that we can achieve and will reset whenever the current number is greater, just as above. 
minProd, on the other hand, will track the minimum product that we can achieve and will reset whenever the current number is smaller. 
Finally, whenever we encounter a negative number, we will swap maxProd and minProd because if a <= b then -b <= -a. 
This makes sure that maxProd and minProd are still the max and min products after multiplied by a negative number. 
*/