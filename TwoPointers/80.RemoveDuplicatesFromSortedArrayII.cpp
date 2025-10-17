// i is the write ptr, n is the read ptr
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int i=0;
       for(int n:nums){
        // when we overwrite
        if(i<2 || n>nums[i-2]){
            nums[i++]=n;
        }
       }
       return i;
    }
};