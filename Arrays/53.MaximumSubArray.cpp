// O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        // As you have seen only first element till now, helpful for cases where array is filled with only negative integers.
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