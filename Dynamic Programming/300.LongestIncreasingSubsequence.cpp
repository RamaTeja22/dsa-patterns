class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,1);
        int i,j;
        int overallMax=1;
        for(i=1;i<n;i++){
            for(j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            overallMax=max(overallMax,dp[i]);
        }
        return overallMax;
    }
};