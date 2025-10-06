class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int n=nums.size();
       // this defines end spots of all nonZero, which is literally o...k, where k is #nonZero elements
       int endNonZero=0;
       int i;
       for(i=0;i<n;i++){
        // we only need to bring nonZeros forward to where they should move to
        if(nums[i]!=0){
            swap(nums[i],nums[endNonZero++]);
        }
       }
    }
};