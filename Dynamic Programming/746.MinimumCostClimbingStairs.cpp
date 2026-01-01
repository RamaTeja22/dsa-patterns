class Solution {
public:
// Bottom up approach
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=0;
        int i;
        for(i=2;i<=n;i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }

    // Top Down Approach

    int solve(int i,vector<int>& memo, vector<int>& cost){
        if(i==0 || i==1)
        return 0;
        if(memo[i]!=-1)
        return memo[i];
        memo[i]=min(solve(i-1,memo,cost)+cost[i-1], solve(i-2,memo,cost)+cost[i-2]);
        return memo[i];
    }

     int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>memo(n+1,-1);
        return solve(n,memo,cost);
    }    
};