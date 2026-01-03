class Solution {
public:
    // Top Down Approach
    int dfs(int n, int curr, int carry,vector<vector<int>>&memo) {
        if (curr > n)
            return 1000; 
        if (curr == n)
            return 0;
        if(memo[curr][carry]!=-1){
            return memo[curr][carry];
        }
        int opt1=2+dfs(n,2*curr,curr,memo);
        int opt2=1+dfs(n,curr+carry,carry,memo);
        memo[curr][carry]=min(opt1,opt2);
        return memo[curr][carry];
    }

    int minSteps(int n) {
        if (n == 1)
            return 0;
        vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
        return 1+dfs(n, 1, 1,memo);
    }

    // Bottom Up Apprach
     int minSteps(int n) {
        if (n == 1)
            return 0;
        vector<int>dp(n+1,1000);
        dp[0]=0;
        dp[1]=0;
        int i,j;
        for(i=2;i<=n;i++){
            for(j=1;j<=i/2;j++){
                if(i%j==0){
                    dp[i]=min(dp[i],dp[j]+i/j);
                }
            }
        }
        return dp[n];
    }
};