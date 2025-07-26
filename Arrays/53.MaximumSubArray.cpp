class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int n=nums.size();
      int currSum=0,i;
      int maxSum=INT_MIN;
      for(i=0;i<n;i++){
        currSum+=nums[i];
        maxSum=max(maxSum,currSum);
        if(currSum<0)
        currSum=0;
      }
      return maxSum;
    }
};