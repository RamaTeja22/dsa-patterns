class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=nums[0];
        int currentSum=0;
        int i;
        for(i=0;i<n;i++){
            currentSum=max(nums[i],currentSum+nums[i]);
            if(currentSum>maxSum){
                maxSum=currentSum;
            }
            else if(currentSum<=0){
                currentSum=0;
            }
        }
        return maxSum;   
    }
};