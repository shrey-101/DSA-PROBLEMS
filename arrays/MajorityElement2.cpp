//https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
/*moore's voting algorithim
n/3+x times wale find krne hai to wo at max 2 hi no. ho skte; eg: 10/3=3 to
2 hi no. honge jo 4 ya usse zada baar aaenge 10 ke array mai at max,
isleye 2 maximum baar aane wale find krlo aur fir check karlo wo n/3 wali 
condition satisfiy karenge ya nhi */
    vector<int> majorityElement(vector<int>& nums) {
        int n =nums.size(),a=nums[0],b=nums[0],c1=0,c2=0,i=0;
        vector<int> sol;
        while(i<n)
        {
            if(nums[i]==a)c1++;
            else if(nums[i]==b)c2++;
            else if(c1==0){a=nums[i]; c1=1;}
            else if(c2==0) {b=nums[i]; c2=1;}
            else{c1--;c2--;}
            i++;
        }
        c1=0;c2=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==a)c1++;
            else if(nums[i]==b)c2++;
        }
        if(c1>n/3)sol.push_back(a);
        if(c2>n/3)sol.push_back(b);
        return sol;
    // Hash table
        // unordered_map<int,int> m;
        // int k=nums.size()/3;
        // vector<int> sol;
        // for(auto &x:nums)
        // {
        //     ++m[x];
        // }
        // for(auto &x:m)
        // {
        //     if(x.second>k)sol.push_back(x.first);
        // }
        // return sol;
    }
};
