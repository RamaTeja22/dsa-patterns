class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        // no need to start from 0, as 0th element is unique by then
        int left=1,right;
        for(right=1;right<n;right++){
            // check for unique number or not
            if(nums[right]!=nums[right-1]){
                nums[left]=nums[right];
                left++;
            }
            // not unique => right++ in for loop
        }
        return left;
    }
};