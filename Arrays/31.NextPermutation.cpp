/*
    1. find prefix match, iterate from right to see where lefter element less than its neighbour, to know at what position, we should swap
    2. swap with whom? iterate from right to find the smmallest number greater than the one to be swapped
    3. reverse the rest of the array
    [2,1,5,4,3,0,0]
    Step 1:- identify 1 as the element to build on next permutation
    Step 2:- Identify 3 as the Swap partner for 1 => [2,3, 5,4,1,0,0]
    Step 3:- Reverse to have in sorted order => [2,3,0,0,1,4,5]
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i,index=-1;
        for(i=n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                index=i;
                break;
            }
        }

        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(i=n-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }

        reverse(nums.begin()+index+1,nums.end());
        return;
    }
};