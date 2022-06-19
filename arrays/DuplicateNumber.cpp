class Solution {
public:
    int findDuplicate(vector<int>& nums) {
// sol 1: sorting, works but it'll modify the array       
// tc: O(nlogn) sc:O(logn)
        // sort(nums.begin(),nums.end());
        //  int i=0;
        //  for( i=0;i<nums.size()-1;i++)
        //  {
        //      if(nums[i]==nums[i+1])
        //          break;
        //  }
        //  return nums[i];

//sol 2: sets, works but uses extra space
//tc:O(n) sc:O(n)
        // unordered_set<int> a;
        // for(auto &i:nums)
        // {
        //     if(a.count(i))return i;
        //     a.insert(i);
        // }
        // return -1;
        
//sol 3: Binary search
//Consider an array that has nn distinct numbers in the range [1,n][1,n]. For example: [1,2,3,4,5][1,2,3,4,5]. If we pick any one of these 5 numbers and count how many numbers are less than or equal to it, the answer will be equal to that number. So in [1,2,3,4,5][1,2,3,4,5], if you pick the number 44, there's exactly 4 numbers that are less than or equal to 44. If you pick 33, there's exactly 3 numbers that are less than or equal to 33, and so on. However, when you have duplicates in the array, this count will exceed the number at some point.  

//tc: O(nlogn) sc:O(1)
//         int low = 1, high = nums.size() - 1, cnt;     
//         while(low <=  high)
//         {
//             int mid = low + (high - low) / 2;
//             cnt = 0;
//             // cnt number less than equal to mid
//             for(int n : nums)
//             {
//                 if(n <= mid)
//                     ++cnt;
//             }
//             // binary search on left
//             if(cnt <= mid)
//                 low = mid + 1;
//             else
//             // binary search on right
//                 high = mid - 1;
//         }
//         return low;
        
// Floyd's Cycle
/*1. Take two pointers (basically integers) namely, slow and fast. Initially both will point to first element
2. Increase slow by 1 and fast by two.
    slow = nums[slow]; fast = nums[nums[fast]].
3. There will be one time when slow and fast will meet. They will meet in a cycle. we have to stop.
4. Now move fast to initial position i.e. fast = nums[0].
5. Now move both slow and fast by one position till both of them meet.increment will be done as follows: slow = nums[slow]; fast = nums[fast].
6.The node at which both slow and fast will meet will be the duplicate number.
7. Return slow or fast */
        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // Find the "entrance" to the cycle.
        tortoise = nums[0];
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
        
    }
};