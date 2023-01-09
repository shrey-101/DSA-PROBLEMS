// https://leetcode.com/problems/gas-station/description/

/* kishi bhi index se shuru kare aur cost>gas to wo aage nhi badh skta to next index se shuru karo,
koi index mil gaya jaha se shuru kar skte fir lekin agar circle complete nhi ho paya to iska matlb
uss point pe jaha circle ruka aur jaha se shuru kiya tha, inn dono ke bich ke kishi bhi point se circle 
complete nhi hoga isleye tank ko reset karke waha se shuru karo wapas.
aur ek aur baat ki agar total gas>total cost hai tbhi koi solution milega*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size(),total=0,tank=0,index=0;
        for(int i=0;i<n;i++)
        {
            tank=gas[i]-cost[i]+tank;
            if(tank<0)
            {
                index=i+1;
                total+=tank; // total = gas[0]-cost[0]+gas[1]-cost[1]+......
                tank=0;
            }
        }              
        return (total+tank)<0?-1:index; // total + tank = last index ke liye, to agar total ki value +ve aayi matlb gas>cost
    }
};