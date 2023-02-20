https://leetcode.com/problems/4sum/

/*Intuition: In the previous approach we fixed three-pointers and did a binary search 
to find the fourth. Over here we will fix two-pointers and then find the remaining two 
elements using two pointer technique as the array will be sorted at first.

Approach: Sort the array, and then fix two pointers, so the remaining 
sum will be (target – (nums[i] + nums[j])). Now we can fix two-pointers, 
one front, and another back, and easily use a two-pointer to find the 
remaining two numbers of the quad. In order to avoid duplications, we jump 
the duplicates, because taking duplicates will result in repeating quads. 
We can easily jump duplicates, by skipping the same elements by running a loop.*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& num, int target) {
          vector<vector<int> > res;
    
        if (num.empty())
            return res;
    
        std::sort(num.begin(),num.end());
    
        for (int i = 0; i < num.size(); i++) {
        
            long long target_3 = target - num[i];
        
            for (int j = i + 1; j < num.size(); j++) {
            
                long long target_2 = target_3 - num[j];
            
                int front = j + 1;
                int back = num.size() - 1;
            
                while(front < back) {
                
                    long long two_sum = num[front] + num[back];
                
                    if (two_sum < target_2) front++;
                
                    else if (two_sum > target_2) back--;
                
                    else {
                    
                        vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);
                    
                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;
                    
                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                
                    }
                    if((long)num[front]+(long)num[i]+(long)num[j]+(long)num[back]>INT_MAX)
                    return res;
                }
                
                // Processing the duplicates of number 2
                while(j + 1 < num.size() && num[j + 1] == num[j]) ++j;
            }
        
            // Processing the duplicates of number 1
            while (i + 1 < num.size() && num[i + 1] == num[i]) ++i;
            
        }
    
        return res;
    }
};