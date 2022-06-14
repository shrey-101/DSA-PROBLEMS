// https://leetcode.com/problems/next-permutation/solution/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k,l,g,h=101;
        for(int i=nums.size()-1;i>0;i--) // to find thefirst smaller element from the back
        {
            if(nums[i]>nums[i-1]){
                k =nums[i-1];h=i-1;
            break;}
        }
        if(h!=101) // if no smaller element present i.e. array is in ascending order
        {
        for(int i=0;i<nums.size();i++) // to find the element just greater than the element
        {
            l=101;
            if(nums[i]>k&&nums[i]<l){
                l=nums[i];
                g=i;
            }
        }
        swap(nums[h],nums[g]);// swaping them 
        sort(nums.begin()+(h+1),nums.end()); // sorting the array from the smallest element to the end
        }
        else
        reverse(nums.begin(),nums.end()); //reverse the complete array as it is the last permutation and will change it to first
        }
};