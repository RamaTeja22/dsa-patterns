class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        int i;
        for(i=0;i<n-2;i++){
            int target = -1*nums[i];
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int left = i+1;
            int right = n-1;
            while(left<right){
                 if(nums[left]+nums[right]==target){
                res.push_back({nums[i],nums[left],nums[right]});
                while(left<right && nums[left]==nums[left+1]){
                    left++;
                }
                while(left<right && nums[right]==nums[right-1]){
                    right--;
                }
                // we exited when left stopped being equal to left+1, but we haven't updated left to left+1.
                left++;
                right--;
            }
            else if(nums[left]+nums[right]<target){
                left++;
            }
            else{
                right--;
            }
            }
        }
        return res;
    }
};