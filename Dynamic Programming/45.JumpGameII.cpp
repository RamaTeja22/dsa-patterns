class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
        return 0;
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        int i,j;
        for(i=1;i<n;i++){
            for(j=0;j<i;j++){
                if(j+nums[j]>=i)
                dp[i]=min(dp[i],1+dp[j]);
            }
        }
        return dp[n-1];
    }
};